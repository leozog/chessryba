#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
    Rook() {}
    Rook(int8_t color) : Piece{color} {}
    void calculate(Board &board) const override
    {
    }

    char get_look() const override
    {
        if (color == 0)
            return 'r';
        else
            return 'R';
    }

    char get_code() const override
    {
        if (color == 0)
            return 'r';
        else
            return 'R';
    }
};