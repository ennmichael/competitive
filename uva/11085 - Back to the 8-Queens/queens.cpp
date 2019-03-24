#include <iostream>
#include <cstdint>
#include <array>
#include <cmath>

using Configuration = std::array<int, 8>;

std::array<Configuration, 92> constexpr valid_configurations {{
    Configuration {{ 0, 4, 7, 5, 2, 6, 1, 3, }},
    Configuration {{ 0, 5, 7, 2, 6, 3, 1, 4, }},
    Configuration {{ 0, 6, 3, 5, 7, 1, 4, 2, }},
    Configuration {{ 0, 6, 4, 7, 1, 3, 5, 2, }},
    Configuration {{ 1, 3, 5, 7, 2, 0, 6, 4, }},
    Configuration {{ 1, 4, 6, 0, 2, 7, 5, 3, }},
    Configuration {{ 1, 4, 6, 3, 0, 7, 5, 2, }},
    Configuration {{ 1, 5, 0, 6, 3, 7, 2, 4, }},
    Configuration {{ 1, 5, 7, 2, 0, 3, 6, 4, }},
    Configuration {{ 1, 6, 2, 5, 7, 4, 0, 3, }},
    Configuration {{ 1, 6, 4, 7, 0, 3, 5, 2, }},
    Configuration {{ 1, 7, 5, 0, 2, 4, 6, 3, }},
    Configuration {{ 2, 0, 6, 4, 7, 1, 3, 5, }},
    Configuration {{ 2, 4, 1, 7, 0, 6, 3, 5, }},
    Configuration {{ 2, 4, 1, 7, 5, 3, 6, 0, }},
    Configuration {{ 2, 4, 6, 0, 3, 1, 7, 5, }},
    Configuration {{ 2, 4, 7, 3, 0, 6, 1, 5, }},
    Configuration {{ 2, 5, 1, 4, 7, 0, 6, 3, }},
    Configuration {{ 2, 5, 1, 6, 0, 3, 7, 4, }},
    Configuration {{ 2, 5, 1, 6, 4, 0, 7, 3, }},
    Configuration {{ 2, 5, 3, 0, 7, 4, 6, 1, }},
    Configuration {{ 2, 5, 3, 1, 7, 4, 6, 0, }},
    Configuration {{ 2, 5, 7, 0, 3, 6, 4, 1, }},
    Configuration {{ 2, 5, 7, 0, 4, 6, 1, 3, }},
    Configuration {{ 2, 5, 7, 1, 3, 0, 6, 4, }},
    Configuration {{ 2, 6, 1, 7, 4, 0, 3, 5, }},
    Configuration {{ 2, 6, 1, 7, 5, 3, 0, 4, }},
    Configuration {{ 2, 7, 3, 6, 0, 5, 1, 4, }},
    Configuration {{ 3, 0, 4, 7, 1, 6, 2, 5, }},
    Configuration {{ 3, 0, 4, 7, 5, 2, 6, 1, }},
    Configuration {{ 3, 1, 4, 7, 5, 0, 2, 6, }},
    Configuration {{ 3, 1, 6, 2, 5, 7, 0, 4, }},
    Configuration {{ 3, 1, 6, 2, 5, 7, 4, 0, }},
    Configuration {{ 3, 1, 6, 4, 0, 7, 5, 2, }},
    Configuration {{ 3, 1, 7, 4, 6, 0, 2, 5, }},
    Configuration {{ 3, 1, 7, 5, 0, 2, 4, 6, }},
    Configuration {{ 3, 5, 0, 4, 1, 7, 2, 6, }},
    Configuration {{ 3, 5, 7, 1, 6, 0, 2, 4, }},
    Configuration {{ 3, 5, 7, 2, 0, 6, 4, 1, }},
    Configuration {{ 3, 6, 0, 7, 4, 1, 5, 2, }},
    Configuration {{ 3, 6, 2, 7, 1, 4, 0, 5, }},
    Configuration {{ 3, 6, 4, 1, 5, 0, 2, 7, }},
    Configuration {{ 3, 6, 4, 2, 0, 5, 7, 1, }},
    Configuration {{ 3, 7, 0, 2, 5, 1, 6, 4, }},
    Configuration {{ 3, 7, 0, 4, 6, 1, 5, 2, }},
    Configuration {{ 3, 7, 4, 2, 0, 6, 1, 5, }},
    Configuration {{ 4, 0, 3, 5, 7, 1, 6, 2, }},
    Configuration {{ 4, 0, 7, 3, 1, 6, 2, 5, }},
    Configuration {{ 4, 0, 7, 5, 2, 6, 1, 3, }},
    Configuration {{ 4, 1, 3, 5, 7, 2, 0, 6, }},
    Configuration {{ 4, 1, 3, 6, 2, 7, 5, 0, }},
    Configuration {{ 4, 1, 5, 0, 6, 3, 7, 2, }},
    Configuration {{ 4, 1, 7, 0, 3, 6, 2, 5, }},
    Configuration {{ 4, 2, 0, 5, 7, 1, 3, 6, }},
    Configuration {{ 4, 2, 0, 6, 1, 7, 5, 3, }},
    Configuration {{ 4, 2, 7, 3, 6, 0, 5, 1, }},
    Configuration {{ 4, 6, 0, 2, 7, 5, 3, 1, }},
    Configuration {{ 4, 6, 0, 3, 1, 7, 5, 2, }},
    Configuration {{ 4, 6, 1, 3, 7, 0, 2, 5, }},
    Configuration {{ 4, 6, 1, 5, 2, 0, 3, 7, }},
    Configuration {{ 4, 6, 1, 5, 2, 0, 7, 3, }},
    Configuration {{ 4, 6, 3, 0, 2, 7, 5, 1, }},
    Configuration {{ 4, 7, 3, 0, 2, 5, 1, 6, }},
    Configuration {{ 4, 7, 3, 0, 6, 1, 5, 2, }},
    Configuration {{ 5, 0, 4, 1, 7, 2, 6, 3, }},
    Configuration {{ 5, 1, 6, 0, 2, 4, 7, 3, }},
    Configuration {{ 5, 1, 6, 0, 3, 7, 4, 2, }},
    Configuration {{ 5, 2, 0, 6, 4, 7, 1, 3, }},
    Configuration {{ 5, 2, 0, 7, 3, 1, 6, 4, }},
    Configuration {{ 5, 2, 0, 7, 4, 1, 3, 6, }},
    Configuration {{ 5, 2, 4, 6, 0, 3, 1, 7, }},
    Configuration {{ 5, 2, 4, 7, 0, 3, 1, 6, }},
    Configuration {{ 5, 2, 6, 1, 3, 7, 0, 4, }},
    Configuration {{ 5, 2, 6, 1, 7, 4, 0, 3, }},
    Configuration {{ 5, 2, 6, 3, 0, 7, 1, 4, }},
    Configuration {{ 5, 3, 0, 4, 7, 1, 6, 2, }},
    Configuration {{ 5, 3, 1, 7, 4, 6, 0, 2, }},
    Configuration {{ 5, 3, 6, 0, 2, 4, 1, 7, }},
    Configuration {{ 5, 3, 6, 0, 7, 1, 4, 2, }},
    Configuration {{ 5, 7, 1, 3, 0, 6, 4, 2, }},
    Configuration {{ 6, 0, 2, 7, 5, 3, 1, 4, }},
    Configuration {{ 6, 1, 3, 0, 7, 4, 2, 5, }},
    Configuration {{ 6, 1, 5, 2, 0, 3, 7, 4, }},
    Configuration {{ 6, 2, 0, 5, 7, 4, 1, 3, }},
    Configuration {{ 6, 2, 7, 1, 4, 0, 5, 3, }},
    Configuration {{ 6, 3, 1, 4, 7, 0, 2, 5, }},
    Configuration {{ 6, 3, 1, 7, 5, 0, 2, 4, }},
    Configuration {{ 6, 4, 2, 0, 5, 7, 1, 3, }},
    Configuration {{ 7, 1, 3, 0, 6, 4, 2, 5, }},
    Configuration {{ 7, 1, 4, 2, 0, 6, 3, 5, }},
    Configuration {{ 7, 2, 0, 5, 1, 4, 6, 3, }},
    Configuration {{ 7, 3, 0, 2, 5, 1, 6, 4, }},
}};

int solve(Configuration const& configuration)
{
    auto const operations_required = [&](Configuration const& valid_configuration)
    {
        int operations = 0;
        for (int column = 0; column < 8; ++column)
        {
            if (configuration[column] != valid_configuration[column])
            {
                ++operations;
            }
        }
        return operations;
    };

    int result = 10;
    for (auto const& valid_configuration : valid_configurations)
    {
        result = std::min(result, operations_required(valid_configuration));
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case = 0;
    while (true)
    {
        ++test_case;

        Configuration configuration;
        for (auto& row : configuration)
        {
            std::cin >> row;
            --row;
        }

        if (std::cin.eof())
        {
            break;
        }

        std::cout << "Case " << test_case << ": " << solve(configuration) << '\n';
    }
}
