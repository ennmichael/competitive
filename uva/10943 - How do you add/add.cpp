#include <iostream>
#include <array>

using DP = std::array<std::array<long long, 105>, 105>;

void clear_dp(DP& dp)
{
    for (auto& row : dp)
    {
        for (auto& n : row)
        {
            n = -1;
        }
    }
}

long long solve(DP& dp, long long n, long long k)
{
    if (n == 0 || k == 1)
    {
        return 1;
    }

    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }

    dp[n][k] = 0;
    
    for (long long i = 0; i <= n; ++i)
    {
        dp[n][k] += solve(dp, n - i, k - 1);
        dp[n][k] %= 1000000;
    }

    return dp[n][k];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    DP dp;

    while (true)
    {
        clear_dp(dp);
        long long n;
        long long k;
        std::cin >> n >> k;

        if (n == 0 && k == 0)
        {
            break;
        }

        std::cout << solve(dp, n, k) << '\n';
    }
}

