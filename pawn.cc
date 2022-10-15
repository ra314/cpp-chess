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
        if (move.in_board()) {
          Piece* piece_on_target_square = board.access_square(move);
          // Add move if the square is contains enemy
          if (piece_on_target_square!=nullptr && piece_on_target_square->color != color) {
            moves.push_back(move);
          }
        }
      }
      Square move_1 = ((Square){0, delta_y})+square;
      if (move_1.in_board() && board.access_square(move_1) == nullptr) {
        moves.push_back(move_1);
        if (times_moved==0) {
          Square move_2 = ((Square){0, delta_y*2})+square;
          if (board.access_square(move_2) == nullptr) {
            moves.push_back(move_2);
          }
        }
      }
      return moves;
    }
};
