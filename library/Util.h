#ifndef UTIL_H_
#define UTIL_H_
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric>
#include <set>

namespace CAN
{
    class Func
    {
    public:
        // Range -----------------------------------
        static std::vector<int> Range(int start, int step, int end) 
        {
            std::vector<int> result;
            result.reserve((end - start) / step + 1);
            for (int i = start; i < end; i += step) 
            {
                result.push_back(i);
            }
            return result;
        }

        static std::vector<int> Range(int start, int end)
        {
            std::vector<int> result(end - start);
            std::iota(result.begin(), result.end(), start);
            return result;
        }

        static std::vector<int> Range(int end)
        {
            return Range(0, end);
        }

        // Map -------------------------------------
        template<typename TIn, typename TOut>
        static std::vector<TOut> Map(const std::vector<TIn>& in, std::function<TOut(TIn)> f)
        {
            std::vector<TOut> result(in.size());
            std::transform(in.begin(), in.end(), result.begin(), f);
            return result;
        }

        // Reduce ----------------------------------
        template<typename TIn, typename TOut>
        static TOut Reduce(const std::vector<TIn>& in, std::function<TOut(TIn, TIn)> f)
        {
            TIn init = in[0];
            for(auto t : in)
            {
                init = f(init, t);
            }
            return init;
        }

        // Math -----------------------------------
        // Sum
        template<typename TIn>
        static TIn Sum(const std::vector<TIn>& in)
        {
            return Reduce<TIn, TIn>(in, [](const TIn& a, const TIn& b){ return a + b; });
        }

        template<typename TIn, typename TOut>
	    static TOut Sum(const std::vector<TIn>& in, std::function<TOut(TIn)> f) 
        {
             return Sum(Map<TIn, TOut>(in, f));
        }

        // Max
        template<typename TIn>
        static TIn Max(const std::vector<TIn>& in)
        {
            return Reduce<TIn, TIn>(in, [](const TIn& a, const TIn& b){ return a > b ? a : b; });
        }

        template<typename TIn, typename TOut>
	    static TOut Max(const std::vector<TIn>& in, const std::function<TOut(TIn)> f) 
        {
            return Max(Map(in, f));
        }

        // Min
        template<typename TIn>
        static TIn Min(const std::vector<TIn>& in)
        {
            return Reduce<TIn, TIn>(in, [](const TIn& a, const TIn& b){ return a < b ? a : b; });
        }

        template<typename TIn, typename TOut>
	    static TOut Min(const std::vector<TIn>& in, const std::function<TOut(TIn)> f) 
        {
            return Min(Map(in, f));
        }

        // Average
        template<typename TIn>
	    static TIn Average(const std::vector<TIn>& in) 
        {
            return Sum(in) / in.size();
        }

        // Zip ------------------------------------
        template<typename TIn, typename TOut>
        static std::vector<TOut> Zip(const std::vector<TIn>& in1, const std::vector<TIn>& in2, std::function<TOut(TIn, TIn)> f)
        {
            if(in1.size() != in2.size())
                throw std::runtime_error("Inconsistent size");
            std::vector<TOut> result(in1.size());
            for(size_t i = 0; i < in1.size(); ++i)
            {
                result[i] = f(in1[i], in2[i]);
            }
            return result;
        }

        // Unique --------------------------------
        template<typename T>
	    static std::vector<T> Unique(const std::vector<T>& in) 
        {
            std::set<T> s(in.begin(), in.end());
            return std::vector<T>(s.begin(), s.end());
        }

        // Filter --------------------------------
        template<typename T>
        static std::vector<T> Filter(const std::vector<T>& in, const std::function<bool(T)> f)
        {
            std::vector<T> result;
            result.reserve(in.size());
            for(auto i : in)
            {
                if(f(i))
                {
                    result.push_back(i);
                }
            }
            return result;
        }
    };

    class UTIL
    {
    public:
        template<typename T1, typename T2>
        static std::string Print(T1 a, T2 b)
        {
            std::stringstream ss;
            ss << a << b;
            return ss.str();
        }

        template<typename T1, typename T2, typename T3>
        static std::string Print(T1 a, T2 b, T3 c)
        {
            std::stringstream ss;
            ss << a << b << c;
            return ss.str();
        }

        template<typename T1, typename T2, typename T3, typename T4>
        static std::string Print(T1 a, T2 b, T3 c, T4 d)
        {
            std::stringstream ss;
            ss << a << b << c << d;
            return ss.str();
        }

        template<typename T1, typename T2, typename T3, typename T4, typename T5>
        static std::string Print(T1 a, T2 b, T3 c, T4 d, T5 e)
        {
            std::stringstream ss;
            ss << a << b << c << d << e;
            return ss.str();
        }
    };
}
#endif // !UTIL_H_


#if 0
#include <iostream>

using namespace CAN;

int main()
{
    auto mVec = Func::Range(1, 10);
    for (auto v : Func::Unique(mVec))
        std::cout << v << std::endl;
/*
    auto sum = Func::Sum<int>(mVec);
    std::cout << sum << std::endl;
    for (auto v : mVec) {
        std::cout << v << std::endl;
    }

    auto reVec = Func::Map<int, int>(mVec, [](int i){ return i * i; });
    for (auto v : reVec) {
        std::cout << v << std::endl;
    }
*/
}

#endif