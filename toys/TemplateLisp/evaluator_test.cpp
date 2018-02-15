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

    // List
    StaticCheckEQ< List_Ref< List< Int<0>, Int<1>, Int<2>, Int<3> >, Int<2> >::value,
                   Int<2> >();
    StaticCheckEQ< List_Ref< List< Int<3> >, Int<2> >::value, Int<3> >();

    typedef List< List< Int<2>, Bool<false> >, 
                  List< Int<2>, Bool<true> >, 
                  List< Int<4> > >  
            L1;
    StaticCheckEQ< List_Ref< List_Ref< L1, Int<1> >::value, Int<1> >::value, Bool<true> >();
    StaticCheckEQ< List_Ref< List_Ref< L1, Int<2> >::value, Int<0> >::value, Int<4> >();
   
    return 0;
}