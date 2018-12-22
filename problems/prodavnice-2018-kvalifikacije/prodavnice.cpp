#include <cmath>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

struct Plan {
    Plan(long c, long d)
    {
        if (c < d)
        {
            a = c;
            b = d;
        }
        else
        {
            a = d;
            b = c;
        }
    }

    long a;
    long b;
};

using Houses = std::vector<long>;

long overall_distance(Houses const& houses, Plan const plan) noexcept
{
    auto const middle = std::upper_bound(houses.cbegin(), houses.cend(), (plan.a + plan.b) / 2);
    long sum = 0;
    for (auto i = houses.cbegin(); i != middle; ++i)
        sum += std::abs(plan.a - *i);
    for (auto i = middle; i != houses.cend(); ++i)
        sum += std::abs(plan.b - *i);
    return sum;
}

Houses load_houses(unsigned long num_houses) noexcept
{
    Houses houses(num_houses);
    for (std::size_t i = 0; i < num_houses; ++i)
        std::cin >> houses[i];
    std::sort(houses.begin(), houses.end());
    return houses;
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    unsigned long num_houses;
    unsigned long num_plans;
    std::cin >> num_houses;
    std::cin >> num_plans;
    auto const houses = load_houses(num_houses);
    for (unsigned long i = 0; i < num_plans; ++i)
    {
        long c;
        long d;
        std::cin >> c;
        std::cin >> d;
        Plan plan {c, d};
        std::cout << overall_distance(houses, plan) << '\n';
    }
}

