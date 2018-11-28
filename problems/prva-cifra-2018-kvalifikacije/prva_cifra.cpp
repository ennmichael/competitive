#include <iostream>
#include <cmath>

unsigned long first_digit(unsigned long n) noexcept
{
    unsigned long constexpr e9 = 1e9;
    unsigned long constexpr e8 = 1e8;
    unsigned long constexpr e7 = 1e7;
    unsigned long constexpr e6 = 1e6;
    unsigned long constexpr e5 = 1e5;
    unsigned long constexpr e4 = 1e4;
    unsigned long constexpr e3 = 1e3;
    unsigned long constexpr e2 = 1e2;
    unsigned long constexpr e1 = 1e1;

    if (n >= e9)
        return n / e9;
    if (n >= e8)
        return n / e8;
    if (n >= e7)
        return n / e7;
    if (n >= e6)
        return n / e6;
    if (n >= e5)
        return n / e5;
    if (n >= e4)
        return n / e4;
    if (n >= e3)
        return n / e3;
    if (n >= e2)
        return n / e2;
    if (n >= e1)
        return n / e1;
    return n;
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    unsigned long a;
    unsigned long b;
    std::cin >> a;
    std::cin >> b;
    auto const a_first_digit = first_digit(a);
    auto const b_first_digit = first_digit(b);
    if (a_first_digit > b_first_digit)
    {
        std::cout << a << '\n';
    }
    else if (a_first_digit < b_first_digit)
    {
        std::cout << b << '\n';
    }
    else
    {
        std::cout << std::max(a, b) << '\n';
    }
}

