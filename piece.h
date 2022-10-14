#pragma once

#include "utils.cc"

class Board;
class Piece
{ 
  public:
    // Origin is in the top left
    Square square;
    // Character representation
    const char symbol;
    // Board that the piece is on
    const Board& board;
    
    Piece(int x, int y, char symbol, Board& board);
    virtual std::vector<Square> get_pseudo_legal_moves() const;
};
