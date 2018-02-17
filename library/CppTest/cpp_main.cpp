#include <iostream>

int cpp_main(int argc, char* argv[]);

namespace CAN
{
    namespace TEST
    {
        class cpp_main_caller
        {
            int argc;
            char** argv;
        public:
            cpp_main_caller(int c, char** v) : argc(c), argv(v) {}
            int operator()() { return cpp_main(argc, argv); }
        };
    }
}

int main(int argc, char* argv[])
{
    try
    {
        CAN::TEST::cpp_main_caller(argc, argv);
    }
    catch(std::exception &)
    {
        std::cout << "main error" << std::endl;
    }

    return 0;
}