#include "piece.h"

class Bishop : public Piece 
{ 
  public:
    Bishop(int x, int y, Board* board): Piece(x, y, 'B', board) {}
};
