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

std::vector<int>::const_iterator solve(std::vector<int>& bachelors, std::vector<int>& spinsters)
{
    if (bachelors.size() <= spinsters.size())
    {
        return bachelors.cend();
    }

    std::sort(bachelors.begin(), bachelors.end(), [](int left, int right) { return left > right; });
    std::sort(spinsters.begin(), spinsters.end());

    auto bachelor = bachelors.cbegin();
    for (; bachelor != bachelors.cend(); ++bachelor)
    {
        auto const i = std::lower_bound(spinsters.begin(), spinsters.end(), *bachelor);

        if (i == spinsters.end())
        {
            break;
        }

        if (i == spinsters.begin() || std::abs(*i - *bachelor) < std::abs(*(i - 1) - *bachelor))
        {
            spinsters.erase(i);
        }
        else
        {
            spinsters.erase(i - 1);
        }
    }

    return bachelor;
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

        auto const bachelor = solve(bachelors, spinsters);

        if (bachelor == bachelors.cend())
        {
            std::cout << "Case " << test_case << ": 0\n";
        }
        else
        {
            std::cout << "Case " << test_case << ": "
                      << std::distance(bachelor, bachelors.cend())
                      << ' ' << *bachelor << '\n';
        }
    }
}
