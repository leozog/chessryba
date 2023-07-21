#include "piece.h"
#include "board.h"

Piece::Piece() {}
Piece::Piece(int8_t color) : color{color} {}

int8_t Piece::get_color() const {return color;}

void Piece::move_point(Board& board, int8_t dx, int8_t dy) const
{

}

void Piece::move_line(Board& board, int8_t dx, int8_t dy) const
{

}