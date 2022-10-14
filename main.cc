#include <iostream>
#include "board.cc"

int main() {
    Board board;
    board.setup();
    std::cout << std::string(board) << std::endl;
    // Caro kann defense exchange variation
    board.play_legal_move("e2e4");
    board.play_legal_move("c7c6");
    board.play_legal_move("d2d4");
    board.play_legal_move("d7d5");
    board.play_legal_move("e4d5");
    board.play_legal_move("c6d5");
    board.play_legal_move("f1d3");
    board.play_legal_move("b8c6");
    board.play_legal_move("c2c3");
    board.play_legal_move("g8f6");
    board.play_legal_move("c1f4");
    board.play_legal_move("c8g4");
    board.play_legal_move("d1b3");
    std::cout << std::string(board);
    return 0;
}

