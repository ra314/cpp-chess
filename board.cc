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

class Board
{
  private:
    static const int size = 8;
    const int init_num_pieces = 32;
    std::vector<Piece> pieces;
    Piece *pos_to_piece_map[size][size] = {};
  
  public:
    Board() {
      pieces.reserve(init_num_pieces);
    }
    
    operator std::string() const {
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
    
    void setup() {
      for (int y: {1,6}) {
        // Pawns
        for (int i=0; i<size; i++) {
          add_piece(Pawn(i, y));
        }
      }
      for (int y: {0,7}) {
        add_piece(Rook(0, y));
        add_piece(Knight(1, y));
        add_piece(Bishop(2, y));
        add_piece(Queen(3, y));
        add_piece(King(4, y));
        add_piece(Bishop(5, y));
        add_piece(Knight(6, y));
        add_piece(Rook(7, y));
      }
    }
    
    void add_piece(Piece piece) {
      pieces.push_back(piece);
      pos_to_piece_map[piece.x][piece.y] = &piece;
    }
};
