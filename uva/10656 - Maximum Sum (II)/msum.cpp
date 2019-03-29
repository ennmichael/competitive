#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

using Numbers = std::vector<int>;

using Range = std::pair<Numbers::const_iterator, Numbers::const_iterator>;

Range solve(Numbers const& numbers)
{
    if (numbers.size() == 1)
    {
        return Range(numbers.cbegin(), numbers.cend());
    }

    if (numbers.front() != 0 && numbers.back() != 0)
    {
        return Range(numbers.cbegin(), numbers.cend());
    }

    auto const i = std::find_if(numbers.cbegin(), numbers.cend(), [](int v) { return v != 0; });
    auto const j = std::find_if(numbers.crbegin(), numbers.crend(), [](int v) { return v != 0; }).base();

    if (j <= i)
    { // All 0
        return Range(numbers.cbegin(), numbers.cbegin() + 1);
    }

    return Range(i, j);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t size;
        std::cin >> size;

        if (size == 0)
        {
            break;
        }

        Numbers numbers(size);

        for (auto& n : numbers)
        {
            std::cin >> n;
        }

        auto const range = solve(numbers);
        for (auto i = range.first; i != range.second - 1; ++i)
        {
            std::cout << *i << ' ';
        }
        std::cout << *(range.second - 1) << '\n';
    }
}
