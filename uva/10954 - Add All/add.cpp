#include <iostream>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <algorithm>

using Elements = std::vector<std::uint32_t>;

std::uint32_t cost(Elements const& elements)
{
    if (elements.size() == 1)
    {
        return elements.back();
    }
    std::uint32_t sum = elements[0] + elements[1];
    std::uint32_t cost = sum;
    for (auto i = elements.cbegin() + 2; i != elements.cend(); ++i)
    {
        sum += *i;
        cost += sum;
    }
    return cost;
}

std::uint32_t solve(Elements& elements)
{
    std::sort(elements.begin(), elements.end());
    auto const a = cost(elements);
    std::swap(elements[0], elements[1]);
    auto const b = cost(elements);
    return std::min(a, b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        Elements elements;
        std::size_t num_elements;
        std::cin >> num_elements;
        if (num_elements == 0)
        {
            break;
        }
        for (std::size_t i = 0; i < num_elements; ++i)
        {
            std::uint32_t elem;
            std::cin >> elem;
            elements.push_back(elem);
        }
        std::cout << solve(elements) << '\n';
    }
}
