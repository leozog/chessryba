#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
    Queen() {}
    Queen(int8_t color) : Piece{color} {}
    void calculate(Board &board) const override
    {
    }

    char get_look() const override
    {
        if (color == 0)
            return 'q';
        else
            return 'Q';
    }

    char get_code() const override
    {
        if (color == 0)
            return 'q';
        else
            return 'Q';
    }
};