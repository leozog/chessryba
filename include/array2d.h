#pragma once
#include <array>
#include <functional>

template <typename T, size_t W, size_t H>
class array2d
{
private:
    std::array<T, W * H> arr;

public:
    static constexpr size_t w = W;
    static constexpr size_t h = H;
    T &operator()(size_t x, size_t y);
    void for_each(std::function<void(T &)> f);
};
