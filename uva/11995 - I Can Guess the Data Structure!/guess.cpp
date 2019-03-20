#include <iostream>
#include <cstdint>
#include <deque>
#include <queue>

struct Container {
    std::deque<std::uint32_t> stack;
    std::deque<std::uint32_t> queue;
    std::priority_queue<std::uint32_t> priority_queue;

    bool is_stack = true;
    bool is_queue = true;
    bool is_priority_queue = true;

    void pop(std::uint32_t expected)
    {
        if (is_stack)
        {
            if (stack.size() > 0)
            {
                is_stack = (stack.back() == expected);
                stack.pop_back();
            }
            else
            {
                is_stack = false;
            }
        }
        if (is_queue)
        {
            if (queue.size() > 0)
            {
                is_queue = (queue.front() == expected);
                queue.pop_front();
            }
            else
            {
                is_queue = false;
            }
        }
        if (is_priority_queue)
        {
            if (priority_queue.size() > 0)
            {
                is_priority_queue = (priority_queue.top() == expected);
                priority_queue.pop();
            }
            else
            {
                is_priority_queue = false;
            }
        }
    }

    void add(std::uint32_t elem)
    {
        if (is_stack)
        {
            stack.push_back(elem);
        }
        if (is_queue)
        {
            queue.push_back(elem);
        }
        if (is_priority_queue)
        {
            priority_queue.push(elem);
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        std::uint32_t num_commands;
        std::cin >> num_commands;
        if (std::cin.eof())
        {
            break;
        }
        Container container;
        for (std::uint32_t i = 0; i < num_commands; ++i)
        {
            int command;
            std::uint32_t value;
            std::cin >> command >> value;
            if (command == 1)
            {
                container.add(value);
            }
            else
            {
                container.pop(value);
            }
        }
        if (!container.is_stack && !container.is_queue && !container.is_priority_queue)
        {
            std::cout << "impossible\n";
        }
        else if (container.is_stack && !container.is_queue && !container.is_priority_queue)
        {
            std::cout << "stack\n";
        }
        else if (!container.is_stack && container.is_queue && !container.is_priority_queue)
        {
            std::cout << "queue\n";
        }
        else if (!container.is_stack && !container.is_queue && container.is_priority_queue)
        {
            std::cout << "priority queue\n";
        }
        else
        {
            std::cout << "not sure\n";
        }
    }
}
