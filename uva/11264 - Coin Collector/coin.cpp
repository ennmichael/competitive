#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>

using Coins = std::vector<long>;

long count_coins(Coins const& coins, long money)
{
    long count = 0;

    for (auto coin = coins.crbegin(); coin != coins.crend(); ++coin)
    {
        if (*coin > money)
        {
            continue;
        }

        while (*coin <= money && money > 0)
        {
            money -= *coin;
        }

        ++count;
    }

    return count;
}

long solve(Coins const& coins)
{
    long num_coins = 0;
    long money = 0;

    for (auto coin = coins.crbegin(); coin != coins.crend(); ++coin)
    {
        money += *coin;
        num_coins = std::max(num_coins, count_coins(coins, money));
    }

    return num_coins;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_test_cases;
    std::cin >> num_test_cases;

    for (int test_case = 0; test_case < num_test_cases; ++test_case)
    {
        int num_coins;
        std::cin >> num_coins;
        Coins coins(num_coins);

        for (auto& coin : coins)
        {
            std::cin >> coin;
        }

        std::cout << solve(coins) << '\n';
    }
}
