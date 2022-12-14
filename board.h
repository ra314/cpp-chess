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
    std::vector<ChessMove> move_history;
    
    // Performs movement without any kind of checks
    void move(const ChessMove& chess_move, bool delete_captured_piece);
    void undo_move(Piece* prev_captured_piece);
    
    void set_square(const Square& square, Piece* piece);
    bool is_white_turn() const;
    
    EvaluatedChessMove minimax(int curr_depth, int max_depth, int alpha, int beta);
    int eval_heuristic() const;
    std::vector<ChessMove> get_all_moves_ordered() const;
  
  public:
    Board();
    Board(const Board &obj);
    ~Board();
    
    operator std::string() const;
    void setup();
    void add_piece(Piece* piece);
    Piece* access_square(const Square& square) const;
    
    // Intended to be used by human players. Performs validity checks for moves
    void play_legal_move(const ChessMove& chess_move);
    void play_legal_move_coordinate_notation(const std::string& move);
    void play_legal_move_algebraic_notation(const std::string& move);
    
    EvaluatedChessMove calc_ai_move(int max_depth) const;
};
