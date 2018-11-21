#include <cstdio>
#include <iostream>
#include <iomanip>

using FloatingPoint = double;

FloatingPoint constexpr unity = 1;

FloatingPoint equivalent_capacitance(unsigned long n)
{
    FloatingPoint result = 2;
    for (unsigned long j = 2; j <= (n - 2) * 2; j += 2)
        result = unity / (result + j) + 2;
    return 2 * result;
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);
    unsigned long n;
    std::cin >> n;
    std::cout << std::setprecision(10) << std::fixed << equivalent_capacitance(n) << '\n';
}

