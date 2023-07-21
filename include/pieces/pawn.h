#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn() {}
    Pawn(int8_t color) : Piece{color} {}
    void calculate(Board &board) const override
    {
    }

    char get_look() const override
    {
        if (color == 0)
            return 'p';
        else
            return 'P';
    }

    char get_code() const override
    {
        if (color == 0)
            return 'p';
        else
            return 'P';
    }
};