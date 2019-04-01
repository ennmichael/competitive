#include <iostream>
#include <vector>
#include <algorithm>

// Finding a longest strictly decreasing subsequence

using Numbers = std::vector<int>;

using Minimums = std::vector<std::size_t>;

using PredecessorTable = std::vector<long long>;

PredecessorTable empty_predecessor_table()
{
    return PredecessorTable(1000, -1);
}

std::vector<int> reconstruct_in_reverse(
    Numbers const& numbers, Minimums const& minimums, PredecessorTable const& predecessor_table)
{
    std::size_t current = minimums.back();
    std::vector<int> result { numbers[current] };

    while (predecessor_table[current] != -1)
    {
        current = predecessor_table[current];
        result.push_back(numbers[current]);
    }

    return result;
}

std::vector<int> find_lds(Numbers const& numbers)
{
    Minimums minimums { 0 };
    auto predecessor_table = empty_predecessor_table();

    for (std::size_t i = 1; i < numbers.size(); ++i)
    {
        auto j = std::lower_bound(minimums.begin(), minimums.end(), numbers[i],
            [&](std::size_t left, int right)
            {
                return numbers[left] > right;
            }
        );

        if (j != minimums.begin())
        {
            predecessor_table[i] = *(j - 1);
        }

        if (j == minimums.end())
        {
            minimums.push_back(i);
        }
        else
        {
            *j = i;
        }
    }

    return reconstruct_in_reverse(numbers, minimums, predecessor_table);
}

int main()
{
    auto const lds = find_lds({ -7, 10, 9, 2, 3, 8, 8, 6 });
    for (auto const n : lds)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
