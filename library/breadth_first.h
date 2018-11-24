#pragma once

#include <vector>
#include <deque>
#include <unordered_set>
#include "graph.h"

namespace Competitive {
namespace BreadthFirst {

    template <class Graph>
    bool path_exists(Graph const& graph, std::size_t start, std::size_t end)
    {
        // Open nodes (nodes in the open_nodes set) are conceptually doing the search.
        // Once an open node neighbours the end node, the search is finished.
        // Closed nodes (nodes in the closed_nodes set) are have already been
        // searched through. The open_nodes set keeps spreading through the tree structure
        // until either we run out of nodes or the end node is found. With each step,
        // the open set is extended in such a manner that each node previously in the
        // set is now removed, while its neighbours are added. Every node from the open_nodes set
        // is also added into the closed_nodes set to avoid being visited again later.
        //
        // For grid graphs, the open set looks like a ring extending around the start node.
        // For non-grid graphs, it's how one could imagine a virus spreading.
        //
        // OpenNodes is a queue so we easily process the nodes one-by-one. It could also
        // be a vector, but that vector would need to get copied and clear a bunch. Using a
        // queue achieves the same purpose more efficiently.

        using OpenNodes = std::deque<std::size_t>;

        using ClosedNodes = std::unordered_set<std::size_t>;

        OpenNodes open_nodes {start};
        ClosedNodes closed_nodes {};

        while (!open_nodes.empty())
        {
            auto const current_node = open_nodes.front();
            open_nodes.pop_front();
            for (auto const neighbour : graph.neighbours(current_node))
            {
                if (neighbour == end)
                    return true;
                if (std::find(open_nodes.cbegin(), open_nodes.cend(), neighbour) == open_nodes.cend() &&
                    closed_nodes.find(neighbour) == closed_nodes.end())
                {
                    open_nodes.push_back(neighbour);
                }
            }
            closed_nodes.insert(current_node);
        }

        return false;
    }
 
    template <class Graph>
    Path find_path(Graph const& graph, std::size_t start, std::size_t end)
    {
        // Naturally this is really similar to checking if a path exists.
        // However, now we don't have to keep track of closed nodes.
        // Instead we introduce breadcrumbs, which in this particular case
        // is an unordered map mapping each node to the node from which it was
        // arrived at. A node is effectively closed if it exists as a key in
        // the breadcrumbs mapping. Later the breadcrums can be turned into a path.

        using OpenNodes = std::deque<std::size_t>;

        OpenNodes open_nodes {start};
        Breadcrumbs breadcrumbs;

        while (!open_nodes.empty())
        {
            auto const current_node = open_nodes.front();
            open_nodes.pop_front();
            for (auto const& neighbour : graph.neighbours(current_node))
            {
                if (neighbour == end)
                {
                    breadcrumbs.insert({neighbour, current_node});
                    return follow_breadcrumbs(breadcrumbs, start, end);
                }
                if (!breadcrumbs.count(neighbour) &&
                    std::find(open_nodes.cbegin(), open_nodes.cend(), current_node) == open_nodes.cend())
                {
                    open_nodes.push_back(neighbour);
                    breadcrumbs.insert({neighbour, current_node});
                }
            }
        }

        return {};
    }

}
}
