#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>

using Package = std::vector<int>;

using Packages = std::deque<Package>;

bool compare_packages(Package const& left, Package const& right)
{
    if (left.size() == right.size())
    {
        return left.back() > right.back();
    }

    return left.size() < right.size();
}

Packages solve(Package& bags)
{
    std::sort(bags.begin(), bags.end());

    Packages packages;

    auto const insert_package =
    [&packages](Package package)
    {
        auto i = std::lower_bound(packages.begin(), packages.end(), package, compare_packages);
        packages.insert(i, std::move(package));
    };

    for (auto const bag : bags)
    {
        bool done = false;

        for (auto package = packages.begin(); package != packages.end(); ++package)
        {
            if (package->back() < bag)
            {
                auto the_package = std::move(*package);
                packages.erase(package);
                the_package.push_back(bag);
                insert_package(std::move(the_package));
                done = true;
                break;
            }
        }

        if (!done)
        {
            insert_package(Package { bag });
        }
    }

    return packages;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t num_bags;
        std::cin >> num_bags;

        if (num_bags == 0)
        {
            break;
        }

        Package bags(num_bags);

        for (auto& bag : bags)
        {
            std::cin >> bag;
        }

        auto const packages = solve(bags);
        std::cout << packages.size() << '\n';
        for (auto const& package : packages)
        {
            if (package.size() > 1)
            {
                for (auto i = package.cbegin(); i != package.cend() - 1; ++i)
                {
                    std::cout << *i << ' ';
                }
            }
            std::cout << package.back() << '\n';
        }
    }
}
