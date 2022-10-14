#include <iostream>
#include "board.cc"

int main() {
    Board board;
    board.setup();
    std::cout << std::string(board);
    board.play_legal_move({4,6}, {4,5});
    std::cout << std::string(board);
    return 0;
}

