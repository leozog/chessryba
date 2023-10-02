#include "board.h"
#include "piece.h"
#include "output.h"

#include <array>

Board::Board(){};
Board::Board(const std::vector<const Piece *> &pieces, const std::string &code) { load_code(pieces, code); };

void Board::evaluate()
{
    for (auto p : arr)
    {
        p->calculate(*this);
    }
}

const Piece *Board::get_piece(int8_t x, int8_t y) const
{
    return arr[y * W + x];
}

void Board::set_piece(int8_t x, int8_t y, const Piece *piece)
{
    arr[y * W + x] = piece;
}

void Board::move_piece(int8_t x1, int8_t y1, int8_t x2, int8_t y2)
{
    set_piece(x2, y2, get_piece(x1, y1));
    set_piece(x1, y1, nullptr);
}

void Board::print() const
{
    for (int i = 0; i < H / 10 + 1; i++)
        output::print(' ');
    output::print("+");
    for (int i = 0; i < W; i++)
        output::print('-');
    output::print("+");
    output::endl();

    for (int y = 0; y < H; y++)
    {
        output::print(std::to_string(H - y));
        for (int i = 0; i < y / 10; i++)
            output::print(' ');
        output::print('|');

        for (int x = 0; x < W; x++)
        {
            const Piece *p = get_piece(x, y);
            if (p != nullptr)
                output::print(p->get_look());
            else
            {
                if (x % 2 == y % 2)
                    output::print('#');
                else
                    output::print(' ');
            }
        }

        output::print('|');
        output::endl();
    }

    output::print(" +");
    for (int i = 0; i < W; i++)
        output::print('-');
    output::print("+");
    output::endl();
    output::print("  ");
    for (int i = 0; i < W; i++)
        output::print('a' + i);
    output::endl();
}

void Board::load_code(const std::vector<const Piece *> &pieces, const std::string &code)
{
    int state = 0;
    int x = 0, y = 0;
    for (char c : code)
    {

        if (c == ' ')
            state++;
        if (state == 0)
        {
            if (x > W)
                throw "FEN load error 1";
            if (y >= H)
                throw "FEN load error 2";
            if (c == '/')
            {
                x = 0;
                y++;
            }
            else if (c >= '1' && c <= '9')
            {
                for (int i = 0; i < c - '0'; i++, x++)
                    set_piece(x, y, nullptr);
            }
            else
            {
                for (const Piece *p : pieces)
                {
                    if ((char)c == p->get_code())
                    {
                        set_piece(x, y, p);
                        x++;
                        break;
                    }
                }
            }
        }
    }
}