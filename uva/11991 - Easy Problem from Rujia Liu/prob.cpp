#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdint>

using Indices = std::unordered_map<std::uint32_t, std::vector<std::uint32_t>>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::uint32_t num_elems;
        std::uint32_t num_queries;
        std::cin >> num_elems >> num_queries;

        if (std::cin.eof())
        {
            break;
        }

        Indices indices;

        for (std::uint32_t i = 1; i <= num_elems; ++i)
        {
            std::uint32_t elem;
            std::cin >> elem;

            if (indices.count(elem))
            {
                indices.at(elem).push_back(i);
                continue;
            }

            indices.emplace(elem, std::vector<std::uint32_t> { i });
        }

        for (std::uint32_t i = 0; i < num_queries; ++i)
        {
            std::uint32_t occurence;
            std::uint32_t elem;
            std::cin >> occurence >> elem;
            --occurence;

            if (indices.count(elem))
            {
                auto const& a = indices.at(elem);
                if (a.size() <= occurence)
                {
                    std::cout << "0\n";
                }
                else
                {
                    std::cout << a[occurence] << '\n';
                }
                continue;
            }

            std::cout << "0\n";
        }
    }
}
