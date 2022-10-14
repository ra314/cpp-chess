#include "piece.h"

class King : public Piece 
{ 
  public:
    King(int x, int y, Board* board): Piece(x, y, 'K', board) {}
};
