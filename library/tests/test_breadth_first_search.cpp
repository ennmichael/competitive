#include "../graph.h"
#include "../breadth_first.h"
#include "example_graphs.h"
#include "catch.hpp"

using namespace Competitive;

TEST_CASE("BreadthFirst::path_exists works")
{
    auto const solvable_1 = solvable_graph_1();
    auto const solvable_2 = solvable_graph_2();
    auto const unsolvable_1 = unsolvable_graph_1();
    auto const unsolvable_2 = unsolvable_graph_2();

    REQUIRE(BreadthFirst::path_exists(solvable_1.graph, solvable_1.start, solvable_1.end));
    REQUIRE(BreadthFirst::path_exists(solvable_2.graph, solvable_2.start, solvable_2.end));
    REQUIRE(!BreadthFirst::path_exists(unsolvable_1.graph, unsolvable_1.start, unsolvable_1.end));
    REQUIRE(!BreadthFirst::path_exists(unsolvable_2.graph, unsolvable_2.start, unsolvable_2.end));
}

TEST_CASE("BreadthFirst::find_path works")
{
    auto const solvable_1 = solvable_graph_1();
    auto const solvable_2 = solvable_graph_2();
    auto const unsolvable_1 = unsolvable_graph_1();
    auto const unsolvable_2 = unsolvable_graph_2();

    REQUIRE(BreadthFirst::find_path(solvable_1.graph, solvable_1.start, solvable_1.end) == solvable_1.nonheuristic_path);
    REQUIRE(BreadthFirst::find_path(solvable_2.graph, solvable_2.start, solvable_2.end) == solvable_2.nonheuristic_path);
    REQUIRE(BreadthFirst::find_path(unsolvable_1.graph, unsolvable_1.start, unsolvable_1.end) == unsolvable_1.nonheuristic_path);
    REQUIRE(BreadthFirst::find_path(unsolvable_2.graph, unsolvable_2.start, unsolvable_2.end) == unsolvable_2.nonheuristic_path);
}

