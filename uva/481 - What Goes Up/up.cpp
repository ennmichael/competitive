#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using Numbers = std::vector<int>;

using Lis = std::vector<std::size_t>;

using Predecessors = std::unordered_map<std::size_t, std::size_t>;

std::vector<int> reconstruct_reverse(Numbers const& numbers, Lis const& lis, Predecessors const& predecessors)
{
    auto current = lis.back();
    std::vector<int> result { numbers[current] };

    while (predecessors.count(current))
    {
        current = predecessors.at(current);
        result.push_back(numbers[current]);
    }

    return result;
}

std::vector<int> find_lis(Numbers const& numbers)
{
    Lis lis { 0 };
    Predecessors predecessors;

    for (std::size_t i = 1; i < numbers.size(); ++i)
    {
        auto j = std::lower_bound(lis.begin(), lis.end(), numbers[i],
            [&](std::size_t left, int right)
            {
                return numbers[left] < right;
            }
        );

        if (j == lis.end())
        {
            predecessors.emplace(i, *(j - 1));
            lis.push_back(i);
        }
        else
        {
            *j = i;
            if (j != lis.begin())
            {
                predecessors.emplace(i, *(j - 1));
            }
        }
    }

    return reconstruct_reverse(numbers, lis, predecessors);
}

void solve(Numbers const& numbers)
{
    auto const lis = find_lis(numbers);
    std::cout << lis.size() << "\n-\n";
    for (auto i = lis.crbegin(); i != lis.crend(); ++i)
    {
        std::cout << *i << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Numbers numbers;

    while (true)
    {
        int i;
        std::cin >> i;

        if (std::cin.eof())
        {
            break;
        }

        numbers.push_back(i);
    }

    solve(numbers);
}
