#pragma once

#include <ctype.h>

struct Square {
  int x;
  int y;
  
  Square operator+(const Square s1) const{
    return Square{s1.x+x, s1.y+y};
  }
  
  Square operator*(int num) const{
    return Square{x*num, y*num};
  }
  
  operator std::string() const {
    // int('a') = 97 // int('1') = 49
    return std::string(1, char(x+97)) + std::string(1, char((7-x)+49));
  }
  
  bool operator==(const Square& s1) {
    return s1.x == x && s1.y == y;
  }
  
  bool in_board() const {
    return !(x<0 || y<0 || x>=8 || y>=8);
  }
  
  Square(int x, int y): x(x), y(y) {}
  
  Square(std::string square) {
    assert(square.size() == 2);
    assert(std::isalpha(square[0]));
    assert(std::isdigit(square[1]));
    // int('a') = 97
    x = int(square[0])-97;
    // int('1') = 49
    y = 7-(int(square[1])-49);
  }
};

struct ChessMove {
  Square start;
  Square end;
  operator std::string() const {
    return std::string(start) + "," + std::string(end);
  }
};

struct EvaluatedChessMove {
  int eval;
  ChessMove chess_move;
  bool operator<(const EvaluatedChessMove& rhs) const {
    return eval < rhs.eval;
  }
  operator std::string() const {
    return std::to_string(eval) + " " + std::string(chess_move);
  }
};
