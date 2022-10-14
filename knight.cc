#include "piece.h"

class Knight : public Piece 
{ 
  private:
    static const std::vector<Square> deltas;
  public:
    Knight(int x, int y, Board& board, bool color): Piece(x, y, 'N', board, color) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A knight at most has 8 legal moves
      std::vector<Square> moves;
      moves.reserve(8);
      for (const Square& delta: deltas) {
        Square move = delta+square;
        if (move.in_board() && board.access_square(move) == nullptr) {
          moves.push_back(move);
          continue;
        }
      } 
      return moves;
    }
};

const std::vector<Square> Knight::deltas({{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}});
