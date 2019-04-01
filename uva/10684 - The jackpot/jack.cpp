#include <iostream>
#include <vector>
#include <algorithm>

int solve(std::vector<int>& scores)
{
    auto i = scores.begin();
    while (i != scores.end() && *i <= 0)
    {
        ++i;
    }

    ++i;

    for (; i < scores.end(); ++i)
    {
        *i += *(i - 1);


        if (*i <= 0)
        {
            i = std::find_if(i, scores.end(), [](int n) { return n >= 0; });
        }
    }

    return *std::max_element(scores.cbegin(), scores.cend());
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t num_scores;
        std::cin >> num_scores;

        if (num_scores == 0)
        {
            break;
        }

        std::vector<int> scores(num_scores);
        for (auto& score : scores)
        {
            std::cin >> score;
        }

        auto const result = solve(scores);

        if (result <= 0)
        {
            std::cout << "Losing streak.\n";
        }
        else
        {
            std::cout << "The maximum winning streak is " << result << ".\n";
        }
    }
}
