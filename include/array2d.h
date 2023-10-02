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
    void for_each(std::function<void(T &, size_t)> f);
    void for_each(std::function<void(T &, size_t, size_t)> f);
    bool is_in(int8_t x, int8_t y) const;
};

#ifdef _DEBUG
template <typename T, size_t W, size_t H>
T &array2d<T, W, H>::operator()(size_t x, size_t y)
{
    return arr.at(x + y * W);
}
#else
template <typename T, size_t W, size_t H>
T &array2d<T, W, H>::operator()(size_t x, size_t y)
{
    return arr[x + y * W];
}
#endif

template <typename T, size_t W, size_t H>
void array2d<T, W, H>::for_each(std::function<void(T &)> f)
{
    for (auto &a : arr)
        f(a);
}

template <typename T, size_t W, size_t H>
void array2d<T, W, H>::for_each(std::function<void(T &, size_t)> f)
{
    for (size_t i = 0; i < W * H; i++)
        f(arr[i], i);
}

template <typename T, size_t W, size_t H>
void array2d<T, W, H>::for_each(std::function<void(T &, size_t, size_t)> f)
{
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
            f(arr[j + i * W], j, i);
    }
}

template <typename T, size_t W, size_t H>
bool array2d<T, W, H>::is_in(int8_t x, int8_t y) const
{
    if (x < 0 || x >= W)
        return false;
    if (y < 0 || y >= H)
        return false;
    return true;
}