class Piece
{ 
  public:
    // Origin is in the top left
    int x;
    int y;
    // Character representation
    const char symbol;
    
    Piece(int x, int y, char symbol): x(x), y(y), symbol(symbol) {}
};
