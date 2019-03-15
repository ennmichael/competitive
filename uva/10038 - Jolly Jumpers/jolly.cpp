#include <iostream>
#include <cstddef>
#include <limits>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <algorithm>

bool is_jolly(std::vector<std::int32_t> const& elements)
{
    if (elements.size() <= 1)
    {
        return true;
    }

    std::unordered_set<std::int32_t> set;

    for (auto i = elements.cbegin(); i != elements.cend() - 1; ++i)
    {
        set.insert(std::abs(*i - *(i + 1)));
    }

    if (set.find(0) != set.end())
    {
        return false;
    }

    for (std::size_t i = 1; i < elements.size(); ++i)
    {
        if (set.find(i) == set.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t num_elements;
        std::cin >> num_elements;

        if (std::cin.eof())
        {
            break;
        }

        std::vector<std::int32_t> elements(num_elements);
        for (std::size_t i = 0; i < num_elements; ++i)
        {
            std::cin >> elements[i];
        }
        if (is_jolly(elements))
        {
            std::cout << "Jolly\n";
        }
        else
        {
            std::cout << "Not jolly\n";
        }
    }
}
