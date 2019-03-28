#include <iostream>
#include <string>

char constexpr good = '.';
char constexpr bad = '#';
char constexpr covered = '/';

// XXX Use covered

int solve(std::string& input)
{
    int num_crows = 0;

    for (auto i = input.begin(); i != input.end(); ++i)
    {
        if (*i == covered)
        {
            continue;
        }

        if (i == input.begin() || *(i - 1) == bad || *(i - 1) == covered)
        {
            if (i == input.end() - 1 && *i == good)
            {
                ++num_crows;
            }
            continue;
        }

        ++num_crows;
        *i = covered;
        if (i != input.end() - 1)
        {
            *(i + 1) = covered;
        }
    }

    return num_crows;
}

int main()
{
    int num_cases;
    std::cin >> num_cases;
    for (int test_case = 1; test_case <= num_cases; ++test_case)
    {
        int num_fields;
        std::cin >> num_fields;
        std::string input;
        input.reserve(num_fields);
        std::cin >> input;
        std::cout << "Case " << test_case << ": " << solve(input) << '\n';
    }
}
