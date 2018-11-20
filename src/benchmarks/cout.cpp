#include <iostream>

int main(int, char**)
{
    for (unsigned long long i = 0; i < 100'000'000; ++i)
    {
        std::cout << i << '\n';
    }
}

