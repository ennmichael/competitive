#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using Row = std::vector<long>;

using Matrix = std::vector<Row>;

void make_torus(Matrix& matrix, std::size_t dimensions)
{
    for (std::size_t row = 0; row < dimensions - 1; ++row)
    {
        for (std::size_t column = 0; column < dimensions - 1; ++column)
        {
            auto const n = matrix[row][column];
            matrix[row + dimensions][column] = n;
            matrix[row][column + dimensions] = n;
            matrix[row + dimensions][column + dimensions] = n;
        }
    }
}

void preprocess(Matrix& matrix)
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
}

long solve(Matrix& matrix, std::size_t dimensions)
{
    long result = std::numeric_limits<long>::min();

    make_torus(matrix, dimensions);
    preprocess(matrix);

    auto const find_min = [&](std::size_t starting_row, std::size_t starting_column,
                              std::size_t ending_row, std::size_t ending_column)
    {
        long min = std::numeric_limits<long>::max();

        for (std::size_t row = starting_row; row <= ending_row; ++row)
        {
            for (std::size_t column = starting_column; column <= ending_column; ++column)
            {
                if (row == ending_row && column == ending_column)
                {
                    break;
                }
                if (row == ending_row || column == ending_column)
                {
                    if (matrix[row][column] < min)
                        std::cout << "Start " << row << ' ' << column << '\n';
                    min = std::min(min, matrix[row][column]);
                }
                else
                {
                    if (matrix[row][ending_column] + matrix[ending_row][column] - matrix[row][column] < min)
                        std::cout << "Start " << row << ' ' << column << '\n';
                    min = std::min(min, matrix[row][ending_column] + matrix[ending_row][column] - matrix[row][column]);
                }
            }
        }

        return min;
    };

    auto const solve_sub = [&](std::size_t starting_row, std::size_t starting_column)
    {
        long sub_result = std::numeric_limits<long>::min();

        for (std::size_t row = starting_row; row < starting_row + dimensions; ++row)
        {
            for (std::size_t column = starting_column; column < starting_column + dimensions; ++column)
            {
                auto const min = find_min(starting_row, starting_column, row, column);

                if (min < 0)
                {
                    if (matrix[row][column] - min > sub_result)
                        std::cout << "End " << row << ' ' << column << '\n';
                    sub_result = std::max(sub_result, matrix[row][column] - min);
                    continue;
                }

                if (matrix[row][column] > sub_result)
                    std::cout << "End " << row << ' ' << column << '\n';
                sub_result = std::max(sub_result, matrix[row][column]);
            }
        }

        if (starting_row == 0 && starting_column == 0)
        {
            return sub_result;
        }

        if (starting_row == 0)
        {
            return sub_result - matrix[0][starting_column - 1];
        }

        if (starting_column == 0)
        {
            return sub_result - matrix[starting_row - 1][0];
        }

        return sub_result -
               matrix[starting_row][starting_column + dimensions - 1] -
               matrix[starting_row + dimensions - 1][starting_column] +
               matrix[starting_row][starting_column];
    };

    for (std::size_t starting_row = 0; starting_row < dimensions; ++starting_row)
    {
        for (std::size_t starting_column = 0; starting_column < dimensions; ++starting_column)
        {
            result = std::max(result, solve_sub(starting_row, starting_column));
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
        std::size_t dimensions;
        std::cin >> dimensions;
        Matrix matrix(2 * dimensions - 1, Row(2 * dimensions - 1));

        for (std::size_t row = 0; row < dimensions; ++row)
        {
            for (std::size_t column = 0; column < dimensions; ++column)
            {
                std::cin >> matrix[row][column];
            }
        }

        std::cout << solve(matrix, dimensions) << '\n';
    }
}
