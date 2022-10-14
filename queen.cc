#include "piece.h"

class Queen : public Piece 
{ 
  public:
    Queen(int x, int y, Board* board): Piece(x, y, 'Q', board) {}
};
