#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>
#include <iterator>

std::string input_description()
{
    std::uint32_t num_pieces;
    std::cin >> num_pieces;
    std::string description;

    for (std::uint32_t i = 0; i < num_pieces; ++i)
    {
        std::uint32_t num_repeats;
        std::string piece;
        std::cin >> num_repeats >> piece;
        description.append(piece, num_repeats);
    }

    return description;
}

struct Node;

using UniqueNode = std::unique_ptr<Node>;

struct Node {
    std::uint32_t num_bucaneers = 0;
    std::uint32_t num_barbaries = 0;
    UniqueNode left = nullptr;
    UniqueNode right = nullptr;
};

struct Tree {
    std::string description;
    UniqueNode root;

    UniqueNode build_root()
    {
        root = build_node(description.cbegin(), description.cend());
    }

    static UniqueNode build_node(std::string::const_iterator description_begin, std::string::const_iterator description_end)
    {
        auto const node = std::make_unique<Node>();
        auto const d = std::distance(description_begin, description_end);

        if (d == 0)
        {
            return nullptr;
        }

        if (d == 1)
        {
            if (*description_begin == '1')
            {
                node->num_bucaneers = 1;
            }
            else
            {
                node->num_barbaries = 1;
            }
            return node;
        }

        auto const half = (description_begin + description_end) / 2;
        node->left = build_node(description_begin, half);
        node->right = build_node(half + 1, description_end);
        node->num_bucaneers = node->left->num_bucaneers + node->right->num_bucaneers;
        node->num_barbaries = node->left->num_barbaries + node->right->num_barbaries;
        return node;
    }
};

int main()
{
    // So far, should be able to build the segment tree.

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint32_t num_test_cases;
    std::cin >> num_test_cases;

    for (std::uint32_t i = 0; i < num_test_cases; ++i)
    {
        Tree tree;
        tree.description = input_description();
        tree.build_root();
    }
}
