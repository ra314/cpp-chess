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
    
Board::operator std::string() const {
  // +1 for the new line chars
  int line_size = size+1;
  // Initialize the view with empty squares
  std::string view(line_size*size, '*');
  for (int i=line_size-1; i<line_size*size; i+=line_size) {
    view[i] = '\n';
  }
  // Replace squares occupied by pieces with their respective characters
  for (Piece piece: pieces) {
    int target_index = piece.x+(piece.y*line_size);
    // Check to make sure that no two pieces share the same square
    assert(view[target_index] == '*');
    view[target_index] = piece.symbol;
  }
  return view;
}
    
void Board::setup() {
  for (int y: {1,6}) {
    // Pawns
    for (int i=0; i<size; i++) {
      add_piece(Pawn(i, y, this));
    }
  }
  for (int y: {0,7}) {
    add_piece(Rook(0, y, this));
    add_piece(Knight(1, y, this));
    add_piece(Bishop(2, y, this));
    add_piece(Queen(3, y, this));
    add_piece(King(4, y, this));
    add_piece(Bishop(5, y, this));
    add_piece(Knight(6, y, this));
    add_piece(Rook(7, y, this));
  }
}

void Board::add_piece(Piece piece) {
  pieces.push_back(piece);
  pos_to_piece_map[piece.x][piece.y] = &piece;
}
