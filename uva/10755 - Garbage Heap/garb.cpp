#include <iostream>
#include <array>

struct Cube {
    std::array<std::array<std::array<long, 22>, 22>, 22> content;
    std::size_t width;
    std::size_t height;
    std::size_t depth;

    void input()
    {
        std::cin >> width >> height >> depth;
        for (std::size_t x = 0; x < width; ++x)
        {
            for (std::size_t y = 0; y < height; ++y)
            {
                for (std::size_t z = 0; z < depth; ++z)
                {
                    std::cin >> content[x][y][z];
                }
            }
        }
    }

    void preprocess()
    {
        for (std::size_t x = 0; x < width; ++x)
        {
            for (std::size_t y = 0; y < height; ++y)
            {
                for (std::size_t z = 0; z < depth; ++z)
                {
                }
            }
        }
    }

    long solve()
    {
        preprocess();
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_cases;
    std::cin >> num_cases;

    for (int i = 0; i < num_cases; ++i)
    {
        Cube cube;
        cube.input();
        std::cout << cube.solve() << '\n';
    }
}
