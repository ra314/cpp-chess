#include "piece.h"
#include "board.h"

Piece::Piece(int x, int y, char symbol, Board& board, bool color): square((Square){x,y}), symbol(symbol), board(board), color(color) {}

std::vector<Square> Piece::get_pseudo_legal_moves() const {
  std::vector<Square> moves;
  return moves;
}
