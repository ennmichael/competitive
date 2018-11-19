#pragma once

namespace Competitive {

    template <class T>
    void minmax(T a, T b, T& min, T& max)
    {
        if (a < b)
        {
            min = a;
            max = b;
        }
        else
        {
            min = b;
            max = a;
        }
    }

}

