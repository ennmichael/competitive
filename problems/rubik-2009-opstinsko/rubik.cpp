#include <array>

using Color = int;

auto constexpr side_dimensions = 3;

using Side = std::array<std::array<Color, side_dimensions>, side_dimensions>;

bool rising_diagonal_symmetry(Side const& side) noexcept
{

}

bool dropping_diagonal_symmetry(Side const& side) noexcept
{

}

bool horizontal_symmetry(Side const& side) noexcept
{

}

bool vertical_symmetry(Side const& side) noexcept
{

}

bool central_symmetry(Side const& side) noexcept
{

}

struct Cube {
	Side back {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Side up {1, 1, 1, 1, 1, 1, 1, 1, 1};
	Side left {2, 2, 2, 2, 2, 2, 2, 2, 2};
	Side right {3, 3, 3, 3, 3, 3, 3, 3, 3};
	Side down {4, 4, 4, 4, 4, 4, 4, 4, 4};
	Side front {5, 5, 5, 5, 5, 5, 5, 5, 5};

    void rotate(char command) noexcept
    {
        switch (command)
        {
            case 'L': rotate_left_side();
            case 'R': rotate_right_side();
            case 'U': rotate_up_side();
            case 'D': rotate_down_side();
            case 'F': rotate_front_side();
            case 'B': rotate_back_side();
        }
    }

    void rotate_double(char command) noexcept
    {
        rotate(command);
        rotate(command);
    }

    void rotate_reverse(char command) noexcept
    {
        switch (command)
        {
            case 'L': rotate_l_reverse();
            case 'R': rotate_r_reverse();
            case 'U': rotate_u_reverse();
            case 'D': rotate_d_reverse();
            case 'F': rotate_f_reverse();
            case 'B': rotate_b_reverse();
        }
    }

    void rotate_left_side( noexcept
    {
        auto const t1 = up[2][0];
        auto const t2 = up[2][1];
        auto const t3 = up[2][2];
        up[2][0] = right[0][0];
        up[2][1] = right[1][0];
        up[2][2] = right[2][0];
        right[0][0] = down[0][2];
        right[1][0] = down[0][1];
        right[2][0] = down[0][0];
        down[0][2] = left[2][2];
        down[0][1] = left[1][2];
        down[0][0] = left[0][2];
        left[2][2] = t1;
        left[1][2] = t2;
        left[0][2] = t3;
    }

    void rotate_right_side() noexcept
    {
        auto const t1 = up[0][0];
        auto const t2 = up[0][1];
        auto const t3 = up[0][2];
        up[0][2] = left[0][0];
        up[0][1] = left[1][0];
        up[0][0] = left[2][0];
        left[0][0] = down[2][0];
        left[1][0] = down[2][1];
        left[2][0] = down[2][2];
        down[2][0] = right[2][2];
        down[2][1] = right[1][2];
        down[2][2] = right[0][2];
        right[0][2] = t1;
        right[1][2] = t2;
        right[2][2] = t3;
    }

    void rotate_up_side() noexcept
    {
        auto const t1 = back[0][0];
        auto const t2 = back[0][1];
        auto const t3 = back[0][2];
        back[0][0] = right[0][0];
        back[0][1] = right[0][1];
        back[0][2] = right[0][2];
        right[0][0] = front[2][2];
        right[0][1] = front[2][1];
        right[0][2] = front[2][0];
        front[2][2] = left[0][2];
        front[2][1] = left[0][1];
        front[2][0] = left[0][2];
        left[0][0] = t1;
        left[0][1] = t2;
        left[0][2] = t3;
    }

    void rotate_down_side() noexcept
    {
        auto const t1 = back[2][0];
        auto const t2 = back[2][1];
        auto const t3 = back[2][2];
        back[2][0] = right[2][0];
        back[2][1] = right[2][1];
        back[2][2] = right[2][2];
        right[2][0] = front[0][2];
        right[2][1] = front[0][1];
        right[2][2] = front[0][0];
        front[0][2] = left[2][0];
        front[0][1] = left[2][1];
        front[0][0] = left[2][2];
        left[2][0] = t1;
        left[2][1] = t2;
        left[2][2] = t3;
    }

    void rotate_front_side() noexcept
    {
    }

    void rotate_back_side() noexcept
    {
    }

    void rotate_l_reverse() noexcept
    {

    }

    void rotate_l_double() noexcept
    {

    }
};

int main(int, char**)
{
    Cube cube;
}
