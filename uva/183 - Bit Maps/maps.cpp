#include <iostream>
#include <vector>
#include <string>

using Row = std::vector<char>;

using Matrix = std::vector<Row>;

void matrix_to_compressed(Matrix::const_iterator matrix, std::size_t width, std::size_t height)
{
}

void compressed_to_matrix(std::string const& compressed, std::size_t width, std::size_t height)
{
}

// XXX Shitty output method

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        char type;
        std::cin >> type;

        if (type == '#')
        {
            break;
        }

        std::size_t width;
        std::size_t height;
        std::cin >> width >> height;

        if (type == 'B')
        {
            Matrix matrix(height, Row(width));
            for (auto& c : matrix)
            {
                std::cin >> c;
            }
            matrix_to_compressed(matrix.cbegin(), width, height);
        }
        else
        {
            std::string compressed;
            std::cin >> compressed;
            compressed_to_matrix(compressed, width, height);
        }
    }
}
