#pragma once

#include <algorithm>
#include <vector>
#include <unordered_map>

namespace Competitive {

    template <class NodeData>
    struct Graph {

        using Nodes = std::vector<NodeData>;

        using Neighbours = std::vector<std::size_t>;

        using Arcs = std::unordered_map<std::size_t, Neighbours>;

        Nodes nodes;
        Arcs arcs;

        Neighbours neighbours(std::size_t node) const noexcept
        {
            return (arcs.count(node)) ? arcs.at(node) : Neighbours {};
        }
    };

    using Path = std::vector<std::size_t>;

    using Breadcrumbs = std::unordered_map<std::size_t, std::size_t>;

    inline Path follow_breadcrumbs(Breadcrumbs const& breadcrumbs, std::size_t start, std::size_t end)
    {
        // Follow the breadcrumbs, getting the path from end to start.
        // The container can optionally be reversed to get the path from start to end.

        Path path;
        do
        {
            path.push_back(end);
            end = breadcrumbs.at(end);
        } while (end != start);
        path.push_back(end);
        return path;
    }

}

