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
    std::cout << std::string(board) << std::endl;
    std::cout << std::string(board.calc_ai_move(6)) << std::endl;
    // I only managed depth 5 with an implementation similar to how I did it in godot.
    // Guess the language doesn't make that big of a difference.
    // Move ordering made it a bit faster
    return 0;
}

