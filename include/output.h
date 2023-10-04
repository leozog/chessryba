#pragma once
#include <iostream>
#include <mutex>

class output
{

public:
    template <typename T>
    static void print(T x)
    {
        static std::mutex w_mutex;
        w_mutex.lock();
        std::cout << x;
        w_mutex.unlock();
    }
    static void endl()
    {
        print('\n');
    }
};