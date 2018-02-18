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
        template<int N> struct Var;
        struct EmptyType;
        struct Unit;

        // VarValList
        struct EmptyVarValList;
        template<class Varible, class Val, class Tail> struct VarValList;
        template<class Varible, class Val>
        struct VarValList<Varible, Val, EmptyVarValList>;

        template<class Varible, class Val, class L>
        struct VarValListExtend
        {
            using value = VarValList<Varible, Val, L>;
        };

        template<class V, class L> struct VarValListLookup;
        template<class V, class Varible, class Val, class Tail>
        struct VarValListLookup<V, VarValList<Varible, Val, Tail>>
        {
            using value = typename VarValListLookup<V, Tail>::value;
        };
        template<class V, class Val, class Tail>
        struct VarValListLookup<V, VarValList<V, Val, Tail>>
        {
            using value = Val;
        };
        template<class V>
        struct VarValListLookup<V, EmptyVarValList>
        {
            using value = EmptyType;
        };

        // Env
        struct EmptyEnv;
        template<class Head, class Tail> struct Env;
        template<class T> struct Env<T, EmptyEnv>;

        template<class Head, class E>
        struct EnvExtend
        {
            using value = Env<Head, E>;
        };

        template<class V, class E> struct EnvLookup;
        template<class V, class L, class ETail>
        struct EnvLookup<V, Env<L, ETail>>
        {
            using ResultType = typename VarValListLookup<V, L>::value;
            using value = typename Select< IsEQ<ResultType, EmptyType>::value,
                                           typename EnvLookup<V, ETail>::value,
                                           ResultType >::value;
        };
        template<class V>
        struct EnvLookup<V, EmptyEnv>
        {
            using value = EmptyType;
        };

        // Eval
        template<class Exp, class Environ> struct EvalUnderEnv;

        template<class Exp>
        struct Eval
        {
            using value = typename EvalUnderEnv<Exp, EmptyEnv>::value;
        };

        template<int N, class Environ>
        struct EvalUnderEnv<Int<N>, Environ>
        {
            using value = Int<N>;
        };
        template<bool B, class Environ>
        struct EvalUnderEnv<Bool<B>, Environ>
        {
            using value = Bool<B>;
        };
        template<int N, class Environ>
        struct EvalUnderEnv<Var<N>, Environ>
        {
            using value = Var<N>;
        };
        template<class Environ>
        struct EvalUnderEnv<Unit, Environ>
        {
            using value = Unit;
        };

        // Add
        template<class T1, class T2> struct Add;
        template<int N1, int N2, class Environ>
        struct EvalUnderEnv<Add<Int<N1>, Int<N2>>, Environ>
        {
            using value = Int<(N1 + N2)>;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<Add<T1, T2>, Environ>
        {
            using T1Val = typename EvalUnderEnv<T1, Environ>::value;
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = typename EvalUnderEnv<Add<T1Val, T2Val>, Environ>::value;
        };
        
        // Compare
        // >
        template<class T1, class T2> struct IsGreater;
        template<int N1, int N2, class Environ>
        struct EvalUnderEnv<IsGreater<Int<N1>, Int<N2>>, Environ>
        {
            using value = Bool<(N1 > N2)>;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<IsGreater<T1, T2>, Environ>
        {
            using T1Val = typename EvalUnderEnv<T1, Environ>::value;
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = typename EvalUnderEnv<IsGreater<T1Val, T2Val>, Environ>::value;
        };

        // <
        template<class T1, class T2> struct IsLess;
        template<int N1, int N2, class Environ>
        struct EvalUnderEnv<IsLess<Int<N1>, Int<N2>>, Environ>
        {
            using value = Bool<(N1 < N2)>;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<IsLess<T1, T2>, Environ>
        {
            using T1Val = typename EvalUnderEnv<T1, Environ>::value;
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = typename EvalUnderEnv<IsLess<T1Val, T2Val>, Environ>::value;
        };

        // ==
        template<class T1, class T2> struct IsEqual;
        template<int N1, int N2, class Environ>
        struct EvalUnderEnv<IsEqual<Int<N1>, Int<N2>>, Environ>
        {
            using value = Bool<(N1 == N2)>;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<IsEqual<T1, T2>, Environ>
        {
            using T1Val = typename EvalUnderEnv<T1, Environ>::value;
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = typename EvalUnderEnv<IsEqual<T1Val, T2Val>, Environ>::value;
        };

        // IsUnit
        template<class T> struct IsUnit;
        template<class Environ>
        struct EvalUnderEnv<IsUnit<Unit>, Environ>
        {
            using value = Bool<true>;
        };
        template<class T, class Environ>
        struct EvalUnderEnv<IsUnit<T>, Environ>
        {
            using TVal = typename EvalUnderEnv<T, Environ>::value;
            using value = typename Select< IsEQ<TVal, Unit>::value,
                                           Bool<true>,
                                           Bool<false> >::value;
        };

        // Pair
        template<class T1, class T2> struct Pair;
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<Pair<T1, T2>, Environ>
        {
            using T1Val = typename EvalUnderEnv<T1, Environ>::value;
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = Pair<T1Val, T2Val>;
        };

        // Pair.first
        template<class T> struct First;
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<First<Pair<T1, T2>>, Environ>
        { 
            using value = T1; 
        };
        template<class T, class Environ>
        struct EvalUnderEnv<First<T>, Environ>
        {
            using TVal = typename EvalUnderEnv<T, Environ>::value;
            using value = typename EvalUnderEnv<First<TVal>, Environ>::value;
        };

        // Pair.second
        template<class T> struct Second;
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<Second<Pair<T1, T2>>, Environ>
        { 
            using value = T2; 
        };
        template<class T, class Environ>
        struct EvalUnderEnv<Second<T>, Environ>
        {
            using TVal = typename EvalUnderEnv<T, Environ>::value;
            using value = typename EvalUnderEnv<Second<TVal>, Environ>::value;
        };

        // List
        template<class... T_Other> struct List;

        template<class T, class... T_Other, class Environ> 
        struct EvalUnderEnv<List<T, T_Other...>, Environ>
        {
            static const int ArgsNum = sizeof...(T_Other) + 1;
            using TVal = typename EvalUnderEnv<T, Environ>::value;
            using TailType = typename Select< ArgsNum == 1,
                                              Unit,
                                              List<T_Other...> >::value;
            using value = Pair<TVal, typename EvalUnderEnv<TailType, Environ>::value>;
        };

        // IsList
        template<class T>
        struct IsList
        {
            static const bool MayBeList = false;
        };
        template<class T1, class T2>
        struct IsList<Pair<T1, T2>>
        {
            static const bool MayBeList = true;
        };
        template<>
        struct IsList<Unit>
        {
            static const bool MayBeList = true;
        };

        template<class T, class Environ>
        struct EvalUnderEnv<IsList<T>, Environ>
        {
            using TVal = typename EvalUnderEnv<T, Environ>::value;
            using TmpType = typename Select< IsList<TVal>::MayBeList,
                                             TVal,
                                             EmptyType >::value;
            using value = typename EvalUnderEnv<IsList<TmpType>, Environ>::value;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<IsList<Pair<T1, T2>>, Environ>
        {
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = typename EvalUnderEnv<IsList<T2Val>, Environ>::value;
        };
        template<class T, class Environ>
        struct EvalUnderEnv<IsList<Pair<T, Unit>>, Environ>
        {
            using value = Bool<true>;
        };
        template<class Environ>
        struct EvalUnderEnv<IsList<Unit>, Environ>
        {
            using value = Bool<true>;
        };
        template<class Environ>
        struct EvalUnderEnv<IsList<EmptyType>, Environ>
        {
            using value = Bool<false>;
        };

        // List.N
        template<class T, class N> 
        struct List_Ref
        {
            static const bool MayBeList = false;
        };
        template<class T1, class T2, int N>
        struct List_Ref<Pair<T1, T2>, Int<N>>
        {
            static const bool MayBeList = true;
        };

        template<class T, class N, class Environ>
        struct EvalUnderEnv<List_Ref<T, N>, Environ>
        {
            using TVal = typename EvalUnderEnv<T, Environ>::value;
            using Num = typename EvalUnderEnv<N, Environ>::value;
            using TmpType = typename Select< List_Ref<TVal, Num>::MayBeList,
                                             TVal,
                                             EmptyType >::value;
            using value = typename EvalUnderEnv<List_Ref<TmpType, Num>, Environ>::value;
        };
        template<class T1, class T2, int N, class Environ>
        struct EvalUnderEnv<List_Ref<Pair<T1, T2>, Int<N>>, Environ>
        {
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = typename EvalUnderEnv<List_Ref<T2Val, Int<N-1>>, Environ>::value;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<List_Ref<Pair<T1, T2>, Int<0>>, Environ>
        {
            using value = typename EvalUnderEnv<T1, Environ>::value;
        };
        template<class N, class Environ>
        struct EvalUnderEnv<List_Ref<EmptyType, N>, Environ>
        {
            using value = Bool<false>;
        };

        // ListAppend
        template<class L, class NewT> struct ListAppend;
        template<class T, class NewT, class Environ>
        struct EvalUnderEnv<ListAppend<T, NewT>, Environ>
        {
            using TVal =  typename EvalUnderEnv<T, Environ>::value;
            using NewTVal = typename EvalUnderEnv<NewT, Environ>::value;
            using value = typename EvalUnderEnv<ListAppend<TVal, NewTVal>, Environ>::value;
        };
        template<class H, class T, class NewT, class Environ>
        struct EvalUnderEnv<ListAppend<Pair<H, T>, NewT>, Environ>
        {
            using HVal = typename EvalUnderEnv<H, Environ>::value;
            using TVal = typename EvalUnderEnv<T, Environ>::value;
            using NewTVal = typename EvalUnderEnv<NewT, Environ>::value;
            using value = Pair< HVal, 
                                typename EvalUnderEnv<ListAppend<TVal, NewTVal>, Environ>::value>;
        };
        template<class NewT, class Environ>
        struct EvalUnderEnv<ListAppend<Unit, NewT>, Environ>
        {
            using NewTVal = typename EvalUnderEnv<NewT, Environ>::value;
            using value = Pair<NewTVal, Unit>;
        };

        // If_Then_Else
        template<class Cond, class T1, class T2> struct If_Then_Else;
        template<class Cond, class T1, class T2, class Environ>
        struct EvalUnderEnv< If_Then_Else<Cond, T1, T2>, Environ >
        {
            using CondVal = typename EvalUnderEnv<Cond, Environ>::value;
            using value = typename EvalUnderEnv<If_Then_Else<CondVal, T1, T2>, Environ>::value;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<If_Then_Else<Bool<true>, T1, T2>, Environ>
        { 
            using T1Val = typename EvalUnderEnv<T1, Environ>::value;
            using value = T1Val;
        };
        template<class T1, class T2, class Environ>
        struct EvalUnderEnv<If_Then_Else<Bool<false>, T1, T2>, Environ>
        {
            using T2Val = typename EvalUnderEnv<T2, Environ>::value;
            using value = T2Val;
        };
        
    }
}

#endif