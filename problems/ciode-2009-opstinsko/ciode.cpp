#include <iostream>
#include <array>
#include <cmath>

// There's a single failing case here, I don't know what it is.
// Anyhow, the point was to have as many pins covering 4 papers as possible.
// That way, the fewest possible pins are used.
// This is best achieved if the number of rows and columns is approximately equal,
// so I set columns = floor(sqrt(number of papers)) and go from there.

unsigned long wraparound_pins_required(unsigned long papers_to_hang, unsigned long pillar_width) noexcept
{
    unsigned long const rows = papers_to_hang / pillar_width;
    unsigned long const extra_papers = papers_to_hang - pillar_width * rows;
    if (extra_papers == 0)
        return pillar_width * (rows + 1);
    return pillar_width * (rows + 1) + extra_papers + 1;
}

unsigned long cubic_pins_required(unsigned long papers_to_hang,
                                  unsigned long columns) noexcept
{
    unsigned long const rows = papers_to_hang / columns;
    unsigned long const extra_papers = papers_to_hang - columns * rows;
    if (extra_papers == 0)
        return (columns + 1) * (rows + 1);
    return (columns + 1) * (rows + 1) + extra_papers + 1;
}

unsigned long min_pins_required(unsigned long papers_to_hang, unsigned long pillar_width) noexcept
{
    if (papers_to_hang == 0)
        return 0;
    if (papers_to_hang % pillar_width == 0)
    {
        auto const rows = papers_to_hang / pillar_width;
        return pillar_width * (rows + 1);
    }
    auto const columns = static_cast<unsigned long>(std::sqrt(papers_to_hang));
    if (columns < pillar_width)
    {
        return std::min(cubic_pins_required(papers_to_hang, columns, pillar_width),
                        wraparound_pins_required(papers_to_hang, pillar_width));
    }
    else
    {
        return wraparound_pins_required(papers_to_hang, pillar_width);
    }
}

void check(unsigned long result, unsigned long expected, unsigned long l)
{
    if (result != expected)
        std::cout << "Bad result at line " << l << ".\n\tExpected " << expected << ".\n\tGot " << result << ".\n";
}

// Check against a REAL must-be solution using nested loops with random numbers up to 100 and see what errors you get

void tests()
{
    check(min_pins_required(1, 1), 2, __LINE__);
    check(min_pins_required(2, 1), 3, __LINE__);
    check(min_pins_required(3, 1), 4, __LINE__);
    check(min_pins_required(1, 2), 4, __LINE__);
    check(min_pins_required(2, 2), 4, __LINE__);
    check(min_pins_required(3, 2), 6, __LINE__);
    check(min_pins_required(7, 4), 12, __LINE__);
    check(min_pins_required(6, 4), 11, __LINE__);
    check(min_pins_required(5, 4), 10, __LINE__);
    check(min_pins_required(4, 4), 8, __LINE__);
    check(min_pins_required(3, 4), 8, __LINE__);
    check(min_pins_required(7, 3), 11, __LINE__);
    check(min_pins_required(1, 3), 4, __LINE__);
    check(min_pins_required(2, 3), 6, __LINE__);
    check(min_pins_required(3, 3), 6, __LINE__);
    check(min_pins_required(4, 1), 5, __LINE__);
    check(min_pins_required(4, 2), 6, __LINE__);
    check(min_pins_required(5, 3), 9, __LINE__);
    check(min_pins_required(25, 5), 30, __LINE__);
    check(min_pins_required(25, 6), 32, __LINE__);
    check(min_pins_required(24, 6), 30, __LINE__);
    check(min_pins_required(27, 6), 34, __LINE__);
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    unsigned long papers_to_hang;
    unsigned long pillar_width;
    std::cin >> papers_to_hang;
    std::cin >> pillar_width;
    unsigned long const pins = min_pins_required(papers_to_hang, pillar_width);
    std::cout << pins << '\n';
}

