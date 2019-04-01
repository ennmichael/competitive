#include <iostream>
#include <bitset>
#include <random>
#include <random>
#include <algorithm>

int main()
{
    unsigned target;
    unsigned lower;
    unsigned upper;

    std::random_device rd;
    std::uniform_int_distribution<unsigned> d(1, 255);

    target = d(rd);
    lower = d(rd);
    upper = d(rd);

    if (upper < lower)
    {
        std::swap(lower, upper);
    }

    unsigned m = 0;
    unsigned mask = 0;
    for (unsigned i = lower; i <= upper; ++i)
    {
        auto const new_m = i | target;
        if ((new_m == m && i < mask) || new_m > m)
        {
            m = new_m;
            mask = i;
        }
    }

    std::cout << "T: " << target << '\n';
    std::cout << "L: " << lower << '\n';
    std::cout << "U: " << upper << '\n';

    std::cout << "L: " << std::bitset<8>(lower) << '\n';
    std::cout << "U: " << std::bitset<8>(upper) << '\n';
    std::cout << "T: " << std::bitset<8>(target) << '\n';
    std::cout << "M: " << std::bitset<8>(mask) << '\n';
    std::cout << "|: " << std::bitset<8>(m) << '\n';
}
