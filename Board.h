#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "piece.hpp"
#include <fstream>
using namespace std;

class Board {
private:
    bool gameOver = false;
    string name;
    string moves; //string used to store moves for save function//
    int turn = 0;

public:
    Piece* board[8][8];
    Board(string);
    void menu();
    void printBoard();
    bool gameEnd();
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
