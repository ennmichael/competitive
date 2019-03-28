#include <iostream>
#include <cmath>
#include <iomanip>

double constexpr epsilon = 1e-9;

struct Equation {
    double p;
    double q;
    double r;
    double s;
    double t;
    double u;

    void input()
    {
        std::cin >> p >> q >> r >> s >> t >> u;
    }

    void solve()
    {
        double x = 0.5;
        double low = 0.0;
        double high = 1.0;

        for (int i = 0; i < 100000; ++i)
        {
            auto const eval = evaluate(x);

            if (std::abs(eval) <= epsilon)
            {
                std::printf("%.4lf\n", x);
                return;
            }

            if (eval < 0.0)
            {
                high = x;
                x = (low + x) / 2.0;
            }
            else
            {
                low = x;
                x = (x + high) / 2.0;
            }
        }

        std::cout << "No solution\n";
    }

    double evaluate(double x) const
    {
        return p / std::exp(x) + q * std::sin(x) + r * std::cos(x) + s * std::tan(x) + t * x * x + u;
    }
};

int main()
{
    while (true)
    {
        Equation equation;
        equation.input();
        if (std::cin.eof())
        {
            break;
        }
        equation.solve();
    }
}
