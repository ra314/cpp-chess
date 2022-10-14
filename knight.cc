#include "piece.h"

class Knight : public Piece 
{ 
  public:
    Knight(int x, int y, Board* board): Piece(x, y, 'N', board) {}
};
