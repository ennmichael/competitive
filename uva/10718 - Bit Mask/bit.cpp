#include <iostream>
#include <bitset>
#include <cmath>

// First check by bruteforce, then try to derive a solution

using Bits = std::bitset<32>;

struct Solution {
    unsigned long mask;
    unsigned long expression;
};

unsigned long solve(unsigned long target, unsigned long lower, unsigned long upper)
{
    auto const forward = [&]
    {
        Bits result = lower;
        Bits target_mask = target;

        for (std::size_t i = 0; i < result.size(); ++i)
        {
            if (target_mask[i] == 0)
            {
                result[i] = 1;
            }
            else if (target_mask[i] == 1)
            {
                result[i] = 0;
            }
            
            if (result.to_ulong() > upper)
            {
                result[i] = 0;
                break;
            }
        }

        result &= ~target_mask;

        return Solution { result.to_ulong(), (result | target_mask).to_ulong() };
    };

    auto const backward = [&]
    {
        Bits result = lower;
        Bits target_mask = target;

        for (long long i = result.size() - 1; i >= 0; --i)
        {
            if (target_mask[i] == 0)
            {
                result[i] = 1;
            }
            else if (target_mask[i] == 1)
            {
                result[i] = 0;
            }
            
            if (result.to_ulong() > upper)
            {
                result[i] = 0;
            }
        }

        return Solution { result.to_ulong(), (result | target_mask).to_ulong() };
    };

    auto const a = forward();
    auto const b = backward();

    std::cout << a.expression << ' ' << a.mask << '\n';
    std::cout << b.expression << ' ' << b.mask << '\n';

    if (a.expression == b.expression)
    {
        return std::min(a.mask, b.mask);
    }

    if (a.expression > b.expression)
    {
        return a.mask;
    }

    return b.mask;
}

int main()
{
    while (true)
    {
        unsigned long target;
        unsigned long lower;
        unsigned long upper;
        std::cin >> target >> lower >> upper;

        if (std::cin.eof())
        {
            break;
        }

        std::cout << solve(target, lower, upper) << '\n';
    }
}
