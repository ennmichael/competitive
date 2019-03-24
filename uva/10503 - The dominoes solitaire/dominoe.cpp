#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct Domino {
    int head;
    int tail;
    bool used = false;

    void rotate()
    {
        std::swap(head, tail);
    }
};

using DominoTable = std::unordered_map<int, std::vector<Domino*>>;

using Dominos = std::vector<Domino>;

struct Problem {
    Domino first;
    Domino last;
    Dominos dominos;
    DominoTable domino_table;
    int num_spaces;

    bool input()
    {
        int num_dominos;
        std::cin >> num_spaces >> num_dominos
                 >> first.head >> first.tail
                 >> last.head >> last.tail;

        if (num_spaces == 0)
        {
            return false;
        }

        dominos.resize(num_dominos);
        for (auto& domino : dominos)
        {
            std::cin >> domino.head >> domino.tail;
        }
        
        preprocess();

        return true;
    }

    void preprocess()
    {
        auto const add = [&](int end, Domino& domino)
        {
            if (domino_table.count(end))
            {
                domino_table.at(end).push_back(&domino);
            }
            else
            {
                domino_table.emplace(end, std::vector<Domino*> { &domino });
            }
        };

        for (auto& domino : dominos)
        {
            add(domino.head, domino);
            add(domino.tail, domino);
        }
    }

    bool solve()
    {
        return solve(first);
    }

    bool solve(Domino const& current)
    {
        if (num_spaces == 0)
        {
            return current.tail == last.head;
        }

        if (domino_table.count(current.tail))
        {
            --num_spaces;
            for (auto* domino : domino_table.at(current.tail))
            {
                if (domino->used)
                {
                    continue;
                }

                if (domino->tail == current.tail)
                {
                    domino->rotate();
                }

                domino->used = true;
                if (solve(*domino))
                {
                    return true;
                }
                domino->used = false;
            }
            ++num_spaces;
        }

        return false;
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

        if (problem.solve())
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}
