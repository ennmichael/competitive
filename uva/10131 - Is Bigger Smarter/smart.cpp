#include <iostream>
#include <vector>
#include <utility>

struct Item {
    std::size_t id;
    int value;
};

using Weights = std::vector<Item>;

using IQs = std::vector<Item>;

std::vector<int> longest_common_subsequence(Weights const& weights, IQs const& iqs)
{
    std::vector<int> result;

    auto i = weights.cbegin();
    auto j = weights.cend()

    for ()
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
