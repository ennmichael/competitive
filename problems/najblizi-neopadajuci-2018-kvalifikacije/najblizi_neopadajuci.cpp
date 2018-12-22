#include <iostream>
#include <array>
#include <cmath>

using Digits = std::array<int, 10>;

Digits get_digits(unsigned long n)
{
    unsigned long constexpr limit = 1e9;

    Digits digits;
    unsigned long div = 1;
    std::size_t i = 9;
    while (div <= limit)
    {
        div *= 10;
    }
}

unsigned long get_number(Digits const& digits)
{

}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    for (auto const d : digits(123))
        std::cout << d << ' ';
    std::cout << '\n';

    unsigned long n;
    std::cin >> n;
    solve(n);
}

