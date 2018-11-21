#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <array>

// The trick was to realize that 1) the order of rotations doesn't matter, 
// and 2) that rotations may be calculated modulus 90 deg
// (i.e., four 90 deg rotations is 460 deg, which is nothing).

unsigned int constexpr max_rotations = 4;

using Label = unsigned int;

using Ringshot = std::vector<std::vector<Label>>;

void rotate(Ringshot& ringshot, unsigned int platform, unsigned int rotations)
{
    auto const q = ringshot.size() - 1;
    switch (rotations)
    {
        case 1:
            for (unsigned int i = 0; i < q - 2 * platform; ++i)
            {
                auto const qmp = q - platform;
                auto const qmpmi = qmp - i;
                auto const ipp = i + platform;
                auto const t = ringshot[ipp][qmp];
                ringshot[ipp][qmp] = ringshot[p][ipp];
                ringshot[platform][ipp] = ringshot[qmpmi][platform];
                ringshot[qmpmi][platform] = ringshot[qmp][qmpmi];
                ringshot[qmp][qmpmi] = t; // ringshot[ipp][qmp]
            }
            break;
        case 2:
            {
                auto const qmp = q - platform;
                for (unsigned int i = 0; i < ringshot.size() - 2 * platform; ++i)
                    std::swap(ringshot[platform][platform + i], ringshot[qmp][qmp - i]);
                for (unsigned int i = 1; i < q - 2 * platform; ++i)
                    std::swap(ringshot[i + platform][qmp], ringshot[qmp - i][platform]);
            }
            break;
        case 3:
            for (unsigned int i = 0; i < q - 2 * platform; ++i)
            {
                auto const qmp = q - platform;
                auto const qmpmi = qmp - i;
                auto const ipp = i + platform;
                auto const t = ringshot[ipp][qmp];
                ringshot[ipp][qmp] = ringshot[qmp][qmpmi];
                ringshot[qmp][qmpmi] = ringshot[qmpmi][platform];
                ringshot[qmpmi][platform] = ringshot[platform][ipp];
                ringshot[platform][ipp] = t;
            }
            break;
    }
}

using Commands = std::array<unsigned int, 350>;
// Commands implemented as a platform -> num_rotations map.

Commands input_commands() // This is the most important part.
{
    Commands commands {};
    unsigned int K;
    std::cin >> K;
    for (unsigned int i = 0; i < K; ++i)
    {
        unsigned int platform;
        std::cin >> platform;
        unsigned int rotations;
        std::cin >> rotations;
        commands[platform - 1] = (commands[platform - 1] + rotations) % max_rotations; 
        // Never do redundant work!
        // Rotating 4 times is ultimately equivalent to no rotations.
        // Rotating 5 times is ultimately equivalent 1 rotation.
        // Rotating 6 times is ultimately equivalent 2 rotations.
        // Therefore, rotations happen modulus 4.
        //
        // Also, add up the rotations - if one line specifies to rotate
        // platform P R1 times, and some other line specifies to rotate
        // the same platform P R2 times, overall platform P should be
        // rotated R1 + R2 times.
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
    auto ringshot = input_ringshot();
    auto commands = input_commands();
    unsigned int const max_platform = std::round(ringshot.size() / 2.0);
    for (unsigned int platform = 0; platform < max_platform - 1; ++platform)
    {
        // This next line is also an important optimization.
        // It says that every more inner platform should be rotated as many times as specified
        // plus the number of rotations of platforms outer to it - everything is still
        // modulus max rotations.
        commands[platform + 1] = (commands[platform + 1] + commands[platform]) % max_rotations;
        rotate(ringshot, platform, commands[platform]);
    }
    rotate(ringshot, max_platform - 1, commands[max_platform - 1]);
    output(ringshot);
}

