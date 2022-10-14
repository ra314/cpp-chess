#include "piece.h"

class King : public Piece 
{ 
  public:
    King(int x, int y, Board& board): Piece(x, y, 'K', board) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      std::vector<Square> moves;
      return moves;
    }
};
