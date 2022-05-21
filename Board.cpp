#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
	this->row = 8;
	this->column = 8;
}

Board::Board(string b) {
	board[row][column] = b;
}

void Board::emptyBoard() {
	board[row][column];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			board[i][j] = "-";
		}
	}
}

void Board::printBoard() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << board[i][j] << "   ";
		}
		cout << i + 1 << "\n\n";
	}

	cout << "A   B   C   D   E   F   G   H\n";
}

void Board::updateBoard() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			//if () { //will be used to see if there is a piece in this position, if so, save piece, else, save "-"
			//
			//}
			//else {
			//	board[i][j] = "-";
			//}
		}
	}
}