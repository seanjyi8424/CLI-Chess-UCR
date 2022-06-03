#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <piece.hpp>
#include <fstream>
using namespace std;

class Board {
private:
    int row;
    int column;
    Piece* board[8][8];
    bool gameOver = false;
    string name;
    string moves; //string used to store moves for save function//
    int turn = 0;

public:
    Board();
    Board(string);
    void menu();
    void printBoard();
    // void updateBoard(); // I don't think this is needed because printBoard() should auto update //
    void populate(); //implement later after piece class//
    void move(int, int, int, int);
    void save();
    void load();
    void emptyBoard();
    void newGame();
    bool blocked(int, int, int, int); //Checks the path to see if piece is blocking it//
    string getPlayer();
};
#endif
