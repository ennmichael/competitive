#pragma once

#include "common.h"
#include <cmath>

namespace Competitive {

    // Play with this a bit, see if there's ever any difference between what you get when you
    // use the Stirling factorial and what you get when you use a real factorial
    template <class Integer>
    Integer stirling_factorial(Integer n) noexcept
    {
        return std::ceil(std::sqrt(2 * pi * n) * std::pow(n / e, n));
    }

    template <class Integer>
    Integer factorial(Integer n) noexcept
    {
        return stirling_factorial(n);
    }
}

