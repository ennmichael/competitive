#pragma once

namespace Competitive {

    double constexpr pi = 3.141592653589793;

    double constexpr e = 2.718281828459045;

    template <class Map, class Key, class Value>
    void insert_or_assign(Map& map, Key const& key, Value const& value)
    {
        if (map.count(key))
            map.at(key) = value;
        else
            map.insert({key, value});
    }

}

