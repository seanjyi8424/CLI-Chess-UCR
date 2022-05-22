#ifndef BOARD_H
#define BOARD_H
#include <iostream>

using namespace std;

class Board {
private:
    int row;
    int column;
    string board[8][8];

public:
    Board();

    Board(string);

    void emptyBoard();

    void printBoard();

    void updateBoard();
};
#endif