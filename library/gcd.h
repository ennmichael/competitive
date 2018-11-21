#pragma once

#include "utils.h"

namespace Competitive {

    template <class Integer>
    Integer euclidean_gcd(Integer a, Integer b) noexcept
    {
        Integer c;
        Integer d;
        minmax(a, b, c, d);

        do
        {
            auto const t = c;
            c = d % c;
            d = t;
        } while (c != 0);

        return d;
    }

    template <class Integer>
    Integer gcd(Integer a, Integer b) noexcept
    {
        return euclidean_gcd(a, b);
    }

    template <class Integer>
    Integer lcm(Integer a, Integer b) noexcept // Lowest common multiplier
    {
        return a / gcd(a, b) * b;
    }

}

