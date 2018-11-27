#include <array>
#include <utility>
#include <iostream>
#include <string>

using Color = int;

auto constexpr side_dimensions = 3;

using Side = std::array<std::array<Color, side_dimensions>, side_dimensions>;

bool rising_diagonal_symmetry(Side const& side) noexcept
{
    return side[1][0] == side[2][1] &&
           side[0][0] == side[2][2] &&
           side[0][1] == side[1][2];
}

bool dropping_diagonal_symmetry(Side const& side) noexcept
{
    return side[1][0] == side[0][1] &&
           side[2][0] == side[0][2] &&
           side[2][1] == side[1][2];
}

bool horizontal_symmetry(Side const& side) noexcept
{
    return side[0][0] == side[2][0] &&
           side[0][1] == side[2][1] &&
           side[0][2] == side[2][2];
}

bool vertical_symmetry(Side const& side) noexcept
{
    return side[0][0] == side[0][2] &&
           side[1][0] == side[1][2] &&
           side[2][0] == side[2][2];
}

bool central_symmetry(Side const& side) noexcept
{
    return side[0][0] == side[2][2] &&
           side[1][0] == side[1][2] &&
           side[2][0] == side[0][2] &&
           side[0][1] == side[2][1];
}

using Rotation = std::array<int*, 12>;

void rotate_3(Rotation const& rotation) noexcept
{
    auto const t0 = *rotation[9];
    auto const t1 = *rotation[10];
    auto const t2 = *rotation[11];
    *rotation[9] = *rotation[6];
    *rotation[10] = *rotation[7];
    *rotation[11] = *rotation[8];
    *rotation[6] = *rotation[3];
    *rotation[7] = *rotation[4];
    *rotation[8] = *rotation[5];
    *rotation[3] = *rotation[0];
    *rotation[4] = *rotation[1];
    *rotation[5] = *rotation[2];
    *rotation[0] = t0;
    *rotation[1] = t1;
    *rotation[2] = t2;
}

void rotate_6(Rotation const& rotation) noexcept
{
    std::swap(*rotation[0], *rotation[6]);
    std::swap(*rotation[1], *rotation[7]);
    std::swap(*rotation[2], *rotation[8]);
    std::swap(*rotation[3], *rotation[9]);
    std::swap(*rotation[4], *rotation[10]);
    std::swap(*rotation[5], *rotation[11]);
}

int side_score(Side const& side) noexcept
{
    int score = 0;
    if (vertical_symmetry(side))
        ++score;
    if (horizontal_symmetry(side))
        ++score;
    if (rising_diagonal_symmetry(side))
        ++score;
    if (dropping_diagonal_symmetry(side))
        ++score;
    if (central_symmetry(side))
        ++score;
    return score;
}

struct Cube {
    Cube()
    {
        back[0] = {0, 0, 0};
        back[1] = {0, 0, 0};
        back[2] = {0, 0, 0};
        up[0] = {1, 1, 1};
        up[1] = {1, 1, 1};
        up[2] = {1, 1, 1};
        left[0] = {2, 2, 2};
        left[1] = {2, 2, 2};
        left[2] = {2, 2, 2};
        right[0] = {3, 3, 3};
        right[1] = {3, 3, 3};
        right[2] = {3, 3, 3};
        down[0] = {4, 4, 4};
        down[1] = {4, 4, 4};
        down[2] = {4, 4, 4};
        front[0] = {5, 5, 5};
        front[1] = {5, 5, 5};
        front[2] = {5, 5, 5};
    }

    Side back;
	Side up;
	Side left;
	Side right;
	Side down;
	Side front;

    Rotation back_rotation {{
        &up[0][2], &up[1][2], &up[2][2],
        &left[0][2], &left[1][2], &left[2][2],
        &down[0][2], &down[1][2], &down[2][2],
        &right[0][2], &right[1][2], &right[2][2],
    }};

    Rotation down_rotation {{
        &back[2][0], &back[2][1], &back[2][2],
        &left[2][0], &left[2][1], &left[2][2],
        &front[2][0], &front[2][1], &front[2][2],
        &right[0][2], &right[0][1], &right[0][0],
    }};

    Rotation front_rotation {{
        &right[0][0], &right[1][0], &right[2][0],
        &down[0][0], &down[1][0], &down[2][0],
        &left[0][0], &left[1][0], &left[2][0],
        &up[0][0], &up[1][0], &up[2][0],
    }};

    Rotation left_rotation {{
        &back[2][0], &back[1][0], &back[0][0],
        &up[2][2], &up[2][1], &up[2][0],
        &front[0][2], &front[1][2], &front[2][2],
        &down[0][0], &down[0][1], &down[0][2],
    }};

    Rotation right_rotation {{
        &up[0][0], &up[0][1], &up[0][2],
        &back[0][2], &back[1][2], &back[2][2],
        &down[2][2], &down[2][1], &down[2][0],
        &front[2][0], &front[1][0], &front[0][0],
    }};

    Rotation up_rotation {{
        &front[0][0], &front[0][1], &front[0][2],
        &left[0][0], &left[0][1], &left[0][2],
        &back[0][0], &back[0][1], &back[0][2],
        &right[2][2], &right[2][1], &right[2][0],
    }};

    Rotation inverse_back_rotation {{
        &right[0][2], &right[1][2], &right[2][2],
        &down[0][2], &down[1][2], &down[2][2],
        &left[0][2], &left[1][2], &left[2][2],
        &up[0][2], &up[1][2], &up[2][2],
    }};

    Rotation inverse_down_rotation {{
        &right[0][2], &right[0][1], &right[0][0],
        &front[2][0], &front[2][1], &front[2][2],
        &left[2][0], &left[2][1], &left[2][2],
        &back[2][0], &back[2][1], &back[2][2],
    }};

    Rotation inverse_front_rotation {{
        &up[0][0], &up[1][0], &up[2][0],
        &left[0][0], &left[1][0], &left[2][0],
        &down[0][0], &down[1][0], &down[2][0],
        &right[0][0], &right[1][0], &right[2][0],
    }};

    Rotation inverse_left_rotation {{
        &down[0][0], &down[0][1], &down[0][2],
        &front[0][2], &front[1][2], &front[2][2],
        &up[2][2], &up[2][1], &up[2][0],
        &back[2][0], &back[1][0], &back[0][0],
    }};

    Rotation inverse_right_rotation {{
        &front[2][0], &front[1][0], &front[0][0],
        &down[2][2], &down[2][1], &down[2][0],
        &back[0][2], &back[1][2], &back[2][2],
        &up[0][0], &up[0][1], &up[0][2],
    }};

    Rotation inverse_up_rotation {{
        &right[2][2], &right[2][1], &right[2][0],
        &back[0][0], &back[0][1], &back[0][2],
        &left[0][0], &left[0][1], &left[0][2],
        &front[0][0], &front[0][1], &front[0][2],
    }};

    Rotation const& command_rotation(char command) const noexcept
    {
        switch (command)
        {
            case 'L': return left_rotation;
            case 'R': return right_rotation;
            case 'U': return up_rotation;
            case 'D': return down_rotation;
            case 'F': return front_rotation;
            case 'B':
            default:  return back_rotation;
        }
    }

    Rotation const& inverse_command_rotation(char command) const noexcept
    {
        switch (command)
        {
            case 'L': return inverse_left_rotation;
            case 'R': return inverse_right_rotation;
            case 'U': return inverse_up_rotation;
            case 'D': return inverse_down_rotation;
            case 'F': return inverse_front_rotation;
            case 'B':
            default:  return inverse_back_rotation;
        }
    }

    void rotate(char command) noexcept
    {
        rotate_3(command_rotation(command));
    }

    void double_rotate(char command) noexcept
    {
        rotate_6(command_rotation(command));
    }

    void inverse_rotate(char command) noexcept
    {
        rotate_3(inverse_command_rotation(command));
    }
};

void execute_commands(Cube& cube)
{
    std::string commands;
    std::cin >> commands;
    if (commands.length() == 1)
    {
        cube.rotate(commands.front());
    }
    else
    {
        for (auto i = commands.cbegin(); i != commands.cend(); ++i)
        {
            auto const current = *i;
            if (i == commands.cend() - 1)
            {
                cube.rotate(current);
                continue;
            }
            auto const next = *(i + 1);
            if (next == '\'')
            {
                cube.inverse_rotate(current);
                ++i;
            }
            else if (next == '2')
            {
                cube.double_rotate(current);
                ++i;
            }
            else
            {
                cube.rotate(current);
            }
        }
    }
}

void tests()
{
    Cube cube;
    cube.rotate('B');
    cube = {};
    cube.rotate('D');
    cube = {};
    cube.rotate('F');
    cube = {};
    cube.rotate('L');
    cube = {};
    cube.rotate('R');
    cube = {};
    cube.rotate('U');
    cube = {};

    cube.inverse_rotate('B');
    cube = {};
    cube.inverse_rotate('D');
    cube = {};
    cube.inverse_rotate('F');
    cube = {};
    cube.inverse_rotate('L');
    cube = {};
    cube.inverse_rotate('R');
    cube = {};
    cube.inverse_rotate('U');
    cube = {};
}

int main(int, char**)
{
    std::ios::sync_with_stdio(false);

    //tests();

    Cube cube;
    execute_commands(cube);
    std::cout << side_score(cube.front) << ' '
              << side_score(cube.right) << ' '
              << side_score(cube.back) << ' '
              << side_score(cube.left) << ' '
              << side_score(cube.up) << ' '
              << side_score(cube.down) << '\n';
}
