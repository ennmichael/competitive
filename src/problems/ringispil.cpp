#include <iostream>
#include <vector>
#include <utility>
#include <array>

// XXX Represent the ringshot as an array of arrays?
// XXX Don't forget to use vector.reserve
// XXX Edge case for N = 1 ?
// XXX Upon completion, copy-paste the problem text to here so it can be revisited later

using Label = unsigned int;

using Ringshot = std::vector<std::vector<Label>>;

void rotate(Ringshot& ringshot, unsigned int platform, unsigned int rotations)
{
    auto const q = ringshot.size() - 1;
    switch (rotations % 4)
    {
        case 1:
            for (unsigned int p = platform; p < q - 1; ++p)
            {
                for (unsigned int i = 0; i < q - 2 * p; ++i)
                {
                    auto const qmp = q - p;
                    auto const qmpmi = qmp - i;
                    auto const ipp = i + p;
                    auto& pivot = ringshot[p][ipp];
                    std::swap(pivot, ringshot[ipp][qmp]);
                    std::swap(pivot, ringshot[qmp][qmpmi]);
                    std::swap(pivot, ringshot[qmpmi][p]);
                }
            }
            break;
        case 2:
            for (unsigned int p = platform; p < q - 1; ++p)
            {
                auto const qmp = q - p;
                for (unsigned int i = 0; i < ringshot.size() - 2 * p; ++i)
                    std::swap(ringshot[p][p + i], ringshot[qmp][qmp - i]);
                for (unsigned int i = 1; i < q - 2 * p; ++i)
                    std::swap(ringshot[i + p][qmp], ringshot[qmp - i][p]);
            }
            break;
        case 3:
            for (unsigned int p = platform; p < q - 1; ++p)
            {
                for (unsigned int i = 0; i < q - 2 * p; ++i)
                {
                    auto const qmp = q - p;
                    auto const qmpmi = qmp - i;
                    auto const ipp = i + p;
                    auto& pivot = ringshot[p][ipp];
                    std::swap(pivot, ringshot[qmpmi][p]);
                    std::swap(pivot, ringshot[qmp][qmpmi]);
                    std::swap(pivot, ringshot[ipp][qmp]);
                }
            }
            break;
    }
}

void nice_print(Ringshot const& ringshot)
{
    for (auto const& row : ringshot)
    {
        for (auto const label : row)
        {
            std::cout << label << ' ';
        }
        std::cout << '\n';
    }
}

struct Command {
    unsigned int platform_to_rotate;
    unsigned int rotations;
};

struct Commands {
    std::array<Command, 100'000> commands;
    unsigned int count;
};

Commands input_commands()
{
    // XXX Extra optimization for same platforms: add up the rotations
    Commands commands;
    std::cin >> commands.count;
    for (unsigned int i = 0; i < commands.count; ++i)
    {
        std::cin >> commands.commands[i].platform_to_rotate;
        std::cin >> commands.commands[i].rotations;
    }
    return commands;
}

Ringshot input_ringshot()
{
    Ringshot result;
    unsigned int N;
    std::cin >> N;
    result.reserve(N);
    for (unsigned int i = 0; i < N; ++i)
    {
        result.push_back(std::vector<Label>{});
        result.back().reserve(N);
        for (unsigned int j = 0; j < N; ++j)
        {
            Label label;
            std::cin >> label;
            result.back().push_back(label);
        }
    }
    return result;
}


void output(Ringshot const& ringshot)
{
    for (auto const& row : ringshot)
    {
        for (auto const label : row)
            std::cout << label << ' ';
        std::cout << '\n';
    }
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);
    auto ringshot = input_ringshot();
    auto const commands = input_commands();
    for (unsigned int i = 0; i < commands.count; ++i)
    {
        auto const command = commands.commands[i];
        rotate(ringshot, command.platform_to_rotate - 1, command.rotations);
    }
    output(ringshot);
}

