#include <iostream>
#include "board.cc"

int main() {
    Board board;
    board.setup();
    std::cout << std::string(board);
    return 0;
}

