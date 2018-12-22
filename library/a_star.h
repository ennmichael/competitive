#pragma once

#include "graph.h"
#include "common.h"
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <limits>

namespace Competitive {
namespace AStar {

    template <class AdjacencyList, class HeuristicFunction>
    Path find_path(AdjacencyList const& graph, std::size_t start, std::size_t end, HeuristicFunction const& h)
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
        HeuristicsComparer comparer {Heuristics {{start, 0}}};

        while (!open_nodes.empty())
        {
            std::pop_heap(open_nodes.begin(), open_nodes.end());
            auto const current_node = open_nodes.back();
            open_nodes.pop_back();
            if (current_node == end)
                return follow_breadcrumbs(breadcrumbs, start, end);
            auto const current_node_heuristic = comparer.heuristics.at(current_node);
            for (auto const neighbour : graph.neighbours(current_node))
            {
                auto const new_heuristic = current_node_heuristic + h(graph, current_node, end);
                if (!comparer.heuristics.count(neighbour))
                {
                    comparer.heuristics.insert({neighbour, new_heuristic});
                    std::make_heap(open_nodes.begin(), open_nodes.end(), comparer);
                    breadcrumbs.insert({neighbour, current_node});
                }
                else if (new_heuristic < comparer.heuristics.at(neighbour))
                {
                    comparer.heuristics.at(neighbour) = new_heuristic;
                    std::make_heap(open_nodes.begin(), open_nodes.end(), comparer);
                    breadcrumbs.at(neighbour) = current_node;
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

