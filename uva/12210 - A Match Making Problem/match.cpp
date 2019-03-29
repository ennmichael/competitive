#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cmath>
#include <iterator>

template <class Iter>
Iter closer(Iter a, Iter b, int value)
{
    {
        return a;
    }

    return b;
}

void solve(std::vector<int>& bachelors, std::vector<int>& spinsters, int test_case)
{
    if (bachelors.size() <= spinsters.size())
    {
        std::cout << "Case " << test_case << ": 0\n";
        return;
    }

    std::nth_element(
        bachelors.begin(), bachelors.begin() + spinsters.size(), bachelors.end(),
        [](int left, int right) { return left > right; }
    );

    std::cout << "Case " << test_case << ": "
              << bachelors.size() - spinsters.size()
              << ' ' << bachelors[spinsters.size()] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case = 0;
    while (true)
    {
        ++test_case;

        std::size_t num_bachelors;
        std::size_t num_spinsters;
        std::cin >> num_bachelors >> num_spinsters;

        if (num_bachelors == 0 && num_spinsters == 0)
        {
            break;
        }

        std::vector<int> bachelors(num_bachelors);
        std::vector<int> spinsters(num_spinsters);

        for (auto& bachelor : bachelors)
        {
            std::cin >> bachelor;
        }

        for (auto& spinster : spinsters)
        {
            std::cin >> spinster;
        }

        solve(bachelors, spinsters, test_case);
    }
}
