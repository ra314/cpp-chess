#include "piece.h"
#include "board.h"

Piece::Piece(int x, int y, char symbol, Board& board): square((Square){x,y}), symbol(symbol), board(board) {}

std::vector<Square> Piece::get_pseudo_legal_moves() const {
  std::vector<Square> moves;
  return moves;
}
