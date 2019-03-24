#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

enum class Color {
    none, black, white
};

struct Node {
    int id;
    Color color;
    std::vector<Node*> neighbours;

    bool is_colored() const
    {
        return color != Color::none;
    }

    bool is_valid() const
    {
        if (color == Color::black)
        {
            return std::none_of(neighbours.cbegin(), neighbours.cend(),
                [](Node* neighbour)
                {
                    return neighbour->color != Color::black;
                }
            );
        }

        return true;
    }

    Node& first_uncolored_neighbour() const
    {
        for (auto* neighbour : neighbours)
        {
            if (!neighbour->is_colored())
            {
                return *neighbour;
            }
        }
    }
};

using Graph = std::unordered_map<int, Node>;

struct Problem {
    Graph graph;
    int max_black_count = 0;
    std::vector<int> solution;

    Node& starting_node()
    {
        return std::min_element(graph.begin(), graph.end(),
            [](Graph::value_type const& left, Graph::value_type const& right)
            {
                return left.second.neighbours.size() < right.second.neighbours.size();
            }
        )->second;
    }

    void solve()
    {
        solve(starting_node());
    }

    void solve(Node& current_node, int black_count = 0)
    {
        if (current_node.is_colored())
        {
            return;
        }

        // End condition
        if (current_node.neighbours.size() == 1 && current_node.neighbours[0]->is_colored())
        {
            if (current_node.neighbours[0]->color == Color::white)
            {
                if (black_count + 1 > max_black_count)
                {
                    max_black_count = black_count + 1;
                    update_solution();
                }
            }
            else
            {
                if (black_count > max_black_count)
                {
                    max_black_count = black_count;
                    update_solution();
                }
            }
            return;
        }

        current_node.color = Color::black;
        if (current_node.is_valid())
        {
            solve(current_node.first_uncolored_neighbour(), black_count + 1);
        }
        else
        {
            current_node.color = Color::white;
            solve(current_node.first_uncolored_neighbour(), black_count);
        }
        current_node.color = Color::white;
    }

    void update_solution()
    {
        solution.clear();
        for (auto const& entry : graph)
        {
            if (entry.second.color == Color::black)
            {
                solution.push_back(entry.second.id);
            }
        }
    }
};

int main()
{
}
