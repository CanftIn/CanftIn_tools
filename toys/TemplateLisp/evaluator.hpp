#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include "utils.hpp"

namespace CAN
{
    namespace TL
    {
        using namespace CAN::TL::UTIL;
        template<int N> struct Int;
        template<bool B> struct Bool;

        //Add
        template<class T1, class T2> struct Add;

        template<int N1, int N2>
        struct Add<Int<N1>, Int<N2>>
        {
            using value = Int<(N1 + N2)>;
        };

        //Compare
        template<class T1, class T2> struct IsGreater;

        template<int N1, int N2>
        struct IsGreater<Int<N1>, Int<N2>>
        {
            using value = Bool<(N1 > N2)>;
        };

        template<class T1, class T2> struct IsLess;

        template<int N1, int N2>
        struct IsLess<Int<N1>, Int<N2>>
        {
            using value = Bool<(N1 < N2)>;
        };

        template<class T1, class T2> struct IsEqual;

        template<int N1, int N2>
        struct IsEqual<Int<N1>, Int<N2>>
        {
            using value = Bool<(N1 == N2)>;
        };
    }
}

#endif