#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstddef>

int solve(std::vector<int>& heads, std::deque<int>& knights)
{
    std::sort(heads.begin(), heads.end());
    std::sort(knights.begin(), knights.end());

    int gold = 0;

    for (auto const head : heads)
    {
        auto const knight = std::lower_bound(knights.cbegin(), knights.cend(), head);

        if (knight == knights.cend())
        {
            return -1;
        }

        gold += *knight;
        knights.erase(knight);
    }

    return gold;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t num_heads;
        std::size_t num_knights;
        std::cin >> num_heads >> num_knights;

        if (num_heads == 0 && num_knights == 0)
        {
            break;
        }

        std::vector<int> heads(num_heads);
        std::deque<int> knights(num_knights);

        for (auto& head : heads)
        {
            std::cin >> head;
        }

        for (auto& knight : knights)
        {
            std::cin >> knight;
        }

        auto const gold = solve(heads, knights);
        if (gold == -1)
        {
            std::cout << "Loowater is doomed!\n";
        }
        else
        {
            std::cout << gold << '\n';
        }
    }
}
