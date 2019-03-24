#include <iostream>
#include <cstdint>
#include <vector>

using Polynomial = std::vector<std::uint64_t>;

std::uint64_t evaluate_polynomial(Polynomial const& polynomial, std::uint64_t n) 
{
    std::uint64_t result = 0;
    std::uint64_t i = 1;
    for (auto const coefficient : polynomial)
    {
        result += coefficient * i;
        i *= n;
    }
    return result;
}

std::uint64_t find_step(std::uint64_t num_repeats, std::uint64_t query)
{
    std::uint64_t i = num_repeats;
    std::uint64_t step = 1;
    while (true)
    {
        if (query <= i)
        {
            return step;
        }
        ++step;
        i += step * num_repeats;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i)
    {
        std::size_t num_coefficients;
        std::cin >> num_coefficients;
        ++num_coefficients;
        Polynomial polynomial(num_coefficients);
        for (auto& coefficient : polynomial)
        {
            std::cin >> coefficient;
        }
        std::uint64_t num_repeats;
        std::uint64_t query;
        std::cin >> num_repeats >> query;
        auto const step = find_step(num_repeats, query);
        std::cout << evaluate_polynomial(polynomial, step) << '\n';
    }
}
