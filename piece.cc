#include "piece.h"
#include "board.h"

Piece::Piece(int x, int y, char symbol, Board& board, bool color, int value): square((Square){x,y}), symbol(symbol), board(board), color(color), value(value) {}

bool Piece::can_move_to(const Square& square) const {
  std::vector<Square> legal_moves = this->get_pseudo_legal_moves();
  return (std::find(legal_moves.begin(), legal_moves.end(), square) != legal_moves.end());
}
