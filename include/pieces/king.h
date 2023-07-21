#pragma once
#include "Piece.h"

class King : public Piece
{
public:
    King() {}
    King(int8_t color) : Piece{color} {}
    void calculate(Board &board) const override
    {
    }

    char get_look() const override
    {
        if (color == 0)
            return 'k';
        else
            return 'K';
    }

    char get_code() const override
    {
        if (color == 0)
            return 'k';
        else
            return 'K';
    }
};