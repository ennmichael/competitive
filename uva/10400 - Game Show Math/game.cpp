#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>

using Operands = std::vector<long>;

using DP = std::unordered_map<long, std::array<std::string, 105>>;

std::string solve(DP& dp, Operands::const_reverse_iterator first, Operands::const_reverse_iterator last, long target)
{
    if (target > 32000 || target < -32000)
    {
        return "X";
    }

    auto const num_operands = std::distance(first, last);

    if (num_operands < 2)
    {
        return "X";
    }

    if (!dp[target][num_operands].empty())
    {
        return dp[target][num_operands];
    }

    if (num_operands == 2)
    {
        auto const a = *(first + 1);
        auto const b = *first;

        if (a + b == target)
        {
            return dp[target][num_operands] = "+";
        }

        if (a - b == target)
        {
            return dp[target][num_operands] = "-";
        }

        if (a * b == target)
        {
            return dp[target][num_operands] = "*";
        }

        if (a % b == 0 && a / b == target)
        {
            return dp[target][num_operands] = "/";
        }

        return "X";
    }

    auto const a = *first;

    auto operators = solve(dp, first + 1, last, target - a);
    if (operators != "X")
    {
        return dp[target][num_operands] = "+" + operators;
    }

    operators = solve(dp, first + 1, last, target + a);
    if (operators != "X")
    {
        return dp[target][num_operands] = "-" + operators;
    }

    if (target % a == 0)
    {
        operators = solve(dp, first + 1, last, target / a);
        if (operators != "X")
        {
            return dp[target][num_operands] = "*" + operators;
        }
    }

    operators = solve(dp, first + 1, last, target * a);
    if (operators != "X")
    {
        return dp[target][num_operands] = "/" + operators;
    }

    return dp[target][num_operands] = "X";
}

void print_expression(Operands const& operands, std::string const& operators, long target)
{
    auto i = operands.cbegin();
    auto j = operators.crbegin();

    while (j != operators.crend())
    {
        std::cout << *i << *j;
        ++i;
        ++j;
    }

    std::cout << operands.back() << '=' << target << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    std::cin >> test_cases;

    for (int i = 0; i < test_cases; ++i)
    {
        int num_operands;
        std::cin >> num_operands;

        Operands operands(num_operands);

        for (auto& operand : operands)
        {
            std::cin >> operand;
        }

        long target;
        std::cin >> target;

        DP dp;

        if (operands.size() == 1)
        {
            if (operands.back() == target)
            {
                std::cout << target << '=' << target << '\n';
            }
            else
            {
                std::cout << "NO EXPRESSION\n";
            }
        }
        else
        {
            auto const operators = solve(dp, operands.crbegin(), operands.crend(), target);
            if (operators == "X")
            { 
                std::cout << "NO EXPRESSION\n";
            }
            else
            {
                print_expression(operands, operators, target);
            }
        }
    }
}
