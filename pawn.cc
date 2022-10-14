#include "piece.h"

class Pawn : public Piece 
{ 
  public:
    Pawn(int x, int y, Board& board): Piece(x, y, 'P', board) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      std::vector<Square> moves;
      return moves;
    }
};
