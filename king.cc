#include "piece.h"

class King : public Piece 
{ 
  private:
    static const std::vector<Square> deltas;
  public:
    King(int x, int y, Board& board): Piece(x, y, 'K', board) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A king at most has 8 legal moves
      std::vector<Square> moves;
      moves.reserve(8);
      for (const Square& delta: deltas) {
        Square move = delta+square;
        if (move.in_board() && board.access_square(move) == nullptr) {
          moves.push_back(move);
          continue;
        }
        break;
      } 
      return moves;
    }
};

const std::vector<Square> King::deltas({{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {1,-1}, {-1,-1}});
