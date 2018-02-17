#ifndef UTIL_H_
#define UTIL_H_

#include<vector>
#include<string>
#include<functional>
#include<algorithm>
#include<numeric>

namespace CAN
{
    class Func
    {
    public:
        static std::vector<int> Range(int start, int end)
        {
            std::vector<int> result(end - start);
            std::iota(result.begin(), result.end(), start);
            return result;
        }

        template<typename TIn, typename TOut>
        static std::vector<TOut> Map(const std::vector<TIn>& in, std::function<TOut(TIn)> f)
        {
            std::vector<TOut> result(in.size());
            std::transform(in.begin(), in.end(), result.begin(), f);
            return result;
        }
    };
}
#endif // !UTIL_H_

#include <iostream>

using namespace CAN;

int main()
{
    auto mVec = Func::Range(1, 10);
    for (auto v : mVec) {
        std::cout << v << std::endl;
    }

    auto reVec = Func::Map<int, int>(mVec, [](int i){ return i * i; });
    for (auto v : reVec) {
        std::cout << v << std::endl;
    }
}