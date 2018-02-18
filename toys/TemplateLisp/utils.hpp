#ifndef UTILS_HPP_
#define UTILS_HPP_

namespace CAN
{
    namespace TL
    {
        namespace UTIL
        {
            template<bool> struct CompileTimeCheck;
            template<> struct CompileTimeCheck<true> {};

            template<class T1, class T2> struct StaticCheckEQ;
            template<class T> struct StaticCheckEQ<T, T> {};

            template<class T1, class T2>
            struct IsEQ
            {
                static const bool value = false;
            };
            template<class T>
            struct IsEQ<T, T>
            {
                static const bool value = true;
            };

            template<class T1, class T2>
            struct NotEQ
            {
                static const bool value = true;
            };
            template<class T>
            struct NotEQ<T, T>
            {
                static const bool valueu = false;
            };

            template<int N> struct Int2Type { static const int v = N; };

            template<bool B, class T1, class T2> struct Select;
            template<class T1, class T2>
            struct Select<true, T1, T2>
            {
                using value = T1;
            };
            template<class T1, class T2>
            struct Select<false, T1, T2>
            {
                using value = T2;
            };

            template<bool B, class T> struct enable_if;
            template<class T>
            struct enable_if<true, T>
            {
                using type = T;
            };
        }
    }
}

#endif