#include <vector>
#include <cassert>
#include <iostream>

#include "piece.cc"
#include "pawn.cc"
#include "rook.cc"
#include "knight.cc"
#include "bishop.cc"
#include "queen.cc"
#include "king.cc"

Board::Board() {
  pieces.reserve(init_num_pieces);
}

Board::~Board() {
  for (Piece* piece: pieces) {
    delete piece;
  }
}
    
Board::operator std::string() const {
  // +1 for the new line chars
  int line_size = size+1;
  // Initialize the view with empty squares
  std::string view(line_size*size, '*');
  for (int i=line_size-1; i<line_size*size; i+=line_size) {
    view[i] = '\n';
  }
  // Replace squares occupied by pieces with their respective characters
  for (const Piece* piece: pieces) {
    int target_index = piece->square.x+(piece->square.y*line_size);
    // Check to make sure that no two pieces share the same square
    assert(view[target_index] == '*');
    view[target_index] = piece->symbol;
  }
  return view;
}
    
void Board::setup() {
  for (int y: {1,6}) {
    // Pawns
    for (int i=0; i<size; i++) {
      add_piece(new Pawn(i, y, *this));
    }
  }
  for (int y: {0,7}) {
    add_piece(new Rook(0, y, *this));
    add_piece(new Knight(1, y, *this));
    add_piece(new Bishop(2, y, *this));
    add_piece(new Queen(3, y, *this));
    add_piece(new King(4, y, *this));
    add_piece(new Bishop(5, y, *this));
    add_piece(new Knight(6, y, *this));
    add_piece(new Rook(7, y, *this));
  }
}

void Board::add_piece(Piece* piece) {
  pieces.push_back(piece);
  map[piece->square.x][piece->square.y] = piece;
}

Piece* Board::access_square(const Square& square) const{
  assert(square.in_board());
  return map[square.x][square.y];
}
