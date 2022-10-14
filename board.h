#pragma once

#include <iostream>
class Piece;
class Board
{
  private:
    static const int size = 8;
    const int init_num_pieces = 32;
    std::vector<Piece> pieces;
    Piece *pos_to_piece_map[size][size] = {};
  public:
    Board();   
    operator std::string() const;
    void setup();
    void add_piece(Piece piece);
};
