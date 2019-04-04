#include <iostream>
#include <vector>
#include <cstddef>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>

using PredecessorTable = std::unordered_map<std::size_t, std::size_t>;

std::vector<int> reconstruct(PredecessorTable const& predecessor_table, std::vector<int> const& missles, std::size_t start)
{
    std::vector<int> result { missles[start] };

    while (predecessor_table.count(start))
    {
        start = predecessor_table.at(start);
        result.push_back(missles[start]);
    }

    return result;
}

std::vector<int> find_lis(std::vector<int> const& missles)
{
    std::vector<std::size_t> minimums;
    PredecessorTable predecessor_table;

    for (std::size_t missle_index = 0; missle_index < missles.size(); ++missle_index)
    {
        auto const missle = missles[missle_index];
        auto const i = std::lower_bound(minimums.begin(), minimums.end(), missle,
            [&](std::size_t left, int right)
            {
                return missles[left] < right;
            }
        );

        if (i != minimums.begin())
        {
            predecessor_table.emplace(missle_index, *(i - 1));
        }

        if (i == minimums.end())
        {
            minimums.push_back(missle_index);
            continue;
        }

        *i = missle_index;
    }

    if (minimums.size() == 0)
    {
        return missles;
    }
    else
    {
        return reconstruct(predecessor_table, missles, minimums.back());
    }
}

void print_reverse(std::vector<int> const& missles)
{
    std::cout << "Max hits: " << missles.size() << '\n';
    for (auto i = missles.crbegin(); i != missles.crend(); ++i)
    {
        std::cout << *i << '\n';
    }
}

void solve(std::vector<int> const& missles)
{
    print_reverse(find_lis(missles));
}

int to_int(std::string const& line)
{
    std::stringstream ss(line);
    int result;
    ss >> result;
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    int test_cases;
    std::cin >> test_cases;
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    for (int i = 0; i < test_cases; ++i)
    {
        std::vector<int> missles;
        while (true)
        {
            std::getline(std::cin, line);

            if (line == "")
            {
                break;
            }

            missles.push_back(to_int(line));
        }

        if (i != 0)
        {
            std::cout << '\n';
        }
        solve(missles);
    }
}
