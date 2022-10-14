#include "piece.h"

class Bishop : public Piece 
{ 
  private:
    static const std::vector<Square> deltas;
  public:
    Bishop(int x, int y, Board& board, bool color): Piece(x, y, 'B', board, color) {}
    std::vector<Square> get_pseudo_legal_moves() const override{
      // A bishop at most has 13 legal moves
      std::vector<Square> moves;
      moves.reserve(13);
      for (const Square& delta: deltas) {
        for (int i=1; i<8; i++) {
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

const std::vector<Square> Bishop::deltas({{1,1}, {1,-1}, {1,-1}, {-1,-1}});
