#pragma once

#include <iostream>
#include <set>

class Piece;
class Board
{
  private:
    static const int size = 8;
    const int init_num_pieces = 32;
    std::set<Piece*> pieces;
    Piece *map[size][size] = {};
    // Performs movement without any kind of checks
    void move(const Square& s1, const Square& s2);
    void set_square(const Square& square, Piece* piece);
  public:
    Board();
    ~Board();
    operator std::string() const;
    void setup();
    void add_piece(Piece* piece);
    Piece* access_square(const Square& square) const;
    // Intended to be used by human players. Performs validity checks for moves
    void play_legal_move(const Square& s1, const Square& s2);
    void play_legal_move(const std::string& move);
};
