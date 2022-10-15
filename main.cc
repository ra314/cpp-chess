#include <iostream>
#include <iomanip>
#include <ranges>
#include <string_view>
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
    std::string game = "e4 c6 d4 d5 exd5 cxd5 Bd3 ";
    std::string move;
    for (auto x: game) {
      if (x == ' ') {
        board.play_legal_move_algebraic_notation(move);
        move = "";
      } else {
        move += x;
      }
    }
    std::cout << std::string(board);
    return 0;
}

