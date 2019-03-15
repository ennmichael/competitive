#include <iostream>
#include <cstddef>
#include <array>
#include <vector>
#include <algorithm>

using Card = std::array<char, 2>;

using Hand = std::array<Card, 13>;

struct Suit {
    std::vector<char> ranks;
    char suit_name;
    bool stopped = false;
    bool contains_king = false;
    bool contains_queen = false;
    bool contains_jack = false;
};

Suit get_suit(Hand const& hand, char suit_name)
{
    Suit suit;
    suit.suit_name = suit_name;
    for (auto const& card : hand)
    {
        if (card[1] != suit_name)
        {
            continue;
        }

        suit.ranks.push_back(card[0]);

        if (card[0] == 'A')
        {
            suit.stopped = true;
        }
        else if (card[0] == 'K')
        {
            suit.contains_king = true;
        }
        else if (card[0] == 'Q')
        {
            suit.contains_queen = true;
        }
        else if (card[0] == 'J')
        {
            suit.contains_jack = true;
        }
    }

    if ((suit.contains_king && suit.ranks.size() >= 1) || (suit.contains_queen && suit.ranks.size() >= 2))
    {
        suit.stopped = true;
    }

    return suit;
}

void evaluate_hand(Hand const& hand)
{
    std::uint32_t points = 0;

    std::array<Suit, 4> const suits {{
        get_suit(hand, 'S'), get_suit(hand, 'H'), get_suit(hand, 'D'), get_suit(hand, 'C')
    }};

    for (auto const card : hand)
    {
        auto const rank = card[0];
        if (rank == 'A')
        {
            points += 4;
        }
        if (rank == 'K')
        {
            points += 3;
        }
        if (rank == 'Q')
        {
            points += 2;
        }
        if (rank == 'J')
        {
            points += 1;
        }
    }

    for (auto const& suit : suits)
    {
        if (suit.contains_king && suit.ranks.size() == 0)
        {
            --points;
        }
        if (suit.contains_queen && suit.ranks.size() <= 1)
        {
            --points;
        }
        if (suit.contains_jack && suit.ranks.size() <= 2)
        {
            --points;
        }
    }

    if (points >= 16 && std::all_of(suits.cbegin(), suits.cend(), [](Suit const& suit) { return suit.stopped; }))
    {
        std::cout << "BID NO-TRUMP\n";
        return;
    }

    for (auto const& suit : suits)
    {
        if (suit.ranks.size() == 2)
        {
            ++points;
        }
        else if (suit.ranks.size() == 1)
        {
            points += 2;
        }
        else if (suit.ranks.size() == 0)
        {
            points += 2;
        }
    }

    if (points >= 14)
    {
        char const suit_name =
            std::max_element(suits.cbegin(), suits.cend(),
                    [](Suit const& suit1, Suit const& suit2) { return suit1.ranks.size() < suit2.ranks.size(); })->suit_name;
        std::cout << "BID " << suit_name << '\n';
    }
    else
    {
        std::cout << "PASS\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Hand hand;
    while (true)
    {
        hand = {};
        for (std::size_t i = 0; i < hand.size(); ++i)
        {
            std::cin >> hand[i].data();
            if (hand[i][0] == '\0')
            {
                return 0;
            }
        }
        evaluate_hand(hand);
        std::cout.flush();
    }
}
