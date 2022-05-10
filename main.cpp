#include "chess.cpp"
//more libraries//

int main() {
    char input = 0;
    int turn = 0; //turn flag//
    string player = ""; //set to empty and will be filled later//
    
    string name = "";
    cout << "Enter name for game: " << endl; //i.e. Alex vs. Sean , Daniel vs. David//
    getline(cin, name);
    Chess game(name);

    while (input != 'q') {
        game.outputGame();
	if (turn == 0) {
	    player = "white";
	    ++turn; //increments turn flag so black player is next//
	}
        else {
            player = "black";
	    turn = 0; //resets turn flag//
        }

        cout << "Currently " << player << "'s turn..." << endl
	     << "Enter input here: "; //MENU OPTIONS: (m)ove, (u)ndo, (s)ave, (l)oad, (n)ew game, (q)quit
        cin >> input;
        cout << endl;
	if (input == 'm') {
	    game.move(player); //I suggest using player as parameter and prompt the user what and where to move in the move() function//
	}
	else if (input == 'u') { //Player shouldn't have to be a parameter here, just undo last two moves one for last player played and one for player undoing//
	    game.undo();
	}
	else if (input == 's') {
	    game.save();
	}
	else if (input == 'l') {
	    game.load();
	}
	else if (input == 'n') {
	    game.newGame();
	}
	else if (input == 'q') { //Added this statement because pressing q results in error message and then closes the loop//
	    cout << "Game has ended, goodbye" << endl;
	}
	else { //encourages users to use lower case inputs, upper case will not be recognized//
	    cout << "Invalid input, try again" << endl;
	}
    }
    return 0;
}
