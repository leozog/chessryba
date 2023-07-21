#include "output.h"

void Output::print(char c)
{
    std::cout<<c;
}

void Output::print(std::string s)
{
    std::cout<<s;
}

void Output::endl()
{
    std::cout<<'\n';
}