#pragma once
#include <cstdint>

class Board;

class Piece
{
protected:
    int8_t color;
public:
    Piece();
    Piece(int8_t color);

    virtual void calculate(Board& board) const = 0;
    virtual char get_look() const = 0;
    virtual char get_code() const = 0;

    int8_t get_color() const;
protected:
    void move_point(Board& board, int8_t dx, int8_t dy) const;
    void move_line(Board& board, int8_t dx, int8_t dy) const;
};