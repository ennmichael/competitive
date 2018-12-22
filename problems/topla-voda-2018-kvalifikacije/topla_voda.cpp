#include <vector>
#include <queue>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

struct PipeConnection {
    unsigned long pipe;
    bool is_hot;
};

struct Pipes {
    using Connections = std::unordered_map<unsigned long, std::vector<PipeConnection>>;

    void add_connection(unsigned long from, unsigned long to) noexcept
    {
        if (connections.count(from))
            connections.at(from).push_back({to, false});
        else
            connections.insert({from, {{to, false}}});
    }

    void hotten_connection(unsigned from, unsigned long to) noexcept
    {
        auto connection = connections.at(from);
        auto const i = std::find_if(connection.begin(), connection.end(),
            [&](PipeConnection c) noexcept
            {
                return c.pipe == to;
            }
        );
        i->is_hot = true;
    }

    unsigned long count;
    Connections connections;
};

using Path = std::vector<unsigned long>;

unsigned long get_waiting_time(Pipes& pipes, unsigned long target_pipe) noexcept
{
    struct Node {
        unsigned long pipe;
        unsigned long time_required;
    };

    struct Breadcrumb {
        unsigned long from;
        PipeConnection* connection;
    };

    using OpenNodes = std::vector<Node>;

    using Breadcrumbs = std::unordered_map<unsigned long, Breadcrumb>;

    Breadcrumbs breadcrumbs;
    OpenNodes open_nodes {{1, 0}};

    auto const time_comparer = [](Node n1, Node n2)
    {
        return n1.time_required > n2.time_required;
    };

    auto const pipe_is_in_open_nodes = [&](unsigned long pipe) noexcept
    {
        auto const i = std::find_if(open_nodes.cbegin(), open_nodes.cend(),
            [&](Node node)
            {
                return node.pipe == pipe;
            }
        );
        return i != open_nodes.cend();
    };

    auto const follow_breadcrumbs = [&]
    {
        unsigned long counter = 0;
        auto current_pipe = target_pipe;
        while (current_pipe != 1)
        {
            auto& breadcrumb = breadcrumbs.at(current_pipe);
            if (breadcrumb.connection->is_hot)
            {
                return counter;
            }
            else
            {
                breadcrumb.connection->is_hot = true;
                ++counter;
                current_pipe = breadcrumb.from;
            }
        }
        return counter;
    };

    while (!open_nodes.empty())
    {
        auto const current_node = open_nodes.front();
        std::pop_heap(open_nodes.begin(), open_nodes.end(), time_comparer);
        open_nodes.pop_back();
        if (current_node.pipe == target_pipe)
            break;
        if (!pipes.connections.count(current_node.pipe))
            continue;
        auto& connections = pipes.connections.at(current_node.pipe);
        for (PipeConnection& c : connections)
        {
            auto time_required = current_node.time_required + 1;
            auto const neighbour_pipe = c.pipe;
            if (breadcrumbs.count(neighbour_pipe) || pipe_is_in_open_nodes(neighbour_pipe))
                continue;
            open_nodes.push_back({neighbour_pipe, time_required});
            std::push_heap(open_nodes.begin(), open_nodes.end(), time_comparer);
            breadcrumbs.insert({neighbour_pipe, {current_node.pipe, &c}});
        }
    }

    return follow_breadcrumbs();
}

Pipes load_pipes() noexcept
{
    unsigned long num_pipes;
    std::cin >> num_pipes;
    Pipes pipes {num_pipes, {}};
    for (std::size_t i = 0; i < num_pipes - 1; ++i)
    {
        unsigned long from;
        unsigned long to;
        std::cin >> from;
        std::cin >> to;
        pipes.add_connection(from, to);
        pipes.add_connection(to, from);
    }
    return pipes;
}

void execute_plans(Pipes& pipes) noexcept
{
    unsigned long num_plans;
    std::cin >> num_plans;
    for (unsigned long i = 0; i < num_plans; ++i)
    {
        unsigned long target_pipe;
        std::cin >> target_pipe;
        std::cout << get_waiting_time(pipes, target_pipe) << '\n';
    }
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    auto pipes = load_pipes();
    execute_plans(pipes);
}

