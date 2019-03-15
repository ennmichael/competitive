#include <iostream>
#include <vector>
#include <cstddef>

struct Soldier;

using Soldiers = std::vector<Soldier>;

struct Soldier {
    std::int64_t left_buddy;
    std::int64_t right_buddy;
};

void print_buddy(std::int64_t buddy)
{
    if (buddy == -1)
    {
        std::cout << '*';
    }
    else
    {
        std::cout << (buddy + 1);
    }
}

void update_buddies(Soldiers& soldiers, std::size_t first_killed, std::size_t last_killed)
{
    if (soldiers[first_killed].left_buddy != -1)
    {
        auto const left_buddy = soldiers[first_killed].left_buddy;
        soldiers[left_buddy].right_buddy = soldiers[last_killed].right_buddy;
    }

    if (soldiers[last_killed].right_buddy != -1)
    {
        auto const right_buddy = soldiers[last_killed].right_buddy;
        soldiers[right_buddy].left_buddy = soldiers[first_killed].left_buddy;
    }

    print_buddy(soldiers[first_killed].left_buddy);
    std::cout << ' ';
    print_buddy(soldiers[last_killed].right_buddy);
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::size_t num_soldiers;
        std::uint32_t num_reports;
        std::cin >> num_soldiers >> num_reports;
        if (num_soldiers == 0 && num_reports == 0)
        {
            break;
        }
        Soldiers soldiers(num_soldiers);
        for (std::size_t i = 0; i < num_soldiers; ++i)
        {
            soldiers[i].left_buddy = i - 1;
            if (i == num_soldiers - 1)
            {
                soldiers[i].right_buddy = -1;
            }
            else
            {
                soldiers[i].right_buddy = i + 1;
            }
        }
        for (std::uint32_t i = 0; i < num_reports; ++i)
        {
            std::size_t first_killed;
            std::size_t last_killed;
            std::cin >> first_killed >> last_killed;
            first_killed -= 1;
            last_killed -= 1;
            update_buddies(soldiers, first_killed, last_killed);
        }
        std::cout << "-\n";
    }
}
