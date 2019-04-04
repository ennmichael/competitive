#include <iostream>
#include <cmath>
#include <vector>
#include <array>

struct Item {
    int price;
    int favour;
};

using Items = std::vector<Item>;

using DP = std::array<std::array<int, 10005>, 105>;

int solve(std::size_t i, int money, Items const& items, DP& dp, int starting_money)
{
    if (i == items.size())
    {
        return 0;
    }

    if (dp[i][money] != -1)
    {
        return dp[i][money];
    }

    if (money <= -200)
    {
        return 0;
    }

    if (money < 0)
    {
        money += 200;
    }

    auto const favour_when_skipping = solve(i + 1, money, items, dp, starting_money);

    if (money + 200 < items[i].price)
    {
        return favour_when_skipping;
    }

    auto const favour_when_taking = items[i].favour + solve(i + 1, money - items[i].price, items, dp, starting_money);

    return dp[i][money] = std::max(favour_when_skipping, favour_when_taking);
}

DP empty_dp()
{
    DP dp;

    for (auto& row : dp)
    {
        for (auto& e : row)
        {
            e = -1;
        }
    }

    return dp;
}

int main()
{
    while (true)
    {
        int money;
        std::size_t num_items;
        std::cin >> money >> num_items;

        if (std::cin.eof())
        {
            break;
        }

        Items items(num_items);

        for (auto& item : items)
        {
            std::cin >> item.price >> item.favour;
        }

        auto dp = empty_dp();

        std::cout << solve(0, money, items, dp, money) << '\n';
    }
}
