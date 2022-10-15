#include <iostream>
#include "board.cc"

int main() {
    Board board;
    board.setup();
    std::cout << std::string(board) << std::endl;
    // Caro kann defense exchange variation
    /*
    board.play_legal_move_coordinate_notation("e2e4");
    board.play_legal_move_coordinate_notation("c7c6");
    board.play_legal_move_coordinate_notation("d2d4");
    board.play_legal_move_coordinate_notation("d7d5");
    board.play_legal_move_coordinate_notation("e4d5");
    board.play_legal_move_coordinate_notation("c6d5");
    board.play_legal_move_coordinate_notation("f1d3");
    board.play_legal_move_coordinate_notation("b8c6");
    board.play_legal_move_coordinate_notation("c2c3");
    board.play_legal_move_coordinate_notation("g8f6");
    board.play_legal_move_coordinate_notation("c1f4");
    board.play_legal_move_coordinate_notation("c8g4");
    board.play_legal_move_coordinate_notation("d1b3");
    */
    board.play_legal_move_algebraic_notation("e4");
    std::cout << std::string(board);
    return 0;
}

