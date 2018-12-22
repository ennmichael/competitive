#include <array>
#include <iostream>

std::size_t constexpr small_matrix_rows = 2;

std::size_t constexpr small_matrix_columns = 3;

using SmallMatrix = std::array<std::array<long long, small_matrix_columns>, small_matrix_rows>;

int count_zeros(SmallMatrix const& m) noexcept
{
    int count = 0;
    if (m[0][0] == 0)
        ++count;
    if (m[1][0] == 0)
        ++count;
    if (m[0][2] == 0)
        ++count;
    if (m[1][2] == 0)
        ++count;
    return count;
}

int larger_column(SmallMatrix const& m) noexcept
{
    auto const zero_sum = m[0][0] + m[1][0];
    auto const two_sum = m[0][2] + m[1][2];
    return (zero_sum >= two_sum) ? 0 : 2;
}

bool fill_in_the_blanks(SmallMatrix& m) noexcept
{
    if (m[0][1] == 0)
        m[0][1] = 1;
    if (m[1][1] == 0)
        m[1][1] = 1;

    if (m[0][0] == 0 && m[1][0] == 0)
        m[0][0] = 1;
    if (m[0][2] == 0 && m[1][2] == 0)
        m[0][2] = 1;

    if (count_zeros(m) == 2)
    {
        auto const c = larger_column(m);
        auto const r = (m[0][c] == 0) ? 0 : 1;
        m[r][c] = 1;
    }

    if (m[0][0] == 0)
    {
        if (m[0][0] + m[1][0] >= m[0][2] + m[1][2])
            return false;
        m[0][0] = m[0][2] + m[1][2] - m[1][0];
    }
    else if (m[1][0] == 0)
    {
        if (m[0][0] + m[1][0] >= m[0][2] + m[1][2])
            return false;
        m[1][0] = m[0][2] + m[1][2] - m[0][0];
    }
    else if (m[0][2] == 0)
    {
        if (m[0][0] + m[1][0] <= m[0][2] + m[1][2])
            return false;
        m[0][2] = m[0][0] + m[1][0] - m[1][2];
    }
    else if (m[1][2] == 0)
    {
        if (m[0][0] + m[1][0] <= m[0][2] + m[1][2])
            return false;
        m[1][2] = m[0][0] + m[1][0] - m[0][2];
    }
    else
    {
        if (m[0][0] + m[1][0] != m[0][2] + m[1][2])
            return false;
    }

    return true;
}

SmallMatrix load_matrix() noexcept
{
    SmallMatrix m;
    for (std::size_t i = 0; i < small_matrix_rows; ++i)
    {
        for (std::size_t j = 0; j < small_matrix_columns; ++j)
            std::cin >> m[i][j];
    }
    return m;
}

void print_matrix(SmallMatrix const& m) noexcept
{
    for (auto const& row : m)
    {
        for (auto const e : row)
            std::cout << e << ' ';
        std::cout << '\n';
    }
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    auto m = load_matrix();
    if (fill_in_the_blanks(m))
        print_matrix(m);
    else
        std::cout << -1 << '\n';
}

