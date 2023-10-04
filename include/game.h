#pragma once
#include <thread>
#include <vector>

#include "task.h"
#include "bush.h"
#include "hashset.h"
#include "async_random.h"
#include "output.h"

class game
{
private:
    class evaluation_thread
    {
        game &game_ref;
        async_random random;
        // bush<> my_bush;

    public:
        evaluation_thread(game &game_ref);
        void loop(std::stop_token stoken);
    };

    std::vector<task<evaluation_thread>> tasks;

public:
    game(int32_t n_of_threads);
};

game::evaluation_thread::evaluation_thread(game &game_ref) : game_ref{game_ref}
{
}

void game::evaluation_thread::loop(std::stop_token stoken)
{
    random.init();
    int32_t x = random.uniform_int(-100, 100);
    output::print(x);
    output::endl();
    // while (!stoken.stop_requested())
    // {
    //     ;
    // }
}

game::game(int32_t n_of_threads)
{
    if (n_of_threads < 0)
        n_of_threads = task<evaluation_thread>::max_threads();
    for (int i = 0; i < n_of_threads; ++i)
    {
        tasks.push_back(task<evaluation_thread>(evaluation_thread(*this), evaluation_thread::loop));
    }
}