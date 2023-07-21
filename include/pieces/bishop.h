#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop() {}
    Bishop(int8_t color) : Piece{color} {}
    void calculate(Board &board) const override
    {
    }

    char get_look() const override
    {
        if (color == 0)
            return 'b';
        else
            return 'B';
    }

    char get_code() const override
    {
        if (color == 0)
            return 'b';
        else
            return 'B';
    }
};