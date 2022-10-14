#include "piece.h"

class Queen : public Piece 
{ 
  public:
    Queen(int x, int y, Board& board): Piece(x, y, 'Q', board) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A bishop at most has 13 legal moves
      // A rook at most has 14 legal moves
      std::vector<Square> moves;
      moves.reserve(27);
      return moves;
    }
};
