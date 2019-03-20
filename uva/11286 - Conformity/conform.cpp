#include <iostream>
#include <unordered_map>
#include <array>
#include <algorithm>

using Courses = std::array<std::uint32_t, 5>;

using Stats = std::unordered_map<Courses, std::uint32_t>;

template <>
struct std::hash<Courses> {
    std::size_t operator()(Courses const& courses) const noexcept
    {
        return courses[0] ^ courses[1] ^ courses[2] ^ courses[3] ^ courses[4];
    }
};

int main()
{
    while (true)
    {
        Stats stats;
        std::uint32_t num_frosh;
        std::cin >> num_frosh;
        if (num_frosh == 0)
        {
            break;
        }
        for (std::uint32_t i = 0; i < num_frosh; ++i)
        {
            Courses courses;
            for (auto& course : courses)
            {
                std::cin >> course;
            }
            std::sort(courses.begin(), courses.end());
            if (stats.count(courses))
            {
                ++stats.at(courses);
            }
            else
            {
                stats.emplace(courses, 1);
            }
        }
        auto const most_popular = std::max_element(
            stats.cbegin(), stats.cend(),
            [](Stats::value_type const& a, Stats::value_type const& b) { return a.second < b.second; })->second;
        std::uint32_t result = 0;
        for (auto const e : stats)
        {
            if (e.second == most_popular)
            {
                result += e.second;
            }
        }
        std::cout << result << '\n';
    }
}
