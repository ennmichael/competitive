#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>

struct Tile {
    int left;
    int middle;
};

using Tiles = std::vector<Tile>;

void sort_tiles(Tiles& tiles)
{
    std::sort(tiles.begin(), tiles.end(),
        [](Tile const& left_tile, Tile const& right_tile)
        {
            if (left_tile.left < right_tile.left && left_tile.middle < right_tile.middle)
            {
                return true;
            }

            return left_tile.left < right_tile.left;
        }
    );
}

int solve(Tiles& tiles)
{
    sort_tiles(tiles);
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t num_tiles;
        std::cin >> num_tiles;

        Tiles tiles(num_tiles);

        for (auto& tile : tiles)
        {
            std::cin >> tile.left >> tile.middle;
        }

        std::cout << solve(tiles) << '\n';
    }

    std::cout << "*\n";
}
