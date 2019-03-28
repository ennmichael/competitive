#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using IndexTable = std::unordered_map<char, std::vector<int>>;

IndexTable build_index_table(std::string const& input)
{
    IndexTable table;

    int i = 0;
    for (auto const c : input)
    {
        if (table.count(c))
        {
            table.at(c).push_back(i);
        }
        else
        {
            table.emplace(c, std::vector<int> { i });
        }
        ++i;
    }

    return table;
}

bool solve(IndexTable const& index_table, std::string const& query)
{
    if (!index_table.count(query[0]))
    {
        return false;
    }

    auto const start = index_table.at(query[0]).front();
    auto i = start;
    for (auto c = query.cbegin() + 1; c != query.cend(); ++c)
    {
        if (!index_table.count(*c))
        {
            return false;
        }

        auto const& indices = index_table.at(*c);
        auto const new_index = std::upper_bound(indices.cbegin(), indices.cend(), i);
        if (new_index == indices.cend())
        {
            return false;
        }

        i = *new_index;
    }

    std::cout << "Matched " << start << ' ' << i << '\n';
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::cin >> input;
    auto const index_table = build_index_table(input);

    int num_queries;
    std::cin >> num_queries;
    for (int i = 0; i < num_queries; ++i)
    {
        std::string query;
        std::cin >> query;
        if (!solve(index_table, query))
        {
            std::cout << "Not matched\n";
        }
    }
}
