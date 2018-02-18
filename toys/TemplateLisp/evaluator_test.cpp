#include "evaluator.hpp"
#include "utils.hpp"

using namespace CAN::TL;
using namespace CAN::TL::UTIL;

int main()
{
    // Add Testing
    StaticCheckEQ< Add< Int<1>, Int<3> >::value, Int<4> >();
    StaticCheckEQ< Add< Int<-9>, Int<45> >::value, Int<36> >();


    // Comparing Testing
    StaticCheckEQ< IsGreater< Int<5>, Int<8> >::value, Bool<false> >();
    StaticCheckEQ< IsLess< Int<5>, Int<8> >::value, Bool<true> >();
    StaticCheckEQ< IsEqual< Int<8>, Int<8> >::value, Bool<true> >();

    // Pair Testing
    using P = Pair< Pair<Int<4>, Bool<true>>,
                    Pair<Pair<Int<2>, Unit>,
                         Bool<false>>>;
    StaticCheckEQ< First< First<P>::value >::value, Int<4> >();
    StaticCheckEQ< Second< First< Second<P>::value >::value >::value, Unit >();
    StaticCheckEQ< Second< Second<P>::value >::value, Bool<false> >();

    // List Testing
    using L1 = List< List< Int<2>, Bool<false> >::value, 
                     List< Int<4>, Bool<true> >::value, 
                     List< Int<6> >::value >::value;
    using P1 = Pair< Pair< Int<2>, Pair<Bool<false>, Unit> >,
                     Pair< Pair< Int<4>, Pair<Bool<true>, Unit> >,
                           Pair< Pair<Int<6>, Unit>,
                                 Unit > > >;
    StaticCheckEQ<L1, P1>();
    // IsList
    CompileTimeCheck< IsList<L1>::value >();    
    CompileTimeCheck< IsList<P1>::value >();
    CompileTimeCheck< IsList<Unit>::value >();
    CompileTimeCheck< IsList< Second<Second<P1>::value>::value >::value >();
    
    // List.N
    typedef List< Int<0>, Int<1>, Int<2>, Int<3>, Int<4> >::value L3;
    StaticCheckEQ< List_Ref< L3, Int<2> >::value, Int<2> >();
    StaticCheckEQ< List_Ref< List_Ref< L1, Int<0> >::value, Int<0> >::value, Int<2> >(); 

    // ListAppend
    typedef List< Int<0>, Int<1>, Int<2>, Int<3>, Int<4>, Int<5> >::value L4;
    StaticCheckEQ< ListAppend< L3, Int<5> >::value, L4 >();
    StaticCheckEQ< ListAppend< ListAppend< L3, Int<5> >::value, List< Int<9> > >, 
                   ListAppend< L4, List< Int<9> > > >();

    
    // If_Then_Else Testing
    StaticCheckEQ< If_Then_Else< IsGreater< Int<5>, Int<8> >::value,
                                 L1,
                                 P>::value,
                   P >();
    StaticCheckEQ< If_Then_Else< IsLess< Int<5>, Int<8> >::value,
                                 L1,
                                 P>::value,
                   L1 >();    

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
    return 0;
}