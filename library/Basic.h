#ifndef BASIC_H_
#define BASIC_H_



namespace CAN
{
#ifndef NODEBUG
    #define CHECK_ERROR(CONDITION,DESCRIPTION) do{if(!(CONDITION))throw Error(DESCRIPTION);}while(0)
#else
    #define CHECK_ERROR(CONDITION,DESCRIPTION)
#endif

#define CHECK_FAIL(DESCRIPTION) do{throw Error(DESCRIPTION);}while(0)


    class NoCopyable
    {
    private:
        NoCopyable(const NoCopyable&);
        NoCopyable& operator=(const NoCopyable&);
    public:
        NoCopyable();
    };

	class Object
	{
	public:
		virtual ~Object();
	};


    template<typename T>
	struct POD
	{
		static const bool Result=false;
	};

	template<>struct POD<bool>{static const bool Result=true;};
	template<>struct POD<signed __int8>{static const bool Result=true;};
	template<>struct POD<unsigned __int8>{static const bool Result=true;};
	template<>struct POD<signed __int16>{static const bool Result=true;};
	template<>struct POD<unsigned __int16>{static const bool Result=true;};
	template<>struct POD<signed __int32>{static const bool Result=true;};
	template<>struct POD<unsigned __int32>{static const bool Result=true;};
	template<>struct POD<signed __int64>{static const bool Result=true;};
	template<>struct POD<unsigned __int64>{static const bool Result=true;};
	template<>struct POD<char>{static const bool Result=true;};
	template<>struct POD<wchar_t>{static const bool Result=true;};
	template<typename T>struct POD<T*>{static const bool Result=true;};
	template<typename T>struct POD<T&>{static const bool Result=true;};
	template<typename T, typename C>struct POD<T C::*>{static const bool Result=true;};
	template<typename T, signed __int64 _Size>struct POD<T[_Size]>{static const bool Result=POD<T>::Result;};
	template<typename T>struct POD<const T>{static const bool Result=POD<T>::Result;};
	template<typename T>struct POD<volatile T>{static const bool Result=POD<T>::Result;};
	template<typename T>struct POD<const volatile T>{static const bool Result=POD<T>::Result;};
}

#endif // !BASIC_H_