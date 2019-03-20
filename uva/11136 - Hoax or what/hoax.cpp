#include <iostream>
#include <cstddef>
#include <set>

std::uint32_t solve_day(std::multiset<std::uint32_t>& bills)
{
    auto const begin = bills.begin();
    auto end = bills.end();
    --end;
    auto const last = *end;
    auto const result = last - *begin;
    bills.erase(begin);
    bills.erase(last);
    return result;
}

int main()
{
    while (true)
    {
        std::uint32_t result = 0;
        std::uint32_t num_days;
        std::cin >> num_days;
        if (num_days == 0)
        {
            break;
        }
        std::multiset<std::uint32_t> bills;
        for (std::uint32_t day = 0; day < num_days; ++day)
        {
            std::uint32_t num_bills;
            std::cin >> num_bills;
            for (std::uint32_t i = 0; i < num_bills; ++i)
            {
                std::uint32_t bill;
                std::cin >> bill;
                bills.insert(bill);
            }
            result += solve_day(bills);
        }
        std::cout << result << '\n';
    }
}
