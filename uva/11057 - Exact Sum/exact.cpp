#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <utility>

using Prices = std::vector<long>;

std::pair<long, long> solve(Prices& prices, long money)
{
    std::sort(prices.begin(), prices.end());

    std::pair<long, long> result;
    auto left = prices.cbegin();
    auto right = prices.cend() - 1;

    while (left != right)
    {
        auto const sum = *left + *right;

        if (sum == money)
        {
            result = { *left, *right };
            ++left;
            continue;
        }

        if (sum > money)
        {
            --right;
        }
        else
        {
            ++left;
        }
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int test_case = 0; ; ++test_case)
    {
        std::size_t num_books;
        std::cin >> num_books;

        if (std::cin.eof())
        {
            break;
        }

        Prices prices(num_books);

        for (auto& price : prices)
        {
            std::cin >> price;
        }
        
        long money;
        std::cin >> money;
        auto const solution = solve(prices, money);
        std::cout << "Peter should buy books whose prices are " << solution.first << " and " << solution.second << ".\n\n";
    }
}
