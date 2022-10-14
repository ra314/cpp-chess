#include "piece.h"

class Pawn : public Piece 
{ 
  public:
    Pawn(int x, int y, Board* board): Piece(x, y, 'P', board) {}
};
