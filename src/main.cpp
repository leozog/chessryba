#include "piece.h"
#include "board.h"
#include "output.h"
#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"

#include "array2d.h"

#include <vector>

int main()
{
    /*const King king_b(0);
    const King king_w(1);
    const Queen queen_b(0);
    const Queen queen_w(1);
    const Rook rook_b(0);
    const Rook rook_w(1);
    const Bishop bishop_b(0);
    const Bishop bishop_w(1);
    const Knight knight_b(0);
    const Knight knight_w(1);
    const Pawn pawn_b(0);
    const Pawn pawn_w(1);
    const std::vector<const Piece *> pieces = {
        &king_b, &king_w,
        &queen_b, &queen_w,
        &rook_b, &rook_w,
        &bishop_b, &bishop_w,
        &knight_b, &knight_w,
        &pawn_b, &pawn_w};

    try
    {
        Board board(pieces, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        board.print();
    }
    catch (char const *s)
    {
        Output::print(s);
    }*/

    array2d<int, 4, 4> arr;
    output::print(arr.h);

    return 0;
}