# CLI-Chess Game
 
  Authors: [Sean Yi](https://github.com/syi012) [Alex Ramos](https://github.com/RamosAlexCS) [David Ahn](https://github.com/dahn013) [Daniel Alcoff](https://github.com/ilkiyani)

## Project Description
  * The reason why we chose Chess is because of its timeless value and popularity. Till this very day Chess continues to thrive and evolve despite starting in the 16th century. 
  * We plan on implementing both the composite and strategy design patterns in this game. The reason we chose composite is because each object on the board will be treated as a Piece class (AKA the composite) but they are all partitioned into 6 subclasses/leafs (Pawn, Bishop, Knight, etc...). We also chose the strategy design pattern because each Piece requires a different algorithm to move across the board so the move function should prompt a specific "strategy" based on the Piece that is selected. In this case isValid in the Piece class is the Strategy and the viable(int x, int y) in the leaf classes are the Concrete Strategies.
  * The program will prompt the user to input commands such as move, undo, new game, and quit. The output will be a chessboard using characters to signify squares and borders for the x and y axis. The output should also print the pieces in the correct locations.
  * The project will be created using C++ using source-code editing tools like VSCode and XCode depending on the author.
  * Once all of the intended features are implemented our chess game is expected to differentiate legal from illegal moves, allow players to undo moves, and load unfinished games. 
  
## Class Diagram 1
  [Chess UML Class Diagram](https://drive.google.com/file/d/1Szcj0UyhY4KbvHp5DhjzDviRplMPprnY/view?usp=sharing)

## Class Diagram 2
  [Updated Chess UML Class Diagram](https://docs.google.com/file/d/1GEduaBfRixYrOmtP3e-OghWE-VfhyVZqRi6r15xAZ2M/view)
 
## Class Diagram 3
  [Final Chess UML Class Diagram](https://drive.google.com/file/d/1TP_z2gxI8cquzujQ0ruFNlctSqlXhAnQ/view?usp=sharing)

## Screenshots
  [Google doc screenshots folder](https://drive.google.com/drive/folders/1NTM0OUHa1Eg8ASEudPd-qO-8RdxXye0V?usp=sharing)

 ## Installation/Usage
  Execution
  1. Download submodules if not installed with git submdule update --init --recursive
  2. cmake .
  3. make
  4. ./play
  
  Playing
  * You can input multiple inputs in one if it is appropriate aka md2d4 (moves d2 to d4).
  * Saving creates a file of these multiple inputs with the game name as the file name.
  * Load gives you instructions how to use the save file.
  * New game prompts for a new game name and resets the board.
  * Quit ends the program/game.
 ## Testing
    We used the google test submodule to run our unit tests. We created a total of 9 tests composited into 5 test suites testing different squares. Each test tested different aspects of the square such as the type of piece that was on the square and the color associated on the square. 
 
