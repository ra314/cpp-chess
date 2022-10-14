#include <iostream>
#include "board.cc"

int main() {
    Board board;
    board.setup();
    std::cout << std::string(board);
    // Rook pointer
    auto rook_piece_pointer = board.access_square({0, 0});
    std::cout << rook_piece_pointer << std::endl;
    std::cout << rook_piece_pointer->symbol << std::endl;
    // Rook moves
    auto moves = board.access_square({0, 0})->get_pseudo_legal_moves();
    for (auto move: moves) {
      std::cout << std::string(move);
    }
    std::cout << std::endl;
    return 0;
}

