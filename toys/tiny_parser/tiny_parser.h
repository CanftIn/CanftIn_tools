///tiny parser
#include <cassert>
#include <cstdlib>
#include <map>
#include <list>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//替换\t\r\n
std::string trim(const std::string& s)
{
	char p[] = " \t\r\n";
	long sp = 0;
	long ep = s.length() - 1;
	for (; sp <= ep; ++sp)
		if (!strchr(p, s[sp])) break;
	for (; ep >= 0; --ep)
		if (!strchr(p, s[ep])) break;
	return s.substr(sp, ep - sp + 1);
}

//找注释哦
inline std::string value(const std::string& s)
{
	std::string c = "#;";
	std::string v = s;
	size_t ep = std::string::npos;
	for (size_t i = 0; i < c.size(); i++)
	{
		ep = s.find(c[i]);
		if (ep != std::string::npos)
			break;
	}
	if (ep != std::string::npos)
		v = s.substr(0, ep);
	return v;
}

////////////////////////////////////////////////////////////////

struct Util
{
	Util() : parent(NULL), depth(0) {}
	Util(Util* p) : parent(p), depth(0) {}

	typedef std::map<std::string, std::string>			value_map_t;
	typedef std::map<std::string, Util>					section_map_t;
	typedef std::list<value_map_t::const_iterator>		values_t;
	typedef std::list<section_map_t::const_iterator>	sections_t;

	value_map_t				values;
	section_map_t			sections;
	values_t				ordered_values; 
	sections_t				ordered_sections;
	Util*					parent;
	size_t					depth;

	const std::string& operator[](const std::string& name) { return values[name]; }
	Util& operator()(const std::string& name) { return sections[name]; }
};

class Parser
{
public:
	Parser(const char* fn);
	Parser(std::istream& f) : f_(&f), ln_(0) { parse(top_); }
	Util& top() { return top_; }
	void dump(std::ostream& s) { dump(s, top(), ""); }

private:
	void dump(std::ostream& s, const Util& util, const std::string& sname);
	void parse(Util& util);
	void parseSLine(std::string& sname, size_t& depth);

private:
	Util			top_;
	std::ifstream	f0_;
	std::istream*	f_;
	std::string		line_;
	size_t			ln_;
};

//////////////////////////////////////////////////////////////////////////////

inline Parser::Parser(const char* fn) : f0_(fn), f_(&f0_), ln_(0)
{
	if (!f0_)
		throw std::runtime_error(std::string("failed to open file: ") + fn);

	parse(top_);
}
//解决[[d]]的例子
inline void Parser::parseSLine(std::string& sname, size_t& depth)
{
	depth = 0;
	for (; depth < line_.length(); ++depth)
		if (line_[depth] != '[') break;

	sname = line_.substr(depth, line_.length() - 2 * depth);
}

inline void Parser::parse(Util& util)
{
	while (std::getline(*f_, line_)) {
		++ln_;
		if (line_[0] == '#' || line_[0] == ';') continue;
		line_ = trim(line_);
		if (line_.empty()) continue;
		if (line_[0] == '[') {
			size_t depth;
			std::string sname;
			parseSLine(sname, depth);
			Util* lp = NULL;
			Util* parent = &util;
			if (depth > util.depth + 1)
				exit(0);
			if (util.depth == depth - 1)
				lp = &util.sections[sname];
			else {
				lp = util.parent;
				size_t n = util.depth - depth;
				for (size_t i = 0; i < n; ++i) lp = lp->parent;
				parent = lp;
				lp = &lp->sections[sname];
			}
			if (lp->depth != 0)
				exit(0);
			if (!lp->parent) {
				lp->depth = depth;
				lp->parent = parent;
			}
			parent->ordered_sections.push_back(parent->sections.find(sname));
			parse(*lp);
		}
		else
		{
			size_t n = line_.find('=');
			if (n == std::string::npos)
				exit(0);
			std::string v = value(trim(line_.substr(n + 1, line_.length() - n - 1)));
			std::pair<Util::value_map_t::const_iterator, bool> res = util.values.insert(std::make_pair(trim(line_.substr(0, n)), v));
			if (!res.second)
				exit(0);
			util.ordered_values.push_back(res.first);
		}
	}
}
//拿值
inline void Parser::dump(std::ostream& s, const Util& util, const std::string& sname)
{
	if (!sname.empty())
		s << '\n';

	for (size_t i = 0; i < util.depth; ++i)
		s << '[';

	if (!sname.empty())
		s << sname;

	for (size_t i = 0; i < util.depth; ++i)
		s << ']';

	if (!sname.empty())
		s << std::endl;

	for (Util::values_t::const_iterator it = util.ordered_values.begin(); it != util.ordered_values.end(); ++it)
		s << (*it)->first << '=' << (*it)->second << std::endl;

	for (Util::sections_t::const_iterator it = util.ordered_sections.begin(); it != util.ordered_sections.end(); ++it) {
		assert((*it)->second.depth == util.depth + 1);
		dump(s, (*it)->second, (*it)->first);
	}
}