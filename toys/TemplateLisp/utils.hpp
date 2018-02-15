#ifndef UTILS_HPP_
#define UTILS_HPP_

namespace CAN
{
    namespace TL
    {
        namespace UTIL
        {
            template<bool>
            struct CompileTimeCheck;

            template<>
            struct CompileTimeCheck<true> {};

            template<class T1, class T2>
            struct StaticCheckEQ;

            template<class T>
            struct StaticCheckEQ<T, T> {};
        }
    }
}

#endif