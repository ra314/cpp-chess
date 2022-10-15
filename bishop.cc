#include "piece.h"

class Bishop : public Piece 
{ 
  private:
    static const std::vector<Square> deltas;
  public:
    Bishop(int x, int y, Board& board, bool color): Piece(x, y, 'B', board, color, 3) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A bishop at most has 13 legal moves
      std::vector<Square> moves;
      moves.reserve(13);
      for (const Square& delta: deltas) {
        for (int i=1; i<8; i++) {
          Square move = (delta*i)+square;
          if (move.in_board()) {
            Piece* piece_on_target_square = board.access_square(move);
            // Add move if the square is empty, and keep looking in that direction
            if (piece_on_target_square == nullptr) {
              moves.push_back(move);
              continue;
            }
            // Add move if the square is occupied by the enemy, and stop looking in the direction
            else if (piece_on_target_square->color != color) {
              moves.push_back(move);
              break;
            // If the square is occupied by a friendly, stop looking in that direction
            } else {
              break;
            }
          }
          break;
        }
      } 
      return moves;
    }
};

const std::vector<Square> Bishop::deltas({{1,1}, {1,-1}, {1,-1}, {-1,-1}});
