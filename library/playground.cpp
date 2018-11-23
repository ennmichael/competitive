#include "graph.h"
#include "breadth_first.h"
#include <iostream>

using namespace Competitive;

using ID = int;

using IDGraph = Graph<ID>;

using Neighbours = IDGraph::Neighbours;

int main(int, char**)
{
    IDGraph graph;
    for (ID i = 0; i < 10; ++i)
        graph.nodes.push_back(i);

    graph.arcs.insert({0, Neighbours {1}});
    graph.arcs.insert({1, Neighbours {2}});
    graph.arcs.insert({2, Neighbours {3}});
    graph.arcs.insert({3, Neighbours {5}});
    graph.arcs.insert({4, Neighbours {1, 6, 8}});
    graph.arcs.insert({5, Neighbours {4}});
    graph.arcs.insert({6, Neighbours {7}});
    graph.arcs.insert({7, Neighbours {8, 9}});
    graph.arcs.insert({8, Neighbours {7, 9}});

    std::cout << BreadthFirst::path_exists(graph, 0, 9) << '\n';
}

