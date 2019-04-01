#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cassert>

// This also works, except the reconstruction step is too slow

using Numbers = std::vector<int>;

using LisNode = std::vector<Numbers::const_iterator>;

using Lis = std::vector<LisNode>;

bool reconstruct(Lis const& lis, std::deque<Numbers::const_iterator>& result, std::size_t depth = 0)
{
    if (depth == lis.size())
    {
        return true;
    }

    auto const& node = lis[depth];
    for (auto i = node.crbegin(); i != node.crend(); ++i)
    {
        if (!result.empty() && *i < result.back())
        {
            return false;
        }

        result.push_back(*i);
        if (reconstruct(lis, result, depth + 1))
        {
            return true;
        }
        result.pop_back();
    }

    return false;
}

std::deque<Numbers::const_iterator> find_lis(Numbers const& numbers)
{
    Lis lis;

    for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
    {
        auto const j = std::lower_bound(lis.begin(), lis.end(), *i,
            [](LisNode const& left, int right)
            {
                return *left.back() < right;
            }
        );

        if (j == lis.end())
        {
            lis.push_back(LisNode{ i });
            continue;
        }

        j->push_back(i);
    }

    std::deque<Numbers::const_iterator> result;
    if (reconstruct(lis, result))
    {
        return result;
    }

    std::cout << "IMPOSSIBLE\n";
    std::cout << "IMPOSSIBLE\n";
    std::cout << "IMPOSSIBLE\n";

    return {};
}

void solve(Numbers const& numbers)
{
    auto const lis = find_lis(numbers);
    std::cout << lis.size() << "\n-\n";
    for (auto const n : lis)
    {
        std::cout << *n << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // std::cout << find_lis(Numbers{ 19, -1, 1, 17, 3, -17, 13, 3, -18, 9, 12, -20, 8 }) << '\n';
    // std::cout << find_lis(Numbers{ -7, 10, 9, 2, 3, 8, 8, 6, 1, 2, 3 }) << '\n';

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
