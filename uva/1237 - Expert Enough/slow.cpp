#include <iostream>
#include <vector>
#include <array>
#include <cstdint>
#include <cmath>

// Using complete search

using Name = std::array<char, 22>;

struct Entry {
    Name name;
    std::uint32_t min;
    std::uint32_t max;

    bool contains(std::uint32_t value) const
    {
        return min <= value && value <= max;
    }
};

using Entries = std::vector<Entry>;

Name solve_query(Entries const& entries, std::uint32_t query)
{
    Name result {{ '\0' }};
    for (auto const& entry : entries)
    {
        if (!entry.contains(query))
        {
            continue;
        }

        if (result[0] == '\0')
        {
            result = entry.name;
        }
        else
        {
            return Name {{ '\0' }};
        }
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i)
    {
        int num_entries;
        std::cin >> num_entries;
        Entries entries(num_entries);
        for (auto& entry : entries)
        {
            std::cin >> entry.name.data() >> entry.min >> entry.max;
        }
        
        int num_queries;
        std::cin >> num_queries;
        for (int j = 0; j < num_queries; ++j)
        {
            std::uint32_t query;
            std::cin >> query;
            auto const result = solve_query(entries, query);
            if (result[0] == '\0')
            {
                std::cout << "UNDETERMINED\n";
            }
            else
            {
                std::cout << result.data() << '\n';
            }
        }

        if (i != num_test_cases - 1)
        {
            std::cout << '\n';
        }
    }
}
