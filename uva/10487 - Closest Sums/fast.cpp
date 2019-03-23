#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <cmath>

using Numbers = std::vector<std::int64_t>;

void solve_query(Numbers const& numbers, std::int64_t query)
{
    auto i = numbers.cbegin();
    auto j = numbers.cend() - 1;

    std::int64_t solution = *i + *j;
    std::int64_t min_difference = std::numeric_limits<std::int64_t>::max();

    while (true)
    {
        if (solution == query)
        {
            break;
        }

        if (solution < query)
        {
            ++i;
        }
        else
        {
            --j;
        }

        if (i == j)
        {
            break;
        }

        auto const new_solution = *i + *j;
        std::int64_t new_difference = std::abs(query - new_solution);

        if (new_difference < min_difference)
        {
            solution = new_solution;
            min_difference = new_difference;
        }
    }

    std::cout << "Closest sum to " << query << " is " << solution << ".\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint64_t num_case = 0;
    while (true)
    {
        ++num_case;
        std::uint64_t num_numbers;
        std::cin >> num_numbers;
        if (num_numbers == 0)
        {
            break;
        }

        Numbers numbers(num_numbers);
        for (auto& n : numbers)
        {
            std::cin >> n;
        }

        std::sort(numbers.begin(), numbers.end());

        std::cout << "Case " << num_case << ":\n";

        std::uint64_t num_queries;
        std::cin >> num_queries;
        for (std::uint64_t i = 0; i < num_queries; ++i)
        {
            std::int64_t query;
            std::cin >> query;
            solve_query(numbers, query);
        }
    }
}
