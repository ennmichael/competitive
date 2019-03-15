#include <iostream>
#include <array>
#include <string>
#include <cstddef>
#include <unordered_map>

std::uint32_t payment_for_line(std::string const& line, std::unordered_map<char, std::uint32_t> const& payment_table)
{
    std::uint32_t payment = 0;
    for (auto const c : line)
    {
        if (payment_table.find(c) == payment_table.cend())
        {
            continue;
        }
        payment += payment_table.at(c);
    }
    return payment;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint32_t num_cases;
    std::cin >> num_cases;
    for (std::uint32_t i = 0; i < num_cases; ++i)
    {
        std::uint32_t payment = 0;
        std::unordered_map<char, std::uint32_t> payment_table;
        std::uint32_t table_size;
        std::cin >> table_size;
        for (std::uint32_t j = 0; j < table_size; ++j)
        {
            char c;
            std::uint32_t cents;
            std::cin >> c >> cents;
            payment_table.emplace(c, cents);
        }
        std::uint32_t num_lines;
        std::cin >> num_lines;
        std::string line;
        line.reserve(10000);
        for (std::uint32_t j = 0; j <= num_lines; ++j)
        {
            std::getline(std::cin, line);
            payment += payment_for_line(line, payment_table);
        }

        auto const dollars = payment / 100;
        auto const remaining_cents = payment - dollars * 100;
        if (remaining_cents < 10)
        {
            std::cout << dollars << ".0" << remaining_cents << "$\n";
        }
        else
        {
            std::cout << dollars << '.' << remaining_cents << "$\n";
        }
    }
}
