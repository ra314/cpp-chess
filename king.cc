#include "piece.h"

class King : public Piece 
{ 
  private:
    static const std::vector<Square> deltas;
  public:
    King(int x, int y, Board& board, bool color): Piece(x, y, 'K', board, color, 1000) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A king at most has 8 legal moves
      std::vector<Square> moves;
      moves.reserve(8);
      for (const Square& delta: deltas) {
        Square move = delta+square;
        if (move.in_board()) {
          Piece* piece_on_target_square = board.access_square(move);
          // Add move if the square is empty
          if (piece_on_target_square==nullptr) {
            moves.push_back(move);
          }
          // Add move if the square contains enemy
          else if (piece_on_target_square->color != color) {
            moves.push_back(move);
          }
        }
      }
      return moves;
    }
};

const std::vector<Square> King::deltas({{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {1,-1}, {-1,-1}});
