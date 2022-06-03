#include "Board.h"
#include <iostream>
using namespace std;

Board::Board(string b) {
	name = b;
	populate();
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
    if (board[a][b] == nullptr) {
        std::cout << "Square selected is empty" << std::endl;
        return;
    }
    if(getPlayer() != board[a][b]->getColor()) 
    { //base case to prevent players from moving pieces that aren't their color//
        std::cout << "NOT YOUR COLOR TRY AGAIN" << std::endl;
        return;
    }
    else {
        if (blocked(a, b, x, y) != true) { // Checks to see if path is blocked
            if (board[a][b]->isValid(board[x][y], x, y) == true) {
                if (board[x][y] != nullptr) { // Kill action
                    if (board[x][y]->getPiece() == 'k' || board[x][y]->getPiece() == 'K') {
                        gameOver = true;
                        std::cout << getPlayer() << " player has killed opponent's King, game over" << std::endl;

                    }
                    delete board[x][y];
                    board[x][y] = nullptr;
                    board[x][y] = board[a][b];
                    board[a][b] = nullptr;
                    if (turn == 0) {
                        ++turn;
                    }
                    else {
                        --turn;
                    }
                    moves += 'm';
                    moves += char(b + 97);
                    moves += abs(a - 8) + 48;
                    moves += char(y + 97);
                    moves += abs(x - 8) + 48;
                }
                else {
                    board[x][y] = board[a][b];
                    board[a][b] = nullptr;
                    if (turn == 0) {
                        ++turn;
                    }
                    else {
                        --turn;
                    }
                    moves += 'm';
                    moves += char(b + 97);
                    moves += abs(a - 8) + 48;
                    moves += char(y + 97);
                    moves += abs(x - 8) + 48;
                }
            }
        }
    }
}
bool Board::blocked(int a, int b, int x, int y) { // checks throughout the board to see if there are pieces blocking the way // ME
    if (board[a][b]->getPiece() == 'q' || board[a][b]->getPiece() == 'Q') { //queen block
        if (a == x) { // horizontal
            for (int i = 1; i < abs(b - y); ++i) {
                if (board[a][b + i] != nullptr) {
                    std::cout << "Path blocked" << std::endl;
                    return true;
                }
            }
            return false;
        }
        else if (b == y) { // vertical
            for (int i = 1; i < abs(a - x); ++i) {
                if (board[a + i][b] != nullptr) {
                    std::cout << "Path blocked HELLO" << a+i << std::endl;
                    return true;
                }
            }
            return false;
        }
        else {
            int h = y > b ? 1 : -1;
            int v = x > a ? 1 : -1;
            for (int i = 1; i <= abs(x - a) - 1; ++i) {
                if (board[a + i * v][b + i * h] != nullptr) {
                    std::cout << "Path blocked" << std::endl;
                    return true;
                }
            } 
            return false;
        }
        return false;
    }
    else if (board[a][b]->getPiece() == 'b'|| board[a][b]->getPiece() == 'B') { // bishop block
        int h = y > b ? 1 : -1;
        int v = x > a ? 1 : -1;
        for (int i = 1; i <= abs(x - a) - 1; ++i) {
            if (board[a + i * v][b + i * h] != nullptr) {
                std::cout << "Path blocked" << std::endl;
                return true;
            }
        }
        return false;
    }
    else if (board[a][b]->getPiece() == 'p' || board[a][b]->getPiece() == 'P') { // pawn block
        if (board[a][b]->getColor() == "black") {
            for (int i = 1; i <= abs(a - x) - 1; ++i ) {
                if (board[a + i][y] != nullptr) {
                    return true;
                }
            }
        }
        else {
            for (int i = 1; i < abs(a - x) - 1; ++i ) {
                if (board[a - i][y] != nullptr) {
                    return true;
                }
            }
        }
        return false;
    }
    else if (board[a][b]->getPiece() == 'k' || board[a][b]->getPiece() == 'K') { // king block
        // Not needed? Only moves one square and friendly fire already blocks it //
        return false;
    }
    else if (tolower(board[a][b]->getPiece()) == 'r' || board[a][b]->getPiece() == 'R') { // rook block
        if (a == x) { // horizontal
            for (int i = 1; i < abs(b - y); ++i) {
                if (board[a][b + i] != nullptr) {
                    std::cout << "Path blocked" << std::endl;
                    return true;
                }
            }
        }
        else if (b == y) { // vertical
            for (int i = 1; i < abs(a - x); ++i) {
                if (board[a + i][b] != nullptr) {
                    std::cout << "Path blocked" << std::endl;
                    return true;
                }
            }
        }
        return false;
    }
    return false; // Knights can jump anywhere
}

string Board::getPlayer() {
    if (turn == 0) {
       return "white";
    }
    return "black";
}
void Board::emptyBoard() {
	// NEED TO IMPLEMENT // Iterates through board deleting each square and setting them to nullptr //
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete board[i][j];
			board[i][j] = nullptr;
		}
	}
}

void Board::printBoard() {
	cout << "[" << name << "]\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != nullptr) { //will be used to see if there is a piece in this position, if so, save piece, else, save "-"
				cout << board[i][j]->getPiece();
			}
			else {
				cout << "-";
			}
			cout << "   ";
		}
		cout << i + 1 << "\n\n";
	}

	cout << "A   B   C   D   E   F   G   H\n";
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
	string newGame;
	emptyBoard();
	cout << "Enter a name for your game\n";
	cin.ignore();
	getline(cin, newGame);
	name = newGame;
	populate();
}

void Board::populate() {
	board[0][0]=new Rook("black",0,0);
	board[0][1]=new Knight("black",0,1);
	board[0][2]=new Bishop("black",0,2);
	board[0][3]=new Queen("black",0,3);
	board[0][4]=new King("black",0,4);
	board[0][5]=new Bishop("black",0,5);
	board[0][6]=new Knight("black",0,6);
	board[0][7]=new Rook("black",0,7);
	for(int i=0;i<8;i++){
		board[1][i]=new Pawn("black",1,i);
	}
	for(int i=2;i<6;i++){
		for(int j=0;j<8;j++){
			board[i][j]=nullptr;
		}
	}
	for(int i=0;i<8;i++){
		board[6][i]=new Pawn("white",6,i);
	}
	board[7][0]=new Rook("white",7,0);
	board[7][1]=new Knight("white",7,1);
	board[7][2]=new Bishop("white",7,2);
	board[7][3]=new Queen("white",7,3);
	board[7][4]=new King("white",7,4);
	board[7][5]=new Bishop("white",7,5);
	board[7][6]=new Knight("white",7,6);
	board[7][7]=new Rook("white",7,7);
}