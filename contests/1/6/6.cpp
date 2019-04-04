#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using Graph = std::unordered_map<char, std::vector<char>>;
using Inwards = std::unordered_map<char, std::vector<char>>;

std::array<char, 5> constexpr all_balls {{ 'A', 'B', 'C', 'D', 'E' }};

char find_root(Graph& graph, Inwards const& inwards)
{
    for (auto const c : all_balls)
    {
        if (!inwards.count(c))
        {
            return c;
        }
    }

    return '\0';
}

using Seen = std::unordered_set<char>;


bool DFS(Graph& graph, Inwards const& inwards, const char curr, const int depth, Seen& seen, char previous = '\0')
{
    if (depth == 5) {
        std::cout << curr;
        return 1;
    }
    seen.insert(curr);
    for (auto c : graph[curr]) {
        if (!seen.count(c)) {
            if (DFS(graph, inwards, c, depth + 1, seen, curr)) {
                std::cout << curr;
                return 1;
            }//if
        }//if
    }//for
    seen.erase(curr);
    return 0;
}

bool topsort(Graph& graph, Inwards const& inwards)
{
    auto const root = find_root(graph, inwards);

    if (!root)
    {
        return false;
    }

    Seen seen;
    return DFS(graph, inwards, root, 1, seen);
}

int main()
{
    std::ios::sync_with_stdio(false);

    Graph graph;
    Inwards inwards;

    for (int i = 0; i < 5; ++i)
    {
        char left;
        char op;
        char right;

        std::cin >> left >> op >> right;

        if (op == '>')
        {
            graph[left].push_back(right);
            inwards[right].push_back(left);
        }
        else
        {
            graph[right].push_back(left);
            inwards[left].push_back(right);
        }
    }

    std::vector<char> result;

    if (!topsort(graph, inwards))
    {
        std::cout << "impossible\n";
    }
    else
    {
        for (auto const c : result)
        {
            std::cout << c;
        }
        std::cout << '\n';
    }
}
