#pragma once

#include <vector>
#include <unordered_set>

namespace Competitive::BreadthFirst {

    template <class Graph>
    bool path_exists(Graph const& graph,
                     typename Graph::Node const& start,
                     typename Graph::Node const& end)
    {
        return path_exists(graph, graph.nodes.find(start), graph.nodes.find(end));
    }

    template <class Graph>
    bool path_exists(Graph const& graph,
                     std::size_t start,
                     std::size_t end)
    {
        using OpenNodes = std::vector<std::size_t>;

        using ClosedNodes = std::unordered_set<std::size_t>;

        // Nodes marked "open" (in the open_nodes set) are conceptually doing the search.
        // Once an open node neighbours the end node, the search is finished.
        // Nodes marked "closed" (in the closed_nodes set) are nodes that have already been
        // searched through. The open_nodes set keeps spreading through the tree structure
        // until either we run out of nodes or the end node is found. With each step,
        // the open set is extended in such a manner that each node previously in the
        // set is now replaced by its neighbours. Every node from the open_nodes set
        // is also added into the closed_nodes set to avoid being visited again later.
        //
        // For grid graphs, the open set looks like a ring extending around the start node.
        // For non-grid graphs, it's how one could imagine a virus spreading.

        OpenNodes open_nodes {start};
        ClosedNodes closed_nodes {start};

        while (!open_nodes.empty())
        {
            auto const old_open_nodes = open_nodes;
            open_nodes.clear();
            for (auto const& node : old_open_nodes)
            {
                for (auto const& neighbour : graph.neighbours(node))
                {
                    if (neighbour == end)
                        return true;

                    if (closed_nodes.find(neighbour) == closed_nodes.end())
                    {
                        open_nodes.push_back(neighbour);
                        closed_nodes.insert(neighbour);
                    }
                }
            }
        }

        return false;
    }

}
