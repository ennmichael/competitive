#include <iostream>
#include <cstddef>
#include <vector>
#include <unordered_set>
#include <cmath>

std::size_t solve(std::vector<std::uint32_t> const& snowflakes)
{
    std::unordered_set<std::uint32_t> snowflake_table;

    for (auto const flake : snowflakes)
    {
        auto const success = snowflake_table.insert(flake).second;
        if (!success)
        {
            break;
        }
    }

    return snowflake_table.size();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint32_t num_cases;
    std::cin >> num_cases;
    for (std::uint32_t i = 0; i < num_cases; ++i)
    {
        std::size_t num_snowflakes;
        std::cin >> num_snowflakes;
        std::vector<std::uint32_t> snowflakes(num_snowflakes);
        for (std::size_t j = 0; j < num_snowflakes; ++j)
        {
            std::cin >> snowflakes[j];
        }
        std::cout << solve(snowflakes) << '\n';
    }
}
