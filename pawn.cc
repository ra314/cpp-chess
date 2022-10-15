#include "piece.h"

class Pawn : public Piece 
{
  private:
    bool is_at_start() {
      return (color && y==6) || (!color && y==1);
    }
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
      if (move.in_board() && board.access_square(move_1) == nullptr) {
        moves.push_back(move_1);
        if (is_at_start()) {
          Square move_2 = ((Square){0, delta_y})+square;
          if (board.access_square(move_2) == nullptr) {
            moves.push_back(move2);
          }
        }
      }
      return moves;
    }
};
