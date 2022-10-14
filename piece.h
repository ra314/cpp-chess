#pragma once

class Board;
class Piece
{ 
  public:
    // Origin is in the top left
    int x;
    int y;
    // Character representation
    const char symbol;
    // Board that the piece is on
    const Board* const board;
    
    Piece(int x, int y, char symbol, Board* board);
};
