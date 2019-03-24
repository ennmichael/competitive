#include <iostream>
#include <vector>
#include <cstdint>
#include <cstddef>

std::uint32_t solve(std::vector<std::uint32_t> const& elements)
{
    std::uint32_t result = 0;
    for (auto i = elements.begin() + 1; i != elements.cend(); ++i)
    {
        for (auto j = elements.begin(); j != i; ++j)
        {
            if (*j <= *i)
            {
                ++result;
            }
        }
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint32_t num_test_cases;
    std::cin >> num_test_cases;
    for (std::uint32_t i = 0; i < num_test_cases; ++i)
    {
        int num_elements;
        std::cin >> num_elements;
        std::vector<std::uint32_t> elements(num_elements);
        for (auto& element : elements)
        {
            std::cin >> element;
        }

        std::cout << solve(elements) << '\n';
    }
}
