#pragma once

namespace Competitive {

    std::array constexpr 

    template <class Integer>
    bool strong_prime_test(Integer n) noexcept
    {

    }

    template <class Integer>
    bool lucas_prime_test(Integer n) noexcept
    {

    }

    template <class Integer>
    bool baillie_psw_test(Integer n) noexcept
    {
        return strong_prime_test(n) && lucas_prime_test(n);
    }

    template <class Integer>
    bool is_prime(Integer n) noexcept
    {
        return baillie_psw_test(n);
    }

}

