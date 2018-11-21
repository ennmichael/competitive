#include <iostream>
#include <string>
#include <cstddef>
#include <cstring>

// This one's just easy

std::size_t constexpr max_characters = 4 * 1024 * 1024;

std::string read_input() noexcept
{
    std::string input;
    input.reserve(max_characters);
    std::getline(std::cin, input);
    return input;
}

using StringIterator = std::string::const_iterator;

using Count = unsigned long;

bool is_palindrome(StringIterator begin, StringIterator end) noexcept
{
    --end;
    while (true)
    {
        if (begin >= end)
            return true;
        if (std::tolower(*begin) != std::tolower(*end))
            return false;
        ++begin;
        --end;
    }
}

Count count_palindromes(StringIterator begin, StringIterator end) noexcept
{
    Count count = 0;
    for (auto i = begin; i < end; ++i)
    {
        if (!std::isalnum(*i))
        {
            if (begin != i && is_palindrome(begin, i))
                ++count;
            begin = i + 1;
        }
    }
    if (begin != end && is_palindrome(begin, end))
        ++count;
    return count;
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);
    auto const sentence = read_input();
    std::cout << count_palindromes(sentence.cbegin(), sentence.cend()) << '\n';
}

