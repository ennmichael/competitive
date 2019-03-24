#include <iostream>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

struct Vertex {
    char name = '\0';
    std::vector<Vertex*> neighbours;
    bool visited = false;

    Vertex() = default;

    explicit Vertex(char name)
        : name(name)
    {}

    bool is_acorn() const
    {
        return neighbours.size() == 0;
    }

    bool is_tree()
    {
        if (visited)
        {
            return false;
        }

        visited = true;

        for (auto * const neighbour : neighbours)
        {
            if (!neighbour->is_tree(*this))
            {
                return false;
            }
        }
        
        return true;
    }

    bool is_tree(Vertex const& parent)
    {
        visited = true;

        for (auto * const neighbour : neighbours)
        {
            if (neighbour->name == parent.name)
            {
                continue;
            }

            if (neighbour->visited)
            {
                return false;
            }

            if (!neighbour->is_tree(*this))
            {
                return false;
            }
        }

        return true;
    }

    bool connected(Vertex const& other) const
    {
        return std::any_of(neighbours.cbegin(), neighbours.cend(),
            [&](Vertex * const neighbour)
            {
                return neighbour->name == other.name;
            }
        );
    }
};

void connect(Vertex& a, Vertex& b)
{
    if (!a.connected(b))
    {
        a.neighbours.push_back(&b);
        b.neighbours.push_back(&a);
    }
}

using Vertices = std::array<Vertex, 26>;

void load_edge(Vertices& vertices, std::string const& input)
{
    auto const first_name = input[1];
    auto const second_name = input[3];
    auto& first_vertex = vertices[first_name - 'A'];
    auto& second_vertex = vertices[second_name - 'A'];
    first_vertex.name = first_name;
    second_vertex.name = second_name;
    connect(first_vertex, second_vertex);
}

void load_vertices(Vertices& vertices, std::string const& input)
{
    for (std::size_t i = 0; i < input.size(); i += 2)
    {
        auto const c = input[i];
        vertices[c - 'A'].name = c;
    }
}

void solve(Vertices& vertices)
{
    std::uint32_t num_trees = 0;
    std::uint32_t num_acorns = 0;

    for (auto & vertex : vertices)
    {
        if (!vertex.name || vertex.visited)
        {
            continue;
        }

        if (vertex.is_acorn())
        {
            ++num_acorns;
            continue;
        }

        if (vertex.is_tree())
        {
            ++num_trees;
        }
    }

    std::cout << "There are " << num_trees << " tree(s) and " << num_acorns << " acorn(s).\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint32_t num_cases;
    std::cin >> num_cases;
    for (std::uint32_t i = 0; i < num_cases; ++i)
    {
        Vertices vertices;
        bool loading_edges = true;
        while (true)
        {
            std::string input;
            std::cin >> input;
            if (input[0] == '*')
            {
                loading_edges = !loading_edges;
                continue;
            }
            if (loading_edges)
            {
                load_edge(vertices, input);
            }
            else
            {
                load_vertices(vertices, input);
                break;
            }
        }
        solve(vertices);
    }
}
