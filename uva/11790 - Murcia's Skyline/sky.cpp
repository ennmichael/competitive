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
long long find_j(Buildings const& buildings, std::vector<int> const& max_widths, std::size_t i, Compare const& compare)
{
    long long result = -1;
    int max_width = -1;

    for (std::size_t j = 0; j < i; ++j)
    {
        if (!compare(buildings[j].height, buildings[i].height))
        {
            continue;
        }

        if (max_widths[j] > max_width)
        {
            max_width = max_widths[j];
            result = j;
        }
    }

    return result;
}

template <class Compare>
int find_max_width(Buildings const& buildings, Compare const& compare)
{
    std::vector<int> max_widths(buildings.size());
    max_widths[0] = buildings.front().width;

    for (std::size_t i = 1; i < buildings.size(); ++i)
    {
        auto const j = find_j(buildings, max_widths, i, compare);
        if (j == -1)
        {
            max_widths[i] = buildings[i].width;
        }
        else
        {
            max_widths[i] = max_widths[j] + buildings[i].width;
        }
    }

    return *std::max_element(max_widths.cbegin(), max_widths.cend());
}

int find_increasing_width(Buildings const& buildings)
{
    return find_max_width(buildings, [](int left, int right) { return left < right; });
}

int find_decreasing_width(Buildings const& buildings)
{
    return find_max_width(buildings, [](int left, int right) { return left > right; });
}

void solve(Buildings const& buildings)
{
    auto const increasing = find_increasing_width(buildings);
    auto const decreasing = find_decreasing_width(buildings);

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
