#include "piece.h"

class Rook : public Piece 
{ 
  public:
    Rook(int x, int y, Board* board): Piece(x, y, 'R', board) {}
};
