#pragma once

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
    return std::to_string(x) + ' ';
  }
  
  bool in_board() const {
    return !(x<0 || y<0 || x>=8 || y>=8);
  }
};
