#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using Int = long long;

using Ints = std::vector<Int>;

Int solve(Ints& ints)
{
    for (auto i = ints.begin() + 1; i != ints.end(); ++i)
    {
        *i *= *(i - 1);
    }

    auto const max_product = *std::max_element(ints.cbegin(), ints.cend());
    auto const min_product = *std::min_element(ints.cbegin(), ints.cend());

    if (min_product >= 0)
    {
        return max_product;
    }

    auto const max_negative_product = *std::min_element(ints.cbegin(), ints.cend(),
        [](Int left, Int right)
        {
            if (left >= 0)
            {
                left = std::numeric_limits<Int>::min();
            }
            if (right >= 0)
            {
                right = std::numeric_limits<Int>::min();
            }
            return left > right;
        }
    );

    if (min_product == max_negative_product)
    {
        return max_product;
    }

    return std::max(max_product, min_product / max_negative_product);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Ints ints;
    Int result = std::numeric_limits<Int>::min();
    while (true)
    {
        Int i;
        std::cin >> i;
        
        if (std::cin.eof())
        {
            break;
        }

        if (i == -999999)
        {
            if (!ints.empty())
            {
                result = std::max(result, solve(ints));
            }

            std::cout << result << '\n';
            ints.clear();
            result = std::numeric_limits<Int>::min();
        }
        else if (i == 0)
        {
            if (!ints.empty())
            {
                result = std::max(result, solve(ints));
                result = std::max(static_cast<Int>(0), result);
                ints.clear();
            }
        }
        else
        {
            ints.push_back(i);
        }
    }
}
