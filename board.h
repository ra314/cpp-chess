#pragma once

#include <iostream>
#include <set>

class Piece;
class Board
{
  private:
    static const int size = 8;
    const int init_num_pieces = 32;
    std::set<Piece*> pieces;
    std::array<Piece*, 64> map = {};
    int ply_counter=0;
    std::vector<std::array<Square, 2>> move_history;
    
    // Performs movement without any kind of checks
    void move(const Square& s1, const Square& s2);
    
    void set_square(const Square& square, Piece* piece);
    bool is_white_turn() const;
    
    std::pair<int, std::array<Square, 2>> minimax(int curr_depth, int max_depth, int alpha, int beta);
    int eval_heuristic() const;
  
  public:
    Board();
    Board(const Board &obj);
    ~Board();
    
    operator std::string() const;
    void setup();
    void add_piece(Piece* piece);
    Piece* access_square(const Square& square) const;
    
    // Intended to be used by human players. Performs validity checks for moves
    void play_legal_move(const Square& s1, const Square& s2);
    void play_legal_move_coordinate_notation(const std::string& move);
    void play_legal_move_algebraic_notation(const std::string& move);
    
    std::pair<int, std::array<Square, 2>> calc_ai_move() const;
};
