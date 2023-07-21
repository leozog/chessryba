#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight() {}
    Knight(int8_t color) : Piece{color} {}
    void calculate(Board &board) const override
    {
    }

    char get_look() const override
    {
        if (color == 0)
            return 'n';
        else
            return 'N';
    }

    char get_code() const override
    {
        if (color == 0)
            return 'n';
        else
            return 'N';
    }
};