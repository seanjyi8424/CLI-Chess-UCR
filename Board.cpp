#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
	this->row = 8;
	this->column = 8;
}

Board::Board(string b) {
	name = b;
	populate();
	board[row][column] = b;
}
void Board::menu() {
    char input = 0;
    while (input != 'q' && gameOver == false) {
        printBoard();
	    std::cout << "Currently " << getPlayer() << "'s turn..." << std::endl
	    << "Enter input: "; //MENU OPTIONS: (m)ove, (s)ave, (l)oad, (n)ew game, (q)quit
	    std::cin >> input;
            std::cout << std::endl;
	    if (input == 'm') {
		char a;
		int b;
		char x;
		int y;
		std::cout << "Enter piece to move" << std::endl
			  << "x axis: " << std::endl;
		std::cin >> a;
		std::cout << "y axis: " << std::endl;
		std::cin >> b;
		std::cout << "Enter where to move" << std::endl
			  << "x axis: " << std::endl;
		std::cin >> x;
		std::cout << "y axis: " << std::endl;
		std::cin >> y;
		move(8 - b, int(tolower(a)) - 97, 8 - y, int(tolower(x)) - 97);
	    }
	    else if (input == 's') {
		save();
            }
	    else if (input == 'l') {
		load();
	    }
	    else if (input == 'n') {
		newGame();
	    }
	    else if (input == 'q') { //Added this statement because pressing q results in error message and then closes the loop//
		std::cout << "Game has ended, goodbye" << std::endl;
	    }
	    else { //encourages users to use lower case inputs, upper case will not be recognized// 
		std::cout << "Invalid input, try again" << std::endl;
	    }
    }
}
void Board::move(int a, int b, int x, int y) { // a = row , b = column because of array access remember to flip it for function calls //
	// NEED TO IMPLEMENT //
}
void Board::blocked(int a, int b, int x, int y) {
// NEED TO IMPLEMENT, ITERATES THROUGH BOARD TO CHECK IF EACH SQUARE IN PATH IS NULLPTR OR NOT //
}
string Board::getPlayer() {
    if (turn == 0) {
       return "white";
    }
    return "black";
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
void Board::save() {
    std::string fname;
    fname = (name += ".txt");
    std::ofstream file;
    file.open(fname);
    file << moves;
    file.close();
    std::cout << "GAME SAVED AS " << fname << std::endl;
}
void Board::load() {
    std::cout << "1. Copy contents of desired game inside .txt file\n2. Prompt newGame()\n3. Rename game identical to file without .txt\n4. Paste contents into command line" << std::endl;

}
void Board::newGame() {
// NEED TO IMPLEMENT // CALLS emptyBoard() PROMPTS NAME FOR GAME, SET name = newName, CALL populate() //
}
void Board::emptyBoard() {
// NEED TO IMPLEMENT // Iterates through board deleting each square and setting them to nullptr //
}
void Board::populate() {
// NEED TO IMPLEMENT // Iterates through [8][8] creating new pieces ex. board[0][0] (top left corner) = new Rook("black", 0, 0) //
}
