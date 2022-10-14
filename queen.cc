#include "piece.h"

class Queen : public Piece 
{ 
  private:
    static const std::vector<Square> deltas;
  public:
    Queen(int x, int y, Board& board): Piece(x, y, 'Q', board) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A bishop at most has 13 legal moves
      // A rook at most has 14 legal moves
      std::vector<Square> moves;
      moves.reserve(27);
      for (const Square& delta: deltas) {
        for (int i=0; i<8; i++) {
          Square move = (delta*i)+square;
          if (move.in_board() && board.access_square(move) == nullptr) {
            moves.push_back(move);
            continue;
          }
          break;
        }
      } 
      return moves;
    }
};

const std::vector<Square> Queen::deltas({{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {1,-1}, {-1,-1}});
