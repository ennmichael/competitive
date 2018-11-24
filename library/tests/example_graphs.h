#pragma once

#include "../graph.h"
#include <functional>

using namespace Competitive;

struct ExampleGraph {
    Graph<int> graph;
    int start;
    int end;
    Path nonheuristic_path;
    Path heuristic_path;
};

inline int example_heuristic(Graph<int> const& graph, std::size_t from, std::size_t to)
{
    return graph.nodes[from] ^ graph.nodes[to];
}

inline ExampleGraph solvable_graph_1()
{
    Graph<int> graph;
    for (int i = 0; i < 10; ++i)
        graph.nodes.push_back(i);
    graph.arcs.insert({0, {1}});
    graph.arcs.insert({1, {2}});
    graph.arcs.insert({2, {3}});
    graph.arcs.insert({3, {5}});
    graph.arcs.insert({4, {1, 6, 8}});
    graph.arcs.insert({5, {4}});
    graph.arcs.insert({6, {7}});
    graph.arcs.insert({7, {8, 9}});
    graph.arcs.insert({8, {7, 9}});
    return {
        graph, 0, 9,
        {9, 8, 4, 5, 3, 2, 1, 0},
        {} // XXX
    };
}

inline ExampleGraph solvable_graph_2()
{
    Graph<int> graph;
    for (int i = 0; i < 7; ++i)
        graph.nodes.push_back(i);
    graph.arcs.insert({0, {1, 4}});
    graph.arcs.insert({1, {2}});
    graph.arcs.insert({2, {3, 5}});
    graph.arcs.insert({3, {6}});
    graph.arcs.insert({4, {0, 2}});
    graph.arcs.insert({5, {2, 3, 4}});
    graph.arcs.insert({6, {5}});
    return {
        graph, 0, 6,
        {6, 3, 2, 1, 0},
        {} // XXX
    };
}

inline ExampleGraph unsolvable_graph_1()
{
    Graph<int> graph;
    for (int i = 0; i < 10; ++i)
        graph.nodes.push_back(i);
    graph.arcs.insert({0, {1}});
    graph.arcs.insert({1, {2}});
    graph.arcs.insert({2, {3}});
    graph.arcs.insert({3, {5}});
    graph.arcs.insert({4, {1, 5, 6, 8}});
    graph.arcs.insert({6, {7}});
    graph.arcs.insert({7, {8, 9}});
    graph.arcs.insert({8, {7, 9}});
    return {
        graph, 0, 9,
        {},
        {}
    };
}

inline ExampleGraph unsolvable_graph_2()
{
    Graph<int> graph;
    for (int i = 0; i < 7; ++i)
        graph.nodes.push_back(i);
    graph.arcs.insert({0, {1, 4}});
    graph.arcs.insert({1, {2}});
    graph.arcs.insert({2, {3, 5}});
    graph.arcs.insert({4, {0, 2}});
    graph.arcs.insert({5, {2, 3, 4}});
    graph.arcs.insert({6, {5}});
    return {
        graph, 0, 6,
        {},
        {}
    };
}

