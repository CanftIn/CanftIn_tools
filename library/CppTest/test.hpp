#ifndef TEST_HPP_
#define TEST_HPP_

#include "cpp_main.cpp"
#include "test.cpp"

#define CAN_TEST(exp) ((exp) ? static_cast<void>(0) : CAN::report_error(#exp, __FILE__, __LINE__))

#define CAN_CRITICAL_TEST(exp) ((exp) ? static_cast<void>(0) : CAN::report_critical_error(#exp, __FILE__, __LINE__))

#define CAN_ERROR(msg) CAN::report_error((msg), __FILE__, __LINE__)

#define CAN_CRITICAL_ERROR(msg) CAN::report_critical_error((msg), __FILE__, __LINE__)

namespace CAN
{
    void report_error(const char* msg, const char* file, int line);

    void report_critical_error(const char* msg, const char* file, int line);
}
#endif // !TEST_HPP_
