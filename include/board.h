#pragma once
#include <memory>
#include <array>
#include <vector>
#include <string>
#include "piece.h"

class Board
{
    static const uint8_t W = 8;
    static const uint8_t H = 8;

    std::array<const Piece *, W * H> A;

public:
    Board();
    Board(const std::vector<const Piece *> &pieces, const std::string &code);
    void load_code(const std::string &code, const std::vector<const Piece *> &pieces);

    // std::string

    void claculate();

    bool is_in(int8_t x, int8_t y) const;
    const Piece *get_piece(int8_t x, int8_t y) const;
    void set_piece(int8_t x, int8_t y, const Piece *piece);
    void move_piece(int8_t x1, int8_t y1, int8_t x2, int8_t y2);

    void print() const;
};