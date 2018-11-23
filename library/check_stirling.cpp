#include "factorial.h"
#include <iostream>

using namespace Competitive;

template <class Integer>
Integer real_factorial(Integer n)
{
    if (n == 0)
        return 1;
    return n * real_factorial(n - 1);
}

int main(int, char**)
{
    for (int i = 0; i < 100; ++i)
    {
        std::cout << i << ":\n";
        std::cout << (factorial(i) - real_factorial(i)) << "\n\n";
    }
}

