#include "evaluator.hpp"
#include "utils.hpp"

using namespace CAN::TL;
using namespace CAN::TL::UTIL;

int main()
{
    // ------------------------------------
    // Basic Testing
    StaticCheckEQ< Eval< Int<4> >, Int<4> >;
    StaticCheckEQ< Eval< Bool<true> >, Bool<true> >;
    StaticCheckEQ< Eval< Var<4> >, Var<4> >;
    StaticCheckEQ< Eval< Unit >, Unit >;
    // ------------------------------------
    
    // ------------------------------------
    // Add Testing
    StaticCheckEQ< Eval< Add< Add< Int<1>, Int<3> >, Int<4> > >::value, Int<8> >();
    StaticCheckEQ< Eval< Add< Int<-9>, Int<45> > >::value, Int<36> >();
    // ------------------------------------

    // ------------------------------------
    // Comparing Testing
    StaticCheckEQ< Eval< IsGreater< Add< Int<1>, Int<4> >, Int<8> > >::value, Bool<false> >();
    StaticCheckEQ< Eval< IsLess< Add< Int<1>, Int<4> >, Int<8> > >::value, Bool<true> >();
    StaticCheckEQ< Eval< IsEqual< Add< Int<4>, Int<4> >, Int<8> > >::value, Bool<true> >();

    StaticCheckEQ< Eval< IsUnit<Unit> >::value, Bool<true> >();
    StaticCheckEQ< Eval< IsUnit< Add< Int<2>, Int<2> > > >::value, Bool<false> >();
    // ------------------------------------

    // ------------------------------------
    // Pair Testing
    using P = Pair< Pair< Int<4>, Bool<true> >,
                    Pair< Pair<Int<2>, Unit>,
                          Bool<false> > >;
    StaticCheckEQ< Eval<P>::value, P >();
    StaticCheckEQ< Eval< First< First<P> > >::value, Int<4> >();
    StaticCheckEQ< Eval< Second< First< Second<P> > > >::value, Unit >();
    StaticCheckEQ< Eval< Second< Second<P> > >::value, Bool<false> >();
    // ------------------------------------

    // ------------------------------------
    // List Testing
    using L1 = List< List< Int<2>, Bool<false> >, 
                     List< Int<4>, Bool<true> >, 
                     List< Int<6> > >;
    using P1 = Pair< Pair< Int<2>, Pair<Bool<false>, Unit> >,
                     Pair< Pair< Int<4>, Pair<Bool<true>, Unit> >,
                           Pair< Pair<Int<6>, Unit>,
                                 Unit > > >;
    StaticCheckEQ< Eval<L1>::value, Eval<P1>::value >();
    StaticCheckEQ< Eval< List< Int<5> > >::value, Pair< Int<5>, Unit > >();
    // IsList
    StaticCheckEQ< Eval< IsList<L1> >::value, Bool<true> >();
    StaticCheckEQ< Eval< IsList<P1> >::value, Bool<true> >();
    StaticCheckEQ< Eval< IsList<Unit> >::value, Bool<true> >();
    StaticCheckEQ< Eval< IsList< Second<Second<P1> > > >::value, Bool<true> >();
    StaticCheckEQ< Eval< IsList<P> >::value, Bool<false> >();
    
    // List.N
    using L3 = List< Int<0>, Int<1>, Int<2>, Int<3>, Int<4> >;
    StaticCheckEQ< Eval< List_Ref< L3, Add< Int<2>, Int<0> > > >::value, Int<2> >();
    StaticCheckEQ< Eval< List_Ref< List_Ref< L1, Add< Int<0>, Int<0> > >, 
                                  Add< Int<-2>, Int<2> > > >::value, 
                   Int<2> >(); 

    // ListAppend
    using L4 = List< Int<0>, Int<1>, Int<2>, Int<3>, Int<4>, Int<5> >;
    StaticCheckEQ< Eval< ListAppend< L3, Int<5> > >::value, Eval<L4>::value >();
    StaticCheckEQ< Eval< ListAppend< ListAppend< L3, Add< Int<1>, Int<4> > >, 
                                     List< Int<9> > > >::value, 
                   Eval< ListAppend< L4, List< Int<9> > > >::value >();
    // ------------------------------------

    // ------------------------------------
    // If_Then_Else Testing
    StaticCheckEQ< Eval< If_Then_Else< IsGreater< Int<5>, Int<8> >,
                                       L1,
                                       P > >::value,
                    P >();
    StaticCheckEQ< Eval< If_Then_Else< IsLess< Int<5>, Int<8> >,
                                       L1,
                                       P> >::value,
                   Eval<L1>::value >();    
    // ------------------------------------

    // ------------------------------------
    // VarValList Testing
    using VarValL0 = VarValList< Var<0>, Int<0>,
                                 VarValList< Var<1>, Int<1>, EmptyVarValList > >;
    using VarValL1 = VarValList< Var<2>, Int<2>, 
                                 VarValList< Var<0>, Int<0>,
                                             VarValList< Var<1>, Int<1>, 
                                                         EmptyVarValList > > >;
    StaticCheckEQ< VarValListExtend< Var<2>, Int<2>, VarValL0 >::value,
                   VarValL1 >;

    StaticCheckEQ< VarValListLookup<Var<2>, VarValL1>::value, Int<2> >();
    StaticCheckEQ< VarValListLookup<Var<0>, VarValL1>::value, Int<0> >();
    StaticCheckEQ< VarValListLookup<Var<1>, VarValL1>::value, Int<1> >();
    StaticCheckEQ< VarValListLookup<Var<3>, VarValL1>::value, EmptyType >();
    // ------------------------------------

    // ------------------------------------
    // Env Testing
    using VarValL2 = VarValList< Var<8>, Int<8>,
                                 VarValList< Var<9>, Int<9>, EmptyVarValList > >;
    using VarValL3 = VarValList< Var<5>, Int<5>,
                                 VarValList< Var<6>, Int<6>,
                                             VarValList< Var<7>, Int<7>,
                                                         EmptyVarValList > > >;

    using E0 = Env< VarValL2,
                    Env< VarValL3, EmptyEnv > >;
    using E1 = Env< VarValL0, 
                    Env< VarValL1,
                         Env< VarValL2,
                              Env< VarValL3, EmptyEnv > > > >;

    StaticCheckEQ< EnvExtend<VarValL0, EnvExtend<VarValL1, E0>::value>::value, E1 >();

    StaticCheckEQ< EnvLookup<Var<0>, E1>::value, Int<0> >();
    StaticCheckEQ< EnvLookup<Var<0>, E0>::value, EmptyType >();
    StaticCheckEQ< EnvLookup<Var<8>, E1>::value, Int<8> >();
    StaticCheckEQ< EnvLookup<Var<7>, E1>::value, Int<7> >();
    StaticCheckEQ< EnvLookup<Var<6>, E0>::value, Int<6> >();
    // ------------------------------------

    // ------------------------------------
    // Lambda Testing
    using Plus = Lambda< ParamList< Var<0>, Var<1> >,
                         Add< Var<0>, Var<1> > >;     
    StaticCheckEQ< Eval<Plus>::value, Closure<EmptyEnv, Plus> >();                     
    return 0;
}