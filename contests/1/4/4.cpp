#include <iostream>
#include <array>
#include <string>

std::array<char const*, 4> constexpr directions {{ "north", "east", "south", "west" }};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int direction = 0;
    int num_commands;
    std::cin >> num_commands;
    std::string command;
    for (int i = 0; i < num_commands; ++i)
    {
        std::cin >> command;
        if (command[0] == 'r')
        {
            ++direction;
        }
        else if (command[0] == 'l')
        {
            --direction;
        }
        else if (command[0] == 'b')
        {
            ++direction;
            ++direction;
        }
    }

    direction %= 4;

    if (direction < 0)
    {
        direction += 4;
    }

    std::cout << directions[direction] << '\n';
}
