#include <iostream>
#include <vector>
#include <cstddef>
#include <array>
#include <algorithm>

// The point of this one was to realize that transforming the matrix A
// into B can be achieved by first doing M (0 to 3) rotations and then N
// element changes. See how many element changes (N) you would need for
// any value of M (0, 1, 2 or 3) and select min(M + N).

using Matrix = std::vector<std::vector<unsigned long>>;

unsigned long difference(Matrix const& a, Matrix const& b) noexcept
{
    unsigned long counter = 0;
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        for (std::size_t j = 0; j < a.size(); ++j)
        {
            if (a[i][j] != b[i][j])
                ++counter;
        }
    }
    return counter;
}

unsigned long single_rotation_difference(Matrix const& a, Matrix const& b) noexcept
{
    unsigned long counter = 0;
    auto const q = a.size() - 1;
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        for (std::size_t j = 0; j < a.size(); ++j)
        {
            if (a[i][j] != b[j][q - i])
                ++counter;
        }
    }
    return counter;
}

unsigned long double_rotation_difference(Matrix const& a, Matrix const& b) noexcept
{
    unsigned long counter = 0;
    auto const q = a.size() - 1;
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        for (std::size_t j = 0; j < a.size(); ++j)
        {
            if (a[i][j] != b[q - i][q - j])
                ++counter;
        }
    }
    return counter;
}

unsigned long triple_rotation_difference(Matrix const& a, Matrix const& b) noexcept
{
    unsigned long counter = 0;
    auto const q = a.size() - 1;
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        for (std::size_t j = 0; j < a.size(); ++j)
        {
            if (a[i][j] != b[q - j][i])
                ++counter;
        }
    }
    return counter;
}

unsigned long min_operations(Matrix const& a, Matrix const& b) noexcept
{
    std::array<unsigned long, 4> const operations {
        difference(a, b),
        single_rotation_difference(a, b) + 1,
        double_rotation_difference(a, b) + 2,
        triple_rotation_difference(a, b) + 3,
    };
    return *std::min_element(operations.cbegin(), operations.cend());
}

Matrix load_matrix(unsigned long size) noexcept
{
    Matrix m;
    m.reserve(size);
    for (unsigned long i = 0; i < size; ++i)
    {
        std::vector<unsigned long> row;
        row.reserve(size);
        for (unsigned long j = 0; j < size; ++j)
        {
            unsigned long element;
            std::cin >> element;
            row.push_back(element);
        }
        m.push_back(row);
    }
    return m;
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    unsigned long size;
    std::cin >> size;
    auto const a = load_matrix(size);
    auto const b = load_matrix(size);
    std::cout << min_operations(a, b) << '\n';
}

