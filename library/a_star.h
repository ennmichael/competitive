#pragma once

#include <unordered_map>
#include <algorithm>
#include <vector>

namespace Competitive {

    struct Point {
        int x;
        int y;

        int sqr_distance(Point other)
        {
            return x * other.x + y * other.y;
        }
    };

    inline bool operator==(Point a, Point b) noexcept
    {
        return a.x == b.x && a.y == b.y;
    }

    inline bool operator!=(Point a, Point b) noexcept
    {
        return !(a == b);
    }

    struct ::std::hash<Point> {
        std::size_t operator()(Point p) const noexcept
        {
            return p.x ^ p.y;
        }
    };

    struct ScoreComparer {
        bool operator()(EvaluatedPoint a, EvaluatedPoint b) const noexcept
        {
            return a.score < b.score;
        }
    };

    struct MazeGraph {
        std::vector<Point> nodes;
        std::vector<std::vector<int>> adjacency_matrix;
    };

    // TODO Extends this algorithm to also determine the path
    
    inline std::array<Point, 4> neighbours(Point p) noexcept
    {
        return
        {
            Point(p.x + 1, p.y),
            Point(p.x - 1, p.y),
            Point(p.x, p.y + 1),
            Point(p.x, p.y - 1),
        };
    }

    inline bool path_exists(MazeGraph const& maze, Point start, Point end) noexcept
    {
        std::unordered_map<Point, int> scores;
        std::vector<EvaluatedPoint> open_points {EvaluatedPoint {start, 0}};
        std::vector<EvaluatedPoint> closed_points;

        while (!open_points.empty())
        {
            auto const current_point = *std::min_element(open_points.cbegin(), open_points.cend());
            for (auto const neighbour : neighbours(current_point))
            {
                if (!closed_points.contains(neighbour) && !open_points.contains(neighbour))
                    closed_points.push_back(neighbour);
            }
        }
    }

}

