#include "array2d.h"

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