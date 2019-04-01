#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <unordered_map>
#include <limits>

struct Building {
    int height;
    int width;
};

using Buildings = std::vector<Building>;

using Minimums = std::vector<std::size_t>;

using WidthTable = std::unordered_map<std::size_t, int>;

template <class Compare>
int find_longest_width(Buildings const& buildings, Compare const& compare)
{
    Minimums minimums;
    WidthTable width_table;

    for (std::size_t building_index = 0; building_index < buildings.size(); ++building_index)
    {
        auto const& building = buildings[building_index];
        auto const minimum = std::lower_bound(minimums.begin(), minimums.end(), building.height,
            [&](std::size_t left, int right)
            {
                return compare(buildings[left].height, right);
            }
        );

        if (minimum == minimums.begin())
        {
            width_table.emplace(building_index, building.width);
        }
        else
        {
            width_table.emplace(building_index, building.width + width_table.at(*(minimum - 1)));
        }

        if (minimum == minimums.end())
        {
            minimums.push_back(building_index);
        }
        else
        {
            *minimum = building_index;
        }
    }

    return std::max_element(width_table.cbegin(), width_table.cend(),
        [](WidthTable::value_type const& left, WidthTable::value_type const& right)
        {
            return left.second < right.second;
        }
    )->second;
}

int find_longest_increasing_width(Buildings const& buildings)
{
    return find_longest_width(buildings, [](int left, int right) { return left < right; });
}

int find_longest_decreasing_width(Buildings const& buildings)
{
    return find_longest_width(buildings, [](int left, int right) { return left > right; });
}

void solve(Buildings const& buildings)
{
    auto const increasing = find_longest_increasing_width(buildings);
    auto const decreasing = find_longest_decreasing_width(buildings);

    if (increasing >= decreasing)
    {
        std::cout << "Increasing (" << increasing << "). Decreasing (" << decreasing << ").\n";
    }
    else
    {
        std::cout << "Decreasing (" << decreasing << "). Increasing (" << increasing << ").\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_test_cases;
    std::cin >> num_test_cases;

    for (int i = 1; i <= num_test_cases; ++i)
    {
        std::size_t num_buildings;
        std::cin >> num_buildings;

        Buildings buildings(num_buildings);

        for (auto& building : buildings)
        {
            std::cin >> building.height;
        }

        for (auto& building : buildings)
        {
            std::cin >> building.width;
        }

        std::cout << "Case " << i << ". ";
        solve(buildings);
    }
}
