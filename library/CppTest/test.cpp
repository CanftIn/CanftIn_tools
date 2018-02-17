#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "global.h"

namespace CAN
{
    namespace TEST
    {
        int test_errors = 0;

        class test_exception : public std::runtime_error
        {
        public:
            test_exception() : std::runtime_error("fatal test error") {}
        };
    }

    void report_error(const char* msg, const char* file, int line)
    {
        ++TEST::test_errors;
        std::cout << "\n**** test failed: " << msg << ", file: " << file
                  << ", line: " << line << std::endl;
    }

    void report_critical_error(const char* msg, const char* file, int line)
    {
        report_error(msg, file, line);
        throw TEST::test_exception();
    }

    // cpp_main() --------------------------------------------------

    // user's test_main()
    int test_main(int argc, char* argv[]);

    int cpp_main(int argc, char* argv[])
    {
        int result = 0;

        try
        {
            result = test_main(argc, argv);
        }
        catch(const CAN::TEST::test_exception &)
        {
            std::cout << "\n**** previous test error is fatal" << std::endl;
            CAN::TEST::test_errors = 0;
            result = CAN::exit_test_failure;
        }

        if(CAN::TEST::test_errors)
        {
             std::cout << "\n**** " << CAN::TEST::test_errors
              << " test errors detected" << std::endl;
              result = CAN::exit_test_failure;
        }
        return result;
    }

}