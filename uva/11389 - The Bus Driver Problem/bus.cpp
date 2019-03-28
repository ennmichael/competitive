#include <iostream>
#include <vector>
#include <algorithm>

using Routes = std::vector<int>;

int solve(Routes& day_routes, Routes& evening_routes, int daily_time, int overtime_rate)
{
    std::sort(day_routes.begin(), day_routes.end());
    std::sort(evening_routes.begin(), evening_routes.end());

    auto i = day_routes.cbegin();
    auto j = evening_routes.crbegin();
    int overtime = 0;

    while (i != day_routes.cend() && j != evening_routes.crend())
    {
        overtime += std::max(0, *i + *j - daily_time);

        ++i;
        ++j;
    }

    return overtime * overtime_rate;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        int num_routes;
        int daily_time;
        int overtime_rate;
        std::cin >> num_routes >> daily_time >> overtime_rate;

        if (num_routes == 0 && daily_time == 0 && overtime_rate == 0)
        {
            break;
        }

        Routes day_routes(num_routes);
        Routes evening_routes(num_routes);

        for (auto& route : day_routes)
        {
            std::cin >> route;
        }

        for (auto& route : evening_routes)
        {
            std::cin >> route;
        }

        std::cout << solve(day_routes, evening_routes, daily_time, overtime_rate) << '\n';
    }
}
