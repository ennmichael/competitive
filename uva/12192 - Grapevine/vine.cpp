#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cmath>

using Row = std::vector<std::uint32_t>;

using Column = std::vector<std::uint32_t>;

using Plane = std::vector<Row>;

Column get_column(Plane const& plane, std::size_t column_index)
{
    Column column;
    column.reserve(plane.size());
    for (auto const& row : plane)
    {
        column.push_back(row[column_index]);
    }
    return column;
}

std::uint32_t solve(Plane const& plane, std::uint32_t lower, std::uint32_t upper)
{
    auto const& first_row = plane.front();
    auto const starting_column_index = std::lower_bound(first_row.cbegin(), first_row.cend(), lower) - first_row.cbegin();
    auto const starting_column = get_column(plane, starting_column_index);
    auto const starting_row_index =
        std::lower_bound(starting_column.cbegin(), starting_column.cend(), lower) - starting_column.cbegin();

    auto const& last_row = plane.back();
    auto const ending_column_index = std::upper_bound(last_row.cbegin(), last_row.cend(), upper) - last_row.cbegin();
    auto const ending_column = get_column(plane, ending_column_index);
    auto const ending_row_index =
        std::lower_bound(ending_column.cbegin(), ending_column.cend(), upper) - ending_column.cbegin();

    return std::min(ending_row_index - starting_row_index, ending_column_index - starting_column_index);
}

int main()
{
    while (true)
    {
        std::size_t height;
        std::size_t width;
        std::cin >> height >> width;

        if (height == 0 && width == 0)
        {
            break;
        }

        Plane plane(height, Row(width));
        for (auto& row : plane)
        {
            for (auto& property : row)
            {
                std::cin >> property;
            }
        }

        std::uint32_t num_queries;
        std::cin >> num_queries;
        for (std::uint32_t i = 0; i < num_queries; ++i)
        {
            std::uint32_t lower;
            std::uint32_t upper;
            std::cin >> lower >> upper;
            std::cout << solve(plane, lower, upper) << '\n';
        }
    }
}
