#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// This is correct, but too slow and shittily written

struct LisNode {
    long long length = 0;
    long long previous = -1;
};

std::vector<int> find_lis(std::vector<int> const& numbers)
{
    std::vector<LisNode> lis(numbers.size());
    lis.front().length = 1;

    auto const max_lis_element = [&]
    {
        long long result = 0;
        long long max_length = -1;

        for (long long i = lis.size() - 1; i >= 0; --i)
        {
            if (lis[i].length > max_length)
            {
                result = i;
                max_length = lis[i].length;
            }
        }

        return result;
    };

    auto const reconstruct = [&]
    {
        std::vector<int> result;

        long long i = max_lis_element();

        while (i != -1)
        {
            result.push_back(numbers[i]);
            i = lis[i].previous;
        }

        return result;
    };

    auto const find_predecessor = [&](long long i)
    {
        long long result = -1;
        long long max_length = -1;

        for (long long j = i - 1; j >= 0; --j)
        {
            if (numbers[j] < numbers[i] && lis[j].length > max_length)
            {
                result = j;
                max_length = lis[j].length;
            }
        }

        return result;
    };

    for (long long i = 1; i < static_cast<long long>(numbers.size()); ++i)
    {
        auto const j = find_predecessor(i);
        if (j == -1)
        {
            lis[i].length = 1;
            continue;
        }
        lis[i].length = lis[j].length + 1;
        lis[i].previous = j;
    }

    return reconstruct();
}

void solve(std::vector<int> const& numbers)
{
    auto const lis = find_lis(numbers);
    std::cout << lis.size() << "\n-\n";
    for (auto i = lis.crbegin(); i != lis.crend(); ++i)
    {
        std::cout << *i << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> numbers;

    while (true)
    {
        int i;
        std::cin >> i;

        if (std::cin.eof())
        {
            break;
        }

        numbers.push_back(i);
    }

    solve(numbers);
}
