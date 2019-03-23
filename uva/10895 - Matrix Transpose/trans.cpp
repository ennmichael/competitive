#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

struct Edge {
    std::size_t row;
    std::size_t column;
    std::int32_t value;

    void transpose()
    {
        std::swap(row, column);
    }
};

struct Matrix {
    std::size_t width;
    std::size_t height;
    std::vector<Edge> edges;

    void transpose()
    {
        std::swap(width, height);
        for (auto& edge : edges)
        {
            edge.transpose();
        }
    }

    bool input()
    {
        std::cin >> height;
        if (std::cin.eof())
        {
            return false;
        }
        std::cin >> width;
        for (std::size_t row = 1; row <= height; ++row)
        {
            std::size_t num_entries;
            std::cin >> num_entries;
            if (num_entries == 0)
            {
                continue;
            }
            std::vector<std::size_t> columns(num_entries);
            for (auto& column : columns)
            {
                std::cin >> column;
            }
            for (auto const column : columns)
            {
                std::int32_t value;
                std::cin >> value;
                edges.push_back(Edge{ row, column, value });
            }
        }
        return true;
    }

    void output()
    {
        std::cout << height << ' ' << width << '\n';
        std::sort(edges.begin(), edges.end(),
            [](Edge const& left, Edge const& right)
            {
                if (left.row == right.row)
                {
                    return left.column < right.column;
                }
                return left.row < right.row;
            }
        );
        auto i = edges.cbegin();
        auto const end_row = (i == edges.cend()) ? height + 1 : i->row;
        for (std::size_t row = 1; row < end_row; ++row)
        {
            std::cout << "0\n\n";
        }
        if (i == edges.cend())
        {
            return;
        }
        do {
            auto const j = std::find_if(i, edges.cend(), [&](Edge const& edge) { return edge.row != i->row; });
            std::cout << std::distance(i, j) << ' ';
            for (auto k = i; k != j; ++k)
            {
                if (k == j - 1)
                {
                    std::cout << k->column;
                    continue;
                }
                std::cout << k->column << ' ';
            }
            std::cout << '\n';
            for (auto k = i; k != j; ++k)
            {
                if (k == j - 1)
                {
                    std::cout << k->value;
                    continue;
                }
                std::cout << k->value << ' ';
            }
            std::cout << '\n';
            auto const new_row = (j == edges.cend()) ? height + 1 : j->row;
            for (std::size_t row = i->row + 1; row < new_row; ++row)
            {
                std::cout << "0\n\n";
            }
            i = j;
        } while (i != edges.cend());
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        Matrix matrix;
        if (!matrix.input())
        {
            break;
        }
        if (matrix.width == 0 || matrix.height == 0)
        {
            std::cout << matrix.width << ' ' << matrix.height << '\n';
            return 0;
        }
        matrix.transpose();
        matrix.output();
    }
}
