#include <iostream>
#include <cmath>
#include <vector>
#include <cstddef>
#include <array>
#include <limits>
#include <climits>

struct Corner {
    int weight;
    int potency = 0;
    std::vector<int> neighbours;

    void set_neighbours(int num_dimensions, int index)
    {
        int mask = 1;
        neighbours.resize(num_dimensions);
        for (int i = 0; i < num_dimensions; ++i)
        {
            neighbours[i] = index ^ mask;
            mask <<= 1;
        }
    }
};

using Corners = std::vector<Corner>;

void update_potencies(Corners& corners)
{
    for (auto& corner : corners)
    {
        for (auto const neighbour : corner.neighbours)
        {
            corner.potency += corners[neighbour].weight;
        }
    }
}

int max_potencies_sum(Corners const& corners)
{
    int result = 0;
    for (auto const& corner : corners)
    {
        for (auto const neighbour : corner.neighbours)
        {
            result = std::max(result, corner.potency + corners[neighbour].potency);
        }
    }
    return result;
}

int solve(Corners& corners)
{
    update_potencies(corners);
    return max_potencies_sum(corners);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        int num_dimensions;
        std::cin >> num_dimensions;

        if (std::cin.eof())
        {
            break;
        }

        int const max_index = 1 << num_dimensions;
        Corners corners(max_index);
        for (int i = 0; i < max_index; ++i)
        {
            std::cin >> corners[i].weight;
            corners[i].set_neighbours(num_dimensions, i);
        }

        std::cout << solve(corners) << '\n';
    }
}
