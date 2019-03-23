#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstddef>

struct SupportingEntry;

struct Element;

using SupportingEntries = std::vector<SupportingEntry>;

using Elements = std::vector<Element>;

struct SupportingEntry {
    Elements::const_iterator origin;
    Elements::const_iterator end;
    std::ptrdiff_t occurence_count;
};

struct Element {
    SupportingEntries::const_iterator supporting_entry;
    std::int32_t value;

    std::ptrdiff_t occurence_count() const
    {
        return supporting_entry->occurence_count;
    }

    Elements::const_iterator origin() const
    {
        return supporting_entry->origin;
    }

    Elements::const_iterator end() const
    {
        return supporting_entry->end;
    }
};

SupportingEntries build_supporting_entries(Elements& elements)
{
    SupportingEntries supporting_entries;
    supporting_entries.reserve(elements.size());
    auto i = elements.begin();
    do {
        auto const j = std::find_if(i, elements.end(), [&](Element const& elem) { return elem.value != i->value; });
        supporting_entries.push_back(SupportingEntry { i, j, std::distance(i, j) });
        auto const new_entry = supporting_entries.cend() - 1;
        for (auto k = i; k != j; ++k)
        {
            k->supporting_entry = new_entry;
        }
        i = j;
    } while (i != elements.end());
    return supporting_entries;
}

std::ptrdiff_t solve_query(Elements const& elements, std::uint32_t start, std::uint32_t end)
{
    if (start == end)
    {
        return 1;
    }

    auto const i_start = elements.cbegin() + start;
    auto const i_end = elements.cbegin() + end;

    auto const d1 = std::distance(i_start, i_start->end());
    auto const d2 = std::distance(i_end->origin(), i_end + 1);
    auto const dmax = std::max(d1, d2);

    auto const support_start = i_start->supporting_entry + 1;
    auto const support_end = i_end->supporting_entry;

    if (support_start >= support_end)
    {
        return dmax;
    }

    auto const other_max = std::max_element(support_start, support_end,
        [](SupportingEntry const& left, SupportingEntry const& right)
        {
            return left.occurence_count < right.occurence_count;
        }
    );

    if (other_max == support_end)
    {
        return dmax;
    }

    return std::max(dmax, other_max->occurence_count);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::uint32_t num_elements;
        std::uint32_t num_queries;
        std::cin >> num_elements >> num_queries;

        if (num_elements == 0)
        {
            break;
        }

        Elements elements(num_elements);

        for (std::uint32_t i = 0; i < num_elements; ++i)
        {
            std::cin >> elements[i].value;
        }

        auto const supporting_entries = build_supporting_entries(elements);
        
        /*for (auto const& element : elements)
        {
            std::cout << element.value << " : " << element.supporting_entry->occurence_count << '\n';
        }
        std::cout << '\n';
        for (auto const& entry : supporting_entries)
        {
            std::cout << entry.origin->value << " : " << entry.occurence_count << '\n';
        }
        return 0;*/

        for (std::uint32_t i = 0; i < num_queries; ++i)
        {
            std::uint32_t start;
            std::uint32_t end;
            std::cin >> start >> end;
            --start;
            --end;
            // Zero-based indexing, both start and end included
            std::cout << solve_query(elements, start, end) << '\n';
        }
    }
}
