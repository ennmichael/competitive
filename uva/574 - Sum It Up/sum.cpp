#include <iostream>
#include <vector>
#include <algorithm>

struct Element;

using Elements = std::vector<Element>;

struct Element {
    int value;
    Elements::const_iterator next;
};

struct Problem {
    Elements elements;
    std::vector<int> operands;
    int total;
    bool success = false;

    bool input()
    {
        int num_elements;
        std::cin >> total >> num_elements;

        if (num_elements == 0)
        {
            return false;
        }

        elements.resize(num_elements);
        operands.reserve(num_elements);
        for (auto& e : elements)
        {
            std::cin >> e.value;
        }

        preprocess();

        return true;
    }

    void preprocess()
    {
        auto i = elements.begin();
        while (i != elements.end())
        {
            auto const next = std::find_if(i, elements.end(), [&](Element const& element) { return element.value != i->value; });
            for (auto j = i; j != next; ++j)
            {
                j->next = next;
            }
            i = next;
        }
    }

    void solve(Elements::const_iterator current_position, int running_total = 0)
    {
        // First check every upcoming operand
        // Then check every upcoming operand, recursing down every time
        // Could cache the results, but not worth it

        for (auto i = current_position; i != elements.cend(); i = i->next)
        {
            if (running_total + i->value == total)
            {
                operands.push_back(i->value);
                output();
                operands.pop_back();
            }
        }

        for (auto i = current_position; i != elements.cend(); i = i->next)
        {
            auto const new_total = running_total + i->value;
            if (new_total >= total)
            {
                continue;
            }
            operands.push_back(i->value);
            solve(i + 1, new_total);
            operands.pop_back();
        }
    }

    void output()
    {
        success = true;
        for (auto i = operands.cbegin(); i != operands.cend() - 1; ++i)
        {
            std::cout << *i << '+';
        }
        std::cout << operands.back() << '\n';
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        Problem problem;
        if (!problem.input())
        {
            break;
        }
        std::cout << "Sums of " << problem.total << ":\n";
        problem.solve(problem.elements.cbegin());
        if (!problem.success)
        {
            std::cout << "NONE\n";
        }
    }
}
