#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <cstddef>

std::array<int, 10> constexpr primes {{
    3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
}};

bool is_prime(int number)
{
    return std::find(primes.cbegin(), primes.cend(), number) != primes.cend();
}

struct Problem {
    std::vector<unsigned> elements;
    std::array<bool, 18> used_numbers {{}};

    explicit Problem(int num_elements)
        : elements(num_elements)
    {
        used_numbers[1] = true;
        elements[0] = 1;
    }

    void solve(std::size_t index = 1)
    {
        if (index == elements.size() && is_prime(elements.front() + elements.back()))
        {
            output();
            return;
        }

        for (auto x = first_unused_number(); x <= elements.size(); x = first_unused_number(x))
        {
            if (!is_prime(x + elements[index - 1]))
            {
                continue;
            }
            elements[index] = x;
            used_numbers[x] = true;
            solve(index + 1);
            used_numbers[x] = false;
        }
    }

    void output()
    {
        for (auto i = elements.cbegin(); i != elements.cend() - 1; ++i)
        {
            std::cout << *i << ' ';
        }
        std::cout << elements.back() << '\n';
    }

    unsigned first_unused_number(unsigned start = 0) const
    {
        for (unsigned i = start + 1; i <= used_numbers.size(); ++i)
        {
            if (used_numbers[i])
            {
                continue;
            }

            return i;
        }

        return 0;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case = 0;
    while (true)
    {
        ++test_case;
        int num_elements;
        std::cin >> num_elements;

        if (std::cin.eof())
        {
            break;
        }

        if (test_case != 1)
        {
            std::cout << '\n';
        }
        std::cout << "Case " << test_case << ":\n";
        Problem problem(num_elements);
        problem.solve();
    }
}
