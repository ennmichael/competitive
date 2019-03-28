#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using Rungs = std::vector<long>;

void preprocess(Rungs& rungs)
{
    for (auto i = rungs.end() - 1; i != rungs.begin(); --i)
    {
        *i = *i - *(i - 1);
    }
}

long remaining_strength(Rungs const& rungs, long strength)
{
    for (auto const rung : rungs)
    {
        if (rung > strength)
        {
            return -1;
        }

        if (rung == strength)
        {
            --strength;
        }
    }

    return strength;
}

long solve(Rungs const& rungs)
{
    long lower = 0;
    long upper = std::numeric_limits<long>::max();
    long strength = (lower + upper) / 2;
    long result = upper;

    while (lower != strength && upper != strength)
    {
        auto const r = remaining_strength(rungs, strength);

        if (r < 0)
        {
            lower = strength;
            strength = (lower + upper) / 2;
        }
        else
        {
            result = std::min(result, strength);
            upper = strength;
            strength = (lower + upper) / 2;
        }
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 1; i <= num_test_cases; ++i)
    {
        std::size_t num_rungs;
        std::cin >> num_rungs;
        Rungs rungs(num_rungs);
        for (auto& rung : rungs)
        {
            std::cin >> rung;
        }
        preprocess(rungs);
        std::cout << "Case " << i << ": " << solve(rungs) << '\n';
    }
}
