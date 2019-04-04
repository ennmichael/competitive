#include <iostream>
#include <string>
#include <unordered_map>

using DP = std::unordered_map<std::string, bool>;

char opposite_char(char c)
{
    if (c == 'a')
    {
        return 'b';
    }

    return 'a';
}

bool solve(DP& dp, std::string const& str)
{
    if (str.empty())
    {
        return true;
    }

    if (dp.count(str))
    {
        return dp.at(str);
    }

    std::size_t i = 0;

    while (i != str.size())
    {
        auto j = str.find(opposite_char(str[i]), i);

        if (j == std::string::npos)
        {
            j = str.size();
        }

        if (j - i == 1)
        {
            i = j;
            continue;
        }

        auto str_copy = str;
        auto first = str_copy.begin() + i;
        auto last = str_copy.begin() + j;
        str_copy.erase(first, last);

        if (solve(dp, str_copy))
        {
            dp.emplace(str, true);
            return true;
        }

        i = j;
    }

    dp.emplace(str, false);
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    std::cin >> test_cases;

    for (int i = 0; i < test_cases; ++i)
    {
        std::string str;
        std::cin >> str;
        DP dp;
        std::cout << solve(dp, str) << '\n';
    }
}
