#include <iostream>
#include <vector>
#include <cstddef>
#include <cmath>
#include <limits>

using Vessels = std::vector<long long>;

// This is incorrect
// Write a correct version, binary search the answer, and then compare the outputs
// of the two programs. If the emptiness function is written correctly, this program
// is more likely to be correct than the other one.
long long emptiness(Vessels const& vessels, long long container_capacity, long long num_containers)
{
    long long result = 0;
    auto i = vessels.cbegin();

    for (long long j = 0; j < num_containers; ++j)
    {
        auto capacity = container_capacity;

        if (i != vessels.cend() && *i > capacity)
        {
            return -1;
        }

        while (i != vessels.cend())
        {
            auto const new_capacity = capacity - *i;

            if (new_capacity < 0)
            {
                break;
            }

            capacity = new_capacity;
            ++i;
        }

        result += capacity;
    }

    if (i != vessels.cend())
    {
        return -1;
    }

    return result;
}

long long solve(Vessels const& vessels, long long num_containers)
{
    long long lower = 0;
    long long upper = 1000000000l;
    long long capacity = upper / 2;
    long long min_emptiness = std::numeric_limits<long long>::max();
    long long solution = capacity;

    while (lower != capacity && upper != capacity)
    {
        auto const e = emptiness(vessels, capacity, num_containers);

        if (e < 0)
        {
            lower = capacity;
            capacity = (lower + upper) / 2;
            continue;
        }

        if (e < min_emptiness)
        {
            min_emptiness = e;
            solution = capacity;
        }

        upper = capacity;
        capacity = (lower + upper) / 2;
    }

    return solution;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t num_vessels;
        long long num_containers;
        std::cin >> num_vessels >> num_containers;

        if (std::cin.eof())
        {
            break;
        }

        Vessels vessels(num_vessels);
        for (auto& vessel : vessels)
        {
            std::cin >> vessel;
        }

        // std::cout << emptiness(vessels, 61035, 3) << '\n';
        std::cout << solve(vessels, num_containers) << '\n';
    }
}
