#include <iostream>
#include <cstddef>
#include <limits>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint32_t num_cases;
    std::cin >> num_cases;
    for (std::uint32_t i = 0; i < num_cases; ++i)
    {
        std::uint32_t num_bits;
        std::uint32_t decimal_value;
        std::cin >> num_bits >> decimal_value;
        std::uint32_t const mask = std::numeric_limits<std::uint32_t>::max() >> (32 - num_bits);
        std::cout << (((decimal_value >> 1) ^ decimal_value) & mask) << '\n';
    }
}
