#include <iostream>
#include <cstddef>
#include <limits>

void solve(std::int64_t number)
{
    int bit_counter = 0;

    std::int64_t a = 0;
    std::int64_t b = 0;
    
    while (number != 0)
    {
        std::int64_t const rightmost_bit = (~(number ^ (-number))) & std::numeric_limits<std::int64_t>::max();
        if (bit_counter % 2 == 0)
        {
            a |= rightmost_bit;
        }
        else
        {
            b |= rightmost_bit;
        }
        number ^= rightmost_bit;
        ++bit_counter;
    }

    if (bit_counter % 2 == 0)
    {
        std::cout << a << ' ' << b << '\n';
    }
    else
    {
        std::cout << b << ' ' << a << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::int64_t number;
        std::cin >> number;
        if (number == 0)
        {
            break;
        }
        solve(number);
    }
}
