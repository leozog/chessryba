#pragma once
#include <memory>
#include <thread>

template <class T>
class task
{
private:
    struct data
    {
        T obj;
        std::jthread thread;

        data(T &&obj, void (T::*fun)(std::stop_token));
        ~data();
    };

    std::unique_ptr<data> d;

public:
    task(T &&obj, void (T::*fun)(std::stop_token));
    static int32_t max_threads();
};

// task::data
template <class T>
task<T>::data::data(T &&obj, void (T::*fun)(std::stop_token)) : obj{std::move(obj)}, thread{std::jthread(fun, &(this->obj))}
{
}

template <class T>
task<T>::data::~data()
{
    thread.request_stop();
    thread.join();
}
// task::data

// task
template <class T>
task<T>::task(T &&obj, void (T::*fun)(std::stop_token)) : d{std::make_unique<data>(std::move(obj), fun)}
{
}

template <class T>
int32_t task<T>::max_threads()
{
    return std::jthread::hardware_concurrency();
}
// task::data