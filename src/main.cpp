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
#include <string>

#include "hashset.h"
#include "bush.h"
#include "game.h"

struct hash_i
{
    std::size_t operator()(int const &i) const noexcept
    {
        return i;
    }
};

struct cmp_i
{
    constexpr bool operator()(const int &lhs, const int &rhs) const
    {
        return lhs == rhs;
    }
};

class box
{
    static int id_ctr;

public:
    const int id;
    box() : id{id_ctr++}
    {

        output::print("new box " + std::to_string(id));
        output::endl();
    }

    ~box()
    {
        output::print("del box " + std::to_string(id));
        output::endl();
    }

    void sing()
    {
        output::print("AAA box " + std::to_string(id));
        output::endl();
    }
};

int box::id_ctr = 0;

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

    // array2d<int, 4, 4> arr;
    // arr(1, 1) = 0;
    /*hashset<int, hash_i, cmp_i> hs(10);
    std::vector<std::pair<std::shared_ptr<typename hashset<int, hash_i, cmp_i>::node>, bool>> p(4);
    {
        p.push_back(hs.get_node(5));
        output::print(p.back().first->key);
        output::endl();
        output::print(p.back().second);
        output::endl();
        output::endl();
    }

    {
        p.push_back(hs.get_node(4));
        output::print(p.back().first->key);
        output::endl();
        output::print(p.back().second);
        output::endl();
        output::endl();
    }

    {
        p.push_back(hs.get_node(5));
        output::print(p.back().first->key);
        output::endl();
        output::print(p.back().second);
        output::endl();
        output::endl();
    }

    {
        p.push_back(hs.get_node(15));
        output::print(p.back().first->key);
        output::endl();
        output::print(p.back().second);
        output::endl();
        output::endl();
    }
    p.clear();
    {
        p.push_back(hs.get_node(5));
        output::print(p.back().first->key);
        output::endl();
        output::print(p.back().second);
        output::endl();
        output::endl();
    }
    {
        p.push_back(hs.get_node(5));
        output::print(p.back().first->key);
        output::endl();
        output::print(p.back().second);
        output::endl();
        output::endl();
    }
    {
        p.push_back(hs.get_node(10));
        output::print(p.back().first->key);
        output::endl();
        output::print(p.back().second);
        output::endl();
        output::endl();
    }*/

    game g(-1);
    return 0;
}