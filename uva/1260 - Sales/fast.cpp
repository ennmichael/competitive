#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cstddef>
#include <iterator>

std::ptrdiff_t add_element(std::vector<std::uint32_t>& elements, std::uint32_t element)
{
    auto const i = std::upper_bound(elements.begin(), elements.end(), element);
    auto const result = std::distance(elements.begin(), i);
    elements.insert(i, element);
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
        std::ptrdiff_t result = 0;

        std::vector<std::uint32_t> elements;
        int num_elements;
        std::cin >> num_elements;
        elements.reserve(num_elements + 3);
        elements.resize(2);
        std::cin >> elements[0] >> elements[1];

        if (elements[0] > elements[1])
        {
            std::swap(elements[0], elements[1]);
        }
        else
        {
            ++result;
        }

        for (int i = 2; i < num_elements; ++i)
        {
            std::uint32_t element;
            std::cin >> element;
            result += add_element(elements, element);
        }

        std::cout << result << '\n';
    }
}
