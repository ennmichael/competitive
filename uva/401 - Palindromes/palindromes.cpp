#include <iostream>
#include <cstddef>
#include <array>
#include <string>

using Mirrors = std::array<char, 'Z' - '1' + 1>;

bool check_is_palindrome(std::string const& str)
{
    for (std::size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] != str[str.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

std::string mirrored(std::string str, Mirrors const& mirrors)
{
    for (auto& c : str)
    {
        auto const replacement = mirrors[c - '1'];
        if (replacement == '\0')
        {
            return "";
        }
        c = replacement;
    }
    return str;
}

bool check_is_mirrored(std::string const& str, Mirrors const& mirrors)
{
    auto const m = mirrored(str, mirrors);
    if (m == "")
    {
        return false;
    }
    for (std::size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] != m[m.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void solve(std::string const& input, Mirrors const& mirrors)
{
    auto const is_palindrome = check_is_palindrome(input);
    auto const is_mirrored = check_is_mirrored(input, mirrors);

    std::cout << input;
    
    if (!is_palindrome && !is_mirrored)
    {
        std::cout << " -- is not a palindrome.\n\n";
    }

    if (is_palindrome && !is_mirrored)
    {
        std::cout << " -- is a regular palindrome.\n\n";
    }
    
    if (!is_palindrome && is_mirrored)
    {
        std::cout << " -- is a mirrored string.\n\n";
    }

    if (is_palindrome && is_mirrored)
    {
        std::cout << " -- is a mirrored palindrome.\n\n";
    }
}

int main()
{
    Mirrors mirrors {{}};
    mirrors['A' - '1'] = 'A';
    mirrors['E' - '1'] = '3';
    mirrors['H' - '1'] = 'H';
    mirrors['I' - '1'] = 'I';
    mirrors['J' - '1'] = 'L';
    mirrors['L' - '1'] = 'J';
    mirrors['M' - '1'] = 'M';
    mirrors['O' - '1'] = 'O';
    mirrors['S' - '1'] = '2';
    mirrors['T' - '1'] = 'T';
    mirrors['U' - '1'] = 'U';
    mirrors['V' - '1'] = 'V';
    mirrors['W' - '1'] = 'W';
    mirrors['X' - '1'] = 'X';
    mirrors['Y' - '1'] = 'Y';
    mirrors['Z' - '1'] = '5';
    mirrors['1' - '1'] = '1';
    mirrors['2' - '1'] = 'S';
    mirrors['3' - '1'] = 'E';
    mirrors['5' - '1'] = 'Z';
    mirrors['8' - '1'] = '8';

    std::string input;
    while (true)
    {
        std::cin >> input;
        if (std::cin.eof())
        {
            break;
        }
        solve(input, mirrors);
    }
}
