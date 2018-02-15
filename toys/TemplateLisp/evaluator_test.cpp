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


    return 0;
}