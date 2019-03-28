#include <iostream>
#include <array>
#include <cstddef>
#include <algorithm>
#include <vector>

using Column = std::array<char, 6>;

using Grid = std::array<Column, 5>;

using Options = std::array<std::vector<char>, 5>;

Grid load_grid()
{
    Grid grid;

    for (std::size_t row = 0; row < grid[0].size(); ++row)
    {
        for (std::size_t column = 0; column < grid.size(); ++column)
        {
            std::cin >> grid[column][row];
        }
    }

    return grid;
}

void sort_grid(Grid& grid)
{
    for (auto& column : grid)
    {
        std::sort(column.begin(), column.end());
    }
}

struct Problem {
    Grid first_grid;
    Grid second_grid;
    Options options;
    std::array<char, 6> solution {{}};

    void input()
    {
        first_grid = load_grid();
        second_grid = load_grid();
    }

    void build_options()
    {
        sort_grid(first_grid);
        sort_grid(second_grid);

        for (int column = 0; column < 5; ++column)
        {
            auto const& first_column = first_grid[column];
            auto const& second_column = second_grid[column];
            auto i = first_column.cbegin();
            auto j = second_column.cbegin();

            while (i != first_column.cend() && j != second_column.cend())
            {
                if (*i == *j)
                {
                    if (options[column].size() == 0 || options[column].back() != *i)
                    {
                        options[column].push_back(*i);
                    }
                    ++i;
                    ++j;
                    continue;
                }
                
                if (*i < *j)
                {
                    ++i;
                    continue;
                }

                ++j;
            }
        }
    }

    bool solve(unsigned k)
    {
        build_options();

        for (int i = 4; i >= 0; --i)
        {
            if (options[i].size() == 0)
            {
                return false;
            }

            if (i != 0)
            {
                auto const n = k / options[i].size();
                auto const o = k - n * options[i].size();
                solution[i] = options[i][o];
                k = n;
                continue;
            }

            if (k >= options[i].size())
            {
                return false;
            }

            solution[i] = options[i][k];
        }

        return true;
    }

    void output()
    {
        std::cout << solution.data() << '\n';
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t num_test_cases;
    std::cin >> num_test_cases;

    for (std::size_t i = 0; i < num_test_cases; ++i)
    {
        unsigned k;
        std::cin >> k;
        --k;
        Problem problem;
        problem.input();
        if (problem.solve(k))
        {
            problem.output();
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}
