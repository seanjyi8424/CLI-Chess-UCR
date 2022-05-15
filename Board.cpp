#include <iostream>
using namespace std;

int main() {

	const int row = 8;
	const int column = 8;
	string board[row][column];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			board[i][j] = '-';
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << board[i][j] << "   ";
		}
		cout << i + 1 << "\n\n";
	}

	cout << "A   B   C   D   E   F   G   H\n";

	return 0;
}
