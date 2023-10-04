#pragma once
#include <random>
#include <time.h>
#include <thread>
#include <functional>

class async_random
{
private:
    std::unique_ptr<std::mt19937> generator;

public:
    void init();
    int32_t uniform_int(int32_t min, int32_t max);
    double uniform_float(double min, double max);
    double normal_float(double mean, double stddev);
    int32_t operator()(int32_t min, int32_t max);
    double operator()(const double min, const double max);
};

void async_random::init()
{
    generator = std::make_unique<std::mt19937>(std::time(nullptr) + (uint32_t)(std::hash<std::thread::id>{}(std::this_thread::get_id())));
}

int32_t async_random::uniform_int(int32_t min, int32_t max)
{
    std::uniform_int_distribution<int32_t> distribution(min, max);
    return distribution(*generator);
}

double async_random::uniform_float(double min, double max)
{
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(*generator);
}

double async_random::normal_float(double mean, double stddev)
{
    std::normal_distribution<double> distribution(mean, stddev);
    return distribution(*generator);
}

int32_t async_random::operator()(const int32_t min, const int32_t max)
{
    return uniform_int(min, max);
}

double async_random::operator()(const double min, const double max)
{
    return uniform_float(min, max);
}