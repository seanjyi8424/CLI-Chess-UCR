#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <piece.hpp>
using namespace std;

class Board {
private:
    int row;
    int column;
    string board[8][8];
    bool gameOver = false;
    string name;
    int turn = 0;

public:
    Board();
    Board(string);
    void menu();
    void printBoard();
    void updateBoard();
    void populate(); //implement later after piece class//
    void move(int, int, int, int);
    string getPlayer();
};
#endif
