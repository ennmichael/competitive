#include "../graph.h"
#include "../a_star.h"
#include "catch.hpp"
#include "example_graphs.h"

using namespace Competitive;

TEST_CASE("AStar::find_path works")
{
    auto const solvable_1 = solvable_graph_1();
    auto const solvable_2 = solvable_graph_2();
    auto const unsolvable_1 = unsolvable_graph_1();
    auto const unsolvable_2 = unsolvable_graph_2();

    REQUIRE(AStar::find_path(solvable_1.graph, solvable_1.start,
                             solvable_1.end, solvable_1.heuristic_function) == solvable_1.heuristic_path);
    REQUIRE(AStar::find_path(solvable_2.graph, solvable_2.start,
                             solvable_2.end, solvable_2.heuristic_function) == solvable_2.heuristic_path);

    REQUIRE(AStar::find_path(unsolvable_1.graph, unsolvable_1.start,
                             unsolvable_1.end, unsolvable_1.heuristic_function) == unsolvable_1.heuristic_path);
    REQUIRE(AStar::find_path(unsolvable_2.graph, unsolvable_2.start,
                             unsolvable_2.end, unsolvable_2.heuristic_function) == unsolvable_2.heuristic_path);
}

