#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <set>

#include "piece.cc"
#include "pawn.cc"
#include "rook.cc"
#include "knight.cc"
#include "bishop.cc"
#include "queen.cc"
#include "king.cc"

Board::Board() {}

Board::Board(const Board &obj) {
  ply_counter = obj.ply_counter;
  move_history = obj.move_history;
  for (Piece* piece: obj.pieces) {
    add_piece(new Piece(*piece));
  }
}

Board::~Board() {
  for (Piece* piece: pieces) {
    delete piece;
  }
}
    
Board::operator std::string() const {
  // +1 for the new line chars
  int line_size = size+1;
  // Initialize the view with empty squares
  std::string view(line_size*size, '*');
  for (int i=line_size-1; i<line_size*size; i+=line_size) {
    view[i] = '\n';
  }
  // Replace squares occupied by pieces with their respective characters
  for (const Piece* piece: pieces) {
    int target_index = piece->square.x+(piece->square.y*line_size);
    // Check to make sure that no two pieces share the same square
    assert(view[target_index] == '*');
    view[target_index] = piece->symbol;
  }
  return view;
}
    
void Board::setup() {
  for (int y: {1,6}) {
    // Pawns
    for (int i=0; i<size; i++) {
      add_piece(new Pawn(i, y, *this, y==6));
    }
  }
  for (int y: {0,7}) {
    add_piece(new Rook(0, y, *this, y==7));
    add_piece(new Knight(1, y, *this, y==7));
    add_piece(new Bishop(2, y, *this, y==7));
    add_piece(new Queen(3, y, *this, y==7));
    add_piece(new King(4, y, *this, y==7));
    add_piece(new Bishop(5, y, *this, y==7));
    add_piece(new Knight(6, y, *this, y==7));
    add_piece(new Rook(7, y, *this, y==7));
  }
}

void Board::add_piece(Piece* piece) {
  pieces.insert(piece);
  Board::set_square(piece->square, piece);
}

Piece* Board::access_square(const Square& square) const{
  assert(square.in_board());
  return map[square.x+(square.y*8)];
}

void Board::set_square(const Square& square, Piece* piece) {
  assert(square.in_board());
  map[square.x+(square.y*8)] = piece;
}

void Board::move(const ChessMove& chess_move) {
  Piece* p1 = Board::access_square(chess_move[0]);
  Piece* p2 = Board::access_square(chess_move[1]);
  
  if (p2 != nullptr) {
    pieces.erase(p2);
    delete p2;
  }
  
  Board::set_square(chess_move[0], nullptr);
  Board::set_square(chess_move[1], p1);
  
  p1->square = chess_move[1];
  p1->times_moved++;
  Board::ply_counter++;
  
  move_history.push_back({chess_move[0], chess_move[1]});
}

void Board::play_legal_move(const ChessMove& chess_move) {
  assert(chess_move[0].in_board());
  Piece* p1 = Board::access_square(chess_move[0]);
  assert(p1 != nullptr);
  assert(p1->can_move_to(chess_move[1]));
  Board::move({{chess_move[0], chess_move[1]}});
}

void Board::play_legal_move_coordinate_notation(const std::string& move) {
  Board::play_legal_move({{move.substr(0,2), move.substr(2,2)}});
}

void Board::play_legal_move_algebraic_notation(const std::string& move) {
  Square target_square = move.substr(move.length()-2);
  
  // eg: Bxc6 or dxc6 or Rexe4
  if (move.find("x") != std::string::npos) {
    assert(Board::access_square(target_square) != nullptr);
  }
  // Find all pieces that can move there this turn
  std::vector<Piece*> pieces;
  for (Piece* piece : Board::pieces) {
    // Limit to the current color to play
    if (piece->color != Board::is_white_turn()) {
      continue;
    }
    // Limit to the right kind of piece to move
    // If the first char is lower, then continue if the current piece is not a pawn
    if (std::islower(move[0])) {
      if (piece->symbol!='P') {
        continue;
      }
    } // If the first char is upper, then if the first letter of the move isn't the same as the symbol of the piece, then continue
    else if (move[0]!=piece->symbol) {
      continue;
    }
    // Limit to pieces that can reach the target square
    if (!piece->can_move_to(target_square)) {
      continue;
    }
    // Filter chess pieces that start from the right file
    // eg: Rexe4 or Ree4 or cxd5
    if (move.size()>=4) {
      char start_file = std::isupper(move[0]) ? move[1] : move[0];
      if (std::string(piece->square)[0]!=start_file) {
        continue;
      }
    }
    pieces.push_back(piece);
  }
  assert(pieces.size()==1);
  Board::play_legal_move({{pieces[0]->square, target_square}});
}

bool Board::is_white_turn() const {
  return Board::ply_counter%2 == 0;
}

EvaluatedChessMove Board::calc_ai_move() const {
  Board new_board = *this;
  return new_board.minimax(0, 4, -1000, 1000);
}

int Board::eval_heuristic() const {
  int eval = 0;
  for (Piece* piece: pieces) {
    if (piece->color) {
      eval += piece->value;
    } else {
      eval -= piece->value;
    }
  }
  return eval;
}

EvaluatedChessMove Board::minimax(int depth, int max_depth, int alpha, int beta) {
  // TODO Order the moves from most promsing to least, to improve alpha beta search
  
  // Leaf node
  if (depth == max_depth) {
    return {eval_heuristic(), move_history[move_history.size()-1]};
  }
  
  // Maximising player
  if (is_white_turn()) {
    EvaluatedChessMove best_valued_move = {1000, {{{-1,-1},{-1,-1}}}};
    for (Piece* piece: pieces) {
      if (piece->color == is_white_turn()) {
        for (const Square& square: piece->get_pseudo_legal_moves()) {
          EvaluatedChessMove valued_move = minimax(depth+1, max_depth, alpha, beta);
          //best_val = std::max(best_valued_move, valued_move);
          //alpha = std::max(alpha, best_valued_move);
          //if (beta <= alpha) {
          //  break;
          //}
        }
      }
    }
    return best_valued_move;
  } else {
  
  }
  // SHOULD NOT REACH
  assert(false);
  return {0, {{{-1,-1},{-1,-1}}}};
}
