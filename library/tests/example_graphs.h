#pragma once

#include "../graph.h"
#include <functional>

using namespace Competitive;

struct ExampleAdjacencyList {
    using HeuristicFunction = std::function<int(AdjacencyList<int> const&, std::size_t, std::size_t)>;

    AdjacencyList<int> graph;
    int start;
    int end;
    HeuristicFunction heuristic_function;
    Path nonheuristic_path;
    Path heuristic_path;
};

inline float heuristic_function_1(AdjacencyList<int> const&, std::size_t from, std::size_t to)
{
    if (to != 9)
        throw std::runtime_error {"Incorrect to argument"};
    switch (from)
    {
        case 0: return 11.66f;
        case 1: return 11.18f;
        case 2: return 10.77f;
        case 3: return 10.44f;
        case 4: return 4.12f;
        case 5: return 10.04f;
        case 6: return 2.23f;
        case 7: return 1.73f;
        case 8: return 1.0f;
    }
    throw std::runtime_error {"Incorrect from argument"};
}

inline ExampleAdjacencyList solvable_graph_1()
{
    AdjacencyList<int> graph;
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
        heuristic_function_1,
        {9, 8, 4, 5, 3, 2, 1, 0},
        {9, 8, 4, 5, 3, 2, 1, 0}
    };
}

inline float heuristic_function_2(AdjacencyList<int> const&, std::size_t from, std::size_t to)
{
    if (to != 6)
        throw std::runtime_error {"Incorrect to argument"};
    switch (from)
    {
        case 0: return 4.0f;
        case 1: return 5.65f;
        case 2: return 2.0f;
        case 3: return 1.0f;
        case 4: return 3.0f;
        case 5: return 5.0f;
    }
    throw std::runtime_error {"Incorrect from argument"};
}

inline ExampleAdjacencyList solvable_graph_2()
{
    AdjacencyList<int> graph;
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
        heuristic_function_2,
        {6, 3, 2, 1, 0},
        {6, 3, 2, 4, 0}
    };
}

inline ExampleAdjacencyList unsolvable_graph_1()
{
    AdjacencyList<int> graph;
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
        heuristic_function_1,
        {}, {}
    };
}

inline ExampleAdjacencyList unsolvable_graph_2()
{
    AdjacencyList<int> graph;
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
        heuristic_function_2,
        {}, {}
    };
}

