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
        template<class T, class... T_Other> 
        struct List
        {
            using value = Pair<T, typename List<T_Other...>::value>;
        };
        template<class T>
        struct List<T>
        {
            using value = Pair<T, Unit>;
        };

        // IsList
        template<class T>
        struct IsList
        {
            static const bool value = false;
        };
        template<class T1, class T2>
        struct IsList<Pair<T1, T2>>
        {
            static const bool value = IsList<T2>::value;
        };
        template<class T>
        struct IsList<Pair<T, Unit>>
        {
            static const bool value = true;
        };
        template<>
        struct IsList<Unit>
        {
            static const bool value = true;
        };

        // List.N
        template<class T, class N> struct List_Ref;
        template<class T1, class T2, int N>
        struct List_Ref<Pair<T1, T2>, Int<N>>
        {
            using value = typename List_Ref<T2, Int<N-1>>::value;
        };
        template<class T1, class T2>
        struct List_Ref<Pair<T1, T2>, Int<0>>
        {
            using value = T1;
        };

        // ListAppend
        template<class L, class NewT> struct ListAppend;
        template<class H, class T, class NewT>
        struct ListAppend<Pair<H, T>, NewT>
        {
            using value = Pair<H, typename ListAppend<T, NewT>::value>;
        };
        template<class NewT>
        struct ListAppend<Unit, NewT>
        {
            using value = Pair<NewT, Unit>;
        };

        // If_Then_Else
        template<class Cond, class T1, class T2> struct If_Then_Else;
        template<class T1, class T2>
        struct If_Then_Else<Bool<true>, T1, T2>
        {
            using value = T1;
        };
        template<class T1, class T2>
        struct If_Then_Else<Bool<false>, T1, T2>
        {
            using value = T2;
        };
    }
}

#endif