#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using Primes = std::array<unsigned long, 86>;

Primes constexpr primes {443, 439, 433, 431, 421, 419, 409, 401, 397, 389, 383, 379, 373, 367, 359, 353, 349, 347, 337, 331, 317, 313, 311, 307, 293, 283, 281, 277, 271, 269, 263, 257, 251, 241, 239, 233, 229, 227, 223, 211, 199, 197, 193, 191, 181, 179, 173, 167, 163, 157, 151, 149, 139, 137, 131, 127, 113, 109, 107, 103, 101, 97, 89, 83, 79, 73, 71, 67, 61, 59, 53, 47, 43, 41, 37, 31, 29, 23, 19, 17, 13, 11, 7, 5, 3, 2};

using Funds = std::vector<unsigned long>;

using Winners = std::vector<unsigned long>;

struct Reward {
    Primes::const_iterator num_winners;
    unsigned long payout;
};

using Rewards = std::vector<Reward>;

struct RewardsChoice {
    Rewards rewards;
    Rewards::const_iterator current_reward = rewards.cbegin();
};

Primes::const_iterator find_factor(Primes::const_iterator begin,
                                   Primes::const_iterator end,
                                   unsigned long n) noexcept
{
    for (; begin != end; ++begin)
    {
        if (*begin > n)
            return end;
        if (n % *begin == 0)
            return begin;
    }
    return end;
}

std::vector<unsigned long> find_factors(unsigned long n) noexcept
{
}

using PossibleRewards = std::vector<RewardChoice>;

bool rewards_are_valid(PossibleRewards const& possible_rewards) noexcept
{
}

void next_combination(PossibleRewards& possible_rewards) noexcept
{

}

std::vector<RewardsChoice> find_rewards(Funds const& funds) noexcept
{
    PossibleRewards possible_rewards;
    possible_rewards.reserve(funds.size());
    for (auto const fund : funds)
    {
        
        if (num_winners == primes.cend())
            return {};
        RewardsChoice choice {find_factors(fund)};
        possible_rewards.push_back(choice);
    }
    while (!rewards_are_valid(possible_rewards))
        next_combination(possible_rewards);
    return possible_rewards;
}

Funds load_funds() noexcept
{
    unsigned long num_funds;
    std::cin >> num_funds;
    Funds funds;
    funds.reserve(num_funds);
    for (unsigned long i = 0; i < num_funds; ++i)
    {
        unsigned long f;
        std::cin >> f;
        funds.push_back(f);
    }
    return funds;
}

int main(int, char**)
{
    auto const funds = load_funds();
    auto const rewards = find_rewards(funds);
    if (rewards.size() == 0)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        for (auto const reward : rewards)
            std::cout << *reward.num_winners << ' ';
        std::cout << '\n';
    }
}

