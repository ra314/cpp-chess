#include "piece.h"

class Bishop : public Piece 
{ 
  public:
    Bishop(int x, int y, Board& board): Piece(x, y, 'B', board) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      std::vector<Square> moves;
      return moves;
    }
};
