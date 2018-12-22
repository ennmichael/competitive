#include <iostream>
#include <array>
#include <limits>
#include <vector>
#include <cmath>
#include <numeric>

using Primes = std::array<unsigned long, 8>;

Primes constexpr primes {{2, 3, 5, 7, 11, 13, 17, 19}};

std::vector<unsigned long> factorize(unsigned long n) noexcept
{
    std::vector<unsigned long> factors;
    for (auto const p : primes)
    {
        if (n % p == 0)
        {
            n /= p;
            factors.push_back(p);
        }
    }
    if (n != 1)
        factors.push_back(n);
    return factors;
}

std::vector<unsigned long> get_divisors(unsigned long n) noexcept
{
    std::vector<unsigned long> divisors;
    divisors.reserve(20);
    divisors.push_back(1);
    auto const factors = factorize(n);
    std::vector<unsigned long> powers(factors.size(), 0);

    auto const current_divisor = [&]
    {
        unsigned long r = 1;
        for (std::size_t i = 0; i < factors.size(); ++i)
            r *= std::pow(factors[i], powers[i]);
        return r;
    };

    while (true)
    {
        ++powers[0];
        std::size_t j = 0;
        while (n % current_divisor() != 0)
        {
            powers[j] = 0;
            ++j;
            if (j == factors.size())
                return divisors;
            ++powers[j];
        }
        divisors.push_back(current_divisor());
    }

    return divisors;
}

double triviality(unsigned long n) noexcept
{
    auto const divisors = get_divisors(n);
    return std::accumulate(divisors.cbegin(), divisors.cend(), 0.0) / n;
}

unsigned long minimum_trivial_number(unsigned long upper_limit) noexcept
{
    unsigned long result = 0;
    double result_triviality = std::numeric_limits<double>::max();
    for (unsigned long i = 2; i <= upper_limit; ++i)
    {
        auto const t = triviality(i);
        if (t < result_triviality)
        {
            result = i;
            result_triviality = t;
        }
    }
    return result;
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    get_divisors(23);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        unsigned long upper_limit;
        std::cin >> upper_limit;
        std::cout << minimum_trivial_number(upper_limit) << '\n';
    }
}
