#include "board.cpp"
#include "board.h"
//more libraries/

int main() {
    char input = 0;
    
    string name = "";
    cout << "Enter name for game: " << endl; //i.e. Alex vs. Sean , Daniel vs. David//
    getline(cin, name);
    Board game(name);
    game.menu();

    return 0;
}
