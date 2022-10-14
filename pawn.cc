#include "piece.h"

class Pawn : public Piece 
{
  public:
    Pawn(int x, int y, Board& board, bool color): Piece(x, y, 'P', board, color) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A pawn at most has 4 legal moves
      std::vector<Square> moves;
      moves.reserve(4);
      int delta_y = color ? -1 : 1;
      for (int delta_x: {-1, 1}) {  
        Square move = ((Square){delta_x, delta_y})+square;
        if (move.in_board() && board.access_square(move) != nullptr) {
          moves.push_back(move);
        }
      }
      for (int i=1; i<=2; i++) {
        Square move = ((Square){0, delta_y*i})+square;
        if (move.in_board() && board.access_square(move) == nullptr) {
          moves.push_back(move);
          continue;
        }
        break;
      }
      return moves;
    }
};
