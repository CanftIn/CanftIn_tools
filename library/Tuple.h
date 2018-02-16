#include "Basic.h"

namespace CAN
{
    class TupleNullItem
	{
	};
	template<typename T0 = TupleNullItem,typename T1 = TupleNullItem,typename T2 = TupleNullItem,typename T3 = TupleNullItem,typename T4 = TupleNullItem,typename T5 = TupleNullItem,typename T6 = TupleNullItem,typename T7 = TupleNullItem,typename T8 = TupleNullItem,typename T9 = TupleNullItem,typename T10 = TupleNullItem>
	class Tuple
	{
	};

    template<typename T0>
	class Tuple<T0> : public Object
	{
	public:
		T0 f0;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0)
			:f0(p0)
		{
		}
 
		static int Compare(const Tuple<T0>& a, const Tuple<T0>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1>
	class Tuple<T0,T1> : public Object
	{
	public:
		T0 f0;T1 f1;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1)
			:f0(p0),f1(p1)
		{
		}
 
		static int Compare(const Tuple<T0,T1>& a, const Tuple<T0,T1>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1,typename T2>
	class Tuple<T0,T1,T2> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2)
			:f0(p0),f1(p1),f2(p2)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2>& a, const Tuple<T0,T1,T2>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1,typename T2,typename T3>
	class Tuple<T0,T1,T2,T3> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;T3 f3;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2,T3 p3)
			:f0(p0),f1(p1),f2(p2),f3(p3)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2,T3>& a, const Tuple<T0,T1,T2,T3>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;if (a.f3 < b.f3) return -1; else if (a.f3 > b.f3) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2,T3>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2,T3>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2,T3>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2,T3>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2,T3>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2,T3>& value)const{ return Compare(*this, value) >= 0; }
	};
  
    template<typename T0,typename T1,typename T2,typename T3,typename T4>
	class Tuple<T0,T1,T2,T3,T4> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;T3 f3;T4 f4;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2,T3 p3,T4 p4)
			:f0(p0),f1(p1),f2(p2),f3(p3),f4(p4)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2,T3,T4>& a, const Tuple<T0,T1,T2,T3,T4>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;if (a.f3 < b.f3) return -1; else if (a.f3 > b.f3) return 1;if (a.f4 < b.f4) return -1; else if (a.f4 > b.f4) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2,T3,T4>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2,T3,T4>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2,T3,T4>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2,T3,T4>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2,T3,T4>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2,T3,T4>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5>
	class Tuple<T0,T1,T2,T3,T4,T5> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;T3 f3;T4 f4;T5 f5;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2,T3 p3,T4 p4,T5 p5)
			:f0(p0),f1(p1),f2(p2),f3(p3),f4(p4),f5(p5)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2,T3,T4,T5>& a, const Tuple<T0,T1,T2,T3,T4,T5>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;if (a.f3 < b.f3) return -1; else if (a.f3 > b.f3) return 1;if (a.f4 < b.f4) return -1; else if (a.f4 > b.f4) return 1;if (a.f5 < b.f5) return -1; else if (a.f5 > b.f5) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2,T3,T4,T5>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2,T3,T4,T5>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2,T3,T4,T5>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2,T3,T4,T5>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2,T3,T4,T5>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2,T3,T4,T5>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6>
	class Tuple<T0,T1,T2,T3,T4,T5,T6> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;T3 f3;T4 f4;T5 f5;T6 f6;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2,T3 p3,T4 p4,T5 p5,T6 p6)
			:f0(p0),f1(p1),f2(p2),f3(p3),f4(p4),f5(p5),f6(p6)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2,T3,T4,T5,T6>& a, const Tuple<T0,T1,T2,T3,T4,T5,T6>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;if (a.f3 < b.f3) return -1; else if (a.f3 > b.f3) return 1;if (a.f4 < b.f4) return -1; else if (a.f4 > b.f4) return 1;if (a.f5 < b.f5) return -1; else if (a.f5 > b.f5) return 1;if (a.f6 < b.f6) return -1; else if (a.f6 > b.f6) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2,T3,T4,T5,T6>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2,T3,T4,T5,T6>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2,T3,T4,T5,T6>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2,T3,T4,T5,T6>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2,T3,T4,T5,T6>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2,T3,T4,T5,T6>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7>
	class Tuple<T0,T1,T2,T3,T4,T5,T6,T7> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;T3 f3;T4 f4;T5 f5;T6 f6;T7 f7;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2,T3 p3,T4 p4,T5 p5,T6 p6,T7 p7)
			:f0(p0),f1(p1),f2(p2),f3(p3),f4(p4),f5(p5),f6(p6),f7(p7)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& a, const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;if (a.f3 < b.f3) return -1; else if (a.f3 > b.f3) return 1;if (a.f4 < b.f4) return -1; else if (a.f4 > b.f4) return 1;if (a.f5 < b.f5) return -1; else if (a.f5 > b.f5) return 1;if (a.f6 < b.f6) return -1; else if (a.f6 > b.f6) return 1;if (a.f7 < b.f7) return -1; else if (a.f7 > b.f7) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8>
	class Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;T3 f3;T4 f4;T5 f5;T6 f6;T7 f7;T8 f8;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2,T3 p3,T4 p4,T5 p5,T6 p6,T7 p7,T8 p8)
			:f0(p0),f1(p1),f2(p2),f3(p3),f4(p4),f5(p5),f6(p6),f7(p7),f8(p8)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& a, const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;if (a.f3 < b.f3) return -1; else if (a.f3 > b.f3) return 1;if (a.f4 < b.f4) return -1; else if (a.f4 > b.f4) return 1;if (a.f5 < b.f5) return -1; else if (a.f5 > b.f5) return 1;if (a.f6 < b.f6) return -1; else if (a.f6 > b.f6) return 1;if (a.f7 < b.f7) return -1; else if (a.f7 > b.f7) return 1;if (a.f8 < b.f8) return -1; else if (a.f8 > b.f8) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8>& value)const{ return Compare(*this, value) >= 0; }
	};

    template<typename T0,typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7,typename T8,typename T9>
	class Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9> : public Object
	{
	public:
		T0 f0;T1 f1;T2 f2;T3 f3;T4 f4;T5 f5;T6 f6;T7 f7;T8 f8;T9 f9;
 
		Tuple()
		{
		}
 
		Tuple(T0 p0,T1 p1,T2 p2,T3 p3,T4 p4,T5 p5,T6 p6,T7 p7,T8 p8,T9 p9)
			:f0(p0),f1(p1),f2(p2),f3(p3),f4(p4),f5(p5),f6(p6),f7(p7),f8(p8),f9(p9)
		{
		}
 
		static int Compare(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& a, const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& b)
		{
			if (a.f0 < b.f0) return -1; else if (a.f0 > b.f0) return 1;if (a.f1 < b.f1) return -1; else if (a.f1 > b.f1) return 1;if (a.f2 < b.f2) return -1; else if (a.f2 > b.f2) return 1;if (a.f3 < b.f3) return -1; else if (a.f3 > b.f3) return 1;if (a.f4 < b.f4) return -1; else if (a.f4 > b.f4) return 1;if (a.f5 < b.f5) return -1; else if (a.f5 > b.f5) return 1;if (a.f6 < b.f6) return -1; else if (a.f6 > b.f6) return 1;if (a.f7 < b.f7) return -1; else if (a.f7 > b.f7) return 1;if (a.f8 < b.f8) return -1; else if (a.f8 > b.f8) return 1;if (a.f9 < b.f9) return -1; else if (a.f9 > b.f9) return 1;
			return 0;
		}
 
		bool operator==(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& value)const{ return Compare(*this, value) == 0; }
		bool operator!=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& value)const{ return Compare(*this, value) != 0; }
		bool operator< (const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& value)const{ return Compare(*this, value) < 0; }
		bool operator<=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& value)const{ return Compare(*this, value) <= 0; }
		bool operator> (const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& value)const{ return Compare(*this, value) > 0; }
		bool operator>=(const Tuple<T0,T1,T2,T3,T4,T5,T6,T7,T8,T9>& value)const{ return Compare(*this, value) >= 0; }
	};
}