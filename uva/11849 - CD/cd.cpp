#include <iostream>
#include <unordered_set>

int main()
{
    while (true)
    {
        std::unordered_set<std::uint32_t> cds;
        std::uint32_t result = 0;
        std::uint32_t num_cds1;
        std::uint32_t num_cds2;
        std::cin >> num_cds1 >> num_cds2;
        if (num_cds1 == 0 && num_cds2 == 0)
        {
            break;
        }
        for (std::uint32_t i = 0; i < num_cds1; ++i)
        {
            std::uint32_t cd;
            std::cin >> cd;
            cds.insert(cd);
        }
        for (std::uint32_t i = 0; i < num_cds2; ++i)
        {
            std::uint32_t cd;
            std::cin >> cd;
            auto const it = cds.find(cd);
            if (it != cds.end())
            {
                cds.erase(it);
                ++result;
            }
        }
        std::cout << result << '\n';
    }
}
