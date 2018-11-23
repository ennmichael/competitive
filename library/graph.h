#pragma once

#include <algorithm>
#include <vector>
#include <unordered_map>

namespace Competitive {

    template <class Node>
    struct Graph {

        using Nodes = std::vector<Node>;

        using Neighbours = std::vector<std::size_t>;

        using Arcs = std::unordered_map<std::size_t, Neighbours>;

        Nodes nodes;
        Arcs arcs;

        Neighbours neighbours(std::size_t index) const noexcept
        {
            return (arcs.count(index)) ? arcs.at(index) : Neighbours {};
        }
    };

}

