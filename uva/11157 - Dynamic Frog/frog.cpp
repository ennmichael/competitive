#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <iterator>

struct Stone {
    char kind;
    long position;

    void input()
    {
        char hypen;
        std::cin >> kind >> hypen >> position;
    }
};

using Stones = std::vector<Stone>;

long check_small_row(Stones const& stones, Stones::const_iterator first, Stones::const_iterator last)
{
    long result = std::numeric_limits<long>::min();

    for (auto i = first + 1; i != last; ++i)
    {
        result = std::max(result, )
    }

    return result;
}

long solve(Stones const& stones)
{
    long min_distance = std::numeric_limits<long>::min();

    for (auto i = stones.cbegin(); i != stones.cend(); ++i)
    {
        if (i->kind == 'S')
        {
            auto j = std::find_if(i, stones.cend(), [](Stone const& stone) { return stone.kind == 'B'; });
            if (std::distance(i, j) > 1)
            {
                min_distance = std::max(min_distance, check_small_row(i, j));
            }
            i = j;
            continue;
        }
        
        if (i == stones.cbegin())
        {
            min_distance = std::max(min_distance, *i);
            continue;
        }
        
        min_distance = std::max(min_distance, *i - *(i - 1));
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_tests;
    std::cin >> num_tests;

    for (int i = 1; i <= num_tests; ++i)
    {
        std::size_t num_stones;
        long final_position;
        std::cin >> num_stones >> final_position;

        Stones stones(num_stones);

        for (auto& stone : stones)
        {
            stone.input();
        }

        stones.push_back(Stone { 'B', final_position });

        std::cout << solve(stones) << '\n';
    }
}
