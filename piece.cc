#include "piece.h"
#include "board.h"

Piece::Piece(int x, int y, char symbol, Board* board): x(x), y(y), symbol(symbol), board(board) {}
