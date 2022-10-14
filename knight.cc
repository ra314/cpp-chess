#include "piece.h"

class Knight : public Piece 
{ 
  public:
    Knight(int x, int y, Board& board): Piece(x, y, 'N', board) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      std::vector<Square> moves;
      return moves;
    }
};
