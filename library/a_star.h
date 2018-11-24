#pragma once

#include "graph.h"
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <limits>

namespace Competitive {
namespace AStar {

    // TODO Change the word priority -> heuristic (because that's what it really is)

    template <class Graph, class HeuristicFunction>
    Path find_path(Graph const& graph, std::size_t start, std::size_t end, HeuristicFunction const& h)
    {
        using Heuristic = decltype(h(graph, start, std::size_t {}));

        using OpenNodes = std::vector<std::size_t>;

        using VisitedNodes = std::unordered_set<std::size_t>;

        using Heuristics = std::unordered_map<std::size_t, Heuristic>;

        struct HeuristicsComparer {
            Heuristics heuristics;

            bool operator()(std::size_t node1, std::size_t node2) const noexcept
            {
                if (!heuristics.count(node1))
                    return true;
                if (!heuristics.count(node2))
                    return false;
                return heuristics.at(node1) > heuristics.at(node2);
            }
        };

        OpenNodes open_nodes {start};
        VisitedNodes visited_nodes;
        Breadcrumbs breadcrumbs;
        HeuristicsComparer comparer;

        while (!open_nodes.empty())
        {
            auto const current_node = std::pop_heap(open_nodes);
            if (current_node == end)
                return follow_breadcrumbs(breadcrumbs);
            for (auto const neighbour : graph.neighbours(current_node))
            {
                auto const heuristic = h(graph, start, current_node);
                auto const active_heuristic = (comparer.heuristics.count(neighbour)) ?
                    comparer.heuristics.at(neighbour) : std::numeric_limits<std::size_t>::max();
                if (heuristic < active_heuristic)
                {
                    comparer.heuristics.insert_or_assign(neighbour, heuristic);
                    std::make_heap(open_nodes.begin(), open_nodes.end(), comparer);
                    breadcrumbs.insert_or_assign(neighbour, current_node);
                }
                if (visited_nodes.find(neighbour) == visited_nodes.end())
                {
                    open_nodes.push_back(neighbour);
                    std::push_heap(open_nodes.begin(), open_nodes.end(), comparer);
                }
            }
            visited_nodes.insert(current_node);
        }

        return {};
    }

}
}

