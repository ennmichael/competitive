#include <iostream>
#include <queue>
#include <cstdint>
#include <string>

struct Query {
    std::uint32_t id;
    std::uint32_t period;
    std::uint32_t time;

    Query next() const noexcept
    {
        return {
            id, period, time + period
        };
    }
};

bool operator<(Query const& left, Query const& right)
{
    if (left.time == right.time)
    {
        return left.id > right.id;
    }
    return left.time > right.time;
}

// If two or more queries are to return the results at the same time, they will return
// the results one by one in the ascending order of id.

void solve(std::priority_queue<Query>& queries, std::uint32_t num_results)
{
    for (std::uint32_t i = 0; i < num_results; ++i)
    {
        auto const query = queries.top();
        std::cout << query.id << '\n';
        queries.pop();
        queries.push(query.next());
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<Query> queries;
    std::string control;

    while (true)
    {
        std::cin >> control;
        if (control == "#")
        {
            break;
        }
        Query query;
        std::cin >> query.id;
        std::cin >> query.period;
        query.time = query.period;
        queries.push(query);
    }

    std::uint32_t num_results;
    std::cin >> num_results;
    solve(queries, num_results);
}
