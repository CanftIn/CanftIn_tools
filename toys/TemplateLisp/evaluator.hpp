#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include "utils.hpp"

namespace CAN
{
    namespace TL
    {
        using namespace CAN::TL::UTIL;

        // Type of data
        template<int N> struct Int;
        template<bool B> struct Bool;
        struct Unit;

        // Add
        template<class T1, class T2> struct Add;
        template<int N1, int N2>
        struct Add<Int<N1>, Int<N2>>
        {
            using value = Int<(N1 + N2)>;
        };

        // Compare
        // >
        template<class T1, class T2> struct IsGreater;
        template<int N1, int N2>
        struct IsGreater<Int<N1>, Int<N2>>
        {
            using value = Bool<(N1 > N2)>;
        };

        // <
        template<class T1, class T2> struct IsLess;
        template<int N1, int N2>
        struct IsLess<Int<N1>, Int<N2>>
        {
            using value = Bool<(N1 < N2)>;
        };

        // ==
        template<class T1, class T2> struct IsEqual;
        template<int N1, int N2>
        struct IsEqual<Int<N1>, Int<N2>>
        {
            using value = Bool<(N1 == N2)>;
        };

        // Pair
        template<class T1, class T2> struct Pair;

        // Pair.first
        template<class T> struct First;
        template<class T1, class T2>
        struct First<Pair<T1, T2>>
        {
            using value = T1;
        };

        // Pair.second
        template<class T> struct Second;
        template<class T1, class T2>
        struct Second<Pair<T1, T2>>
        {
            using value = T2;
        };

        // List
        template<class T, class... T_Other> struct List;

        // List.N
        template<class T, class N> struct List_Ref;
        template<class T, class... T_Other, int N>
        struct List_Ref<List<T, T_Other...>, Int<N>>
        {
            using value = typename List_Ref<List<T_Other...>, Int<N-1>>::value;
        };
        template<class T, class... T_Other>
        struct List_Ref<List<T, T_Other...>, Int<0>>
        {
            using value = T;
        };
    }
}

#endif