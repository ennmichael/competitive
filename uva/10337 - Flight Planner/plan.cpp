#include <iostream>
#include <array>
#include <limits>

auto constexpr inf = std::numeric_limits<int>::max() - 300;

using WindTable = std::array<std::array<int, 15>, 105>;

using DP = std::array<std::array<int, 15>, 105>;

DP empty_dp()
{
    DP dp;

    for (auto& row : dp)
    {
        for (auto& n : row)
        {
            n = inf;
        }
    }

    return dp;
}

int solve(DP& dp, WindTable const& wind_table, int distance, int altitude, int longitude)
{
    if (altitude > longitude || altitude < 0 || altitude > 9)
    {
        return inf;
    }

    if (altitude == 0 && longitude == 0)
    {
        return 0;
    }

    if (dp[altitude][longitude] != inf)
    {
        return dp[altitude][longitude];
    }

    int fuel = std::min(
        solve(dp, wind_table, distance, altitude, longitude - 1) + 30 - wind_table[altitude][longitude - 1],
        solve(dp, wind_table, distance, altitude + 1, longitude - 1) + 20 - wind_table[altitude + 1][longitude - 1]
    );

    if (altitude > 0)
    {
        fuel = std::min(
            fuel,
            solve(dp, wind_table, distance, altitude - 1, longitude - 1) + 60 - wind_table[altitude - 1][longitude - 1]
        );
    }

    dp[altitude][longitude] = fuel;

    return dp[altitude][longitude];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    std::cin >> test_cases;

    for (int i = 0; i < test_cases; ++i)
    {
        int distance;
        std::cin >> distance;
        distance /= 100;
        WindTable wind_table;

        for (int altitude = 9; altitude >= 0; --altitude)
        {
            for (int longitude = 0; longitude < distance; ++longitude)
            {
                std::cin >> wind_table[altitude][longitude];
            }
        }

        auto dp = empty_dp();
        if (i != 0)
        {
            std::cout << '\n';
        }
        std::cout << solve(dp, wind_table, distance, 0, distance) << '\n';
    }
}
