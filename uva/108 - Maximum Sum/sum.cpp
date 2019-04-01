#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using Int = long long;

using Row = std::vector<Int>;

using Matrix = std::vector<Row>;

Int solve(Matrix& matrix)
{
    auto const preprocess = [&]
    {
        for (auto& row : matrix)
        {
            for (auto i = row.begin() + 1; i != row.end(); ++i)
            {
                *i += *(i - 1);
            }
        }

        for (std::size_t column = 0; column < matrix.back().size(); ++column)
        {
            for (std::size_t row = 1; row < matrix.size(); ++row)
            {
                matrix[row][column] += matrix[row - 1][column];
            }
        }
    };

    auto const find_min = [&](std::size_t max_row, std::size_t max_column)
    {
        Int result = std::numeric_limits<Int>::max();

        for (std::size_t row = 0; row <= max_row; ++row)
        {
            for (std::size_t column = 0; column <= max_column; ++column)
            {
                Int q;

                if (row != max_row && column != max_column)
                {
                    q = matrix[max_row][column] + matrix[row][max_column] - matrix[row][column];
                }
                else if (row == max_row && column == max_column)
                {
                    break;
                }
                else
                {
                    q = matrix[row][column];
                }

                result = std::min(result, q);
            }
        }

        return result;
    };

    preprocess();

    Int result = matrix[0][0];

    for (std::size_t row = 0; row < matrix.size(); ++row)
    {
        for (std::size_t column = 1; column < matrix[row].size(); ++column)
        {
            auto const n = matrix[row][column];
            auto const m = find_min(row, column);

            if (m < 0 && m != n)
            {
                result = std::max(result, n - m);
            }
            else
            {
                result = std::max(result, n);
            }
        }
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t dimensions;
        std::cin >> dimensions;

        if (std::cin.eof())
        {
            break;
        }

        Matrix matrix(dimensions, Row(dimensions));

        for (auto& row : matrix)
        {
            for (auto& e : row)
            {
                std::cin >> e;
            }
        }

        std::cout << solve(matrix) << '\n';
    }
}
