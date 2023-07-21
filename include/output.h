#pragma once
#include <iostream>

class output
{
public:
    template <typename T>
    static void print(T x)
    {
        std::cout << x;
    }
    static void endl()
    {
        std::cout << '\n';
    }
};