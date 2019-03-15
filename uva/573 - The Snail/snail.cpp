#include <iostream>
#include <cstddef>
#include <cmath>

struct Problem {
    std::int32_t well_height;
    std::int32_t climb;
    std::int32_t fall;
    std::int32_t fatigue;
    std::int32_t position = 0;

    bool load()
    {
        std::cin >> well_height >> climb >> fall >> fatigue;
        fatigue *= climb;
        well_height *= 100;
        climb *= 100;
        fall *= 100;
        position = 0;
        return well_height != 0;
    }

    void solve()
    {
        for (std::int32_t day = 1; ; ++day)
        {
            position += climb;

            if (position > well_height)
            {
                std::cout << "success on day " << day << '\n';
                break;
            }

            position -= fall;

            if (position < 0)
            {
                std::cout << "failure on day " << day << '\n';
                break;
            }

            climb = std::max(static_cast<int32_t>(0), climb - fatigue);
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Problem problem;
    while (problem.load())
    {
        problem.solve();
    }
}
