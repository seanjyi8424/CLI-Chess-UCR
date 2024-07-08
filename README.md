# CLI-Chess Game
 
  Authors: [Sean Yi](https://github.com/syi012) [Alex Ramos](https://github.com/RamosAlexCS) [David Ahn](https://github.com/dahn013) [Daniel Alcoff](https://github.com/ilkiyani)
  
  This repository is updated and maintained by [Sean Yi](https://github.com/syi012) only

## Project Description
  * The reason why we chose Chess is because of its timeless value and popularity. Till this very day Chess continues to thrive and evolve despite starting in the 16th century. 
  * We plan on implementing both the composite and strategy design patterns in this game. The reason we chose composite is because each object on the board will be treated as a Piece class (AKA the composite) but they are all partitioned into 6 subclasses/leafs (Pawn, Bishop, Knight, etc...). We also chose the strategy design pattern because each Piece requires a different algorithm to move across the board so the move function should prompt a specific "strategy" based on the Piece that is selected. In this case isValid in the Piece class is the Strategy and the viable(int x, int y) in the leaf classes are the Concrete Strategies.
  * The program will prompt the user to input commands such as move, undo, new game, and quit. The output will be a chessboard using characters to signify squares and borders for the x and y axis. The output should also print the pieces in the correct locations.
  * The project will be created using C++ using source-code editing tools like VSCode and XCode depending on the author.
  * Once all of the intended features are implemented our chess game is expected to differentiate legal from illegal moves, allow players to undo moves, and load unfinished games. 
 
## Class Diagram
  ![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/618792a8-babf-453b-8ea6-d0028264abad)

## Screenshots
### Execute Program
![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/a5010787-054a-4fa8-98f4-fcc0ab996208)

### Save
![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/00235596-8819-46e2-8a3e-75ee432e7af9)

### Quit
![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/1cafe28c-8498-41a9-aedc-102ef7714bc9)

### Move
![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/271674e7-39ad-49f7-a574-ca3b163f8de8)

### Load
![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/39974a99-c9e9-4571-b510-e7427348c11a)

### Execute Load
![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/71b31159-76de-4271-90b2-b10cbc27f911)

### Game Over
![image](https://github.com/seanjyi8424/CLI-Chess-UCR/assets/108261874/29775818-de16-45e1-82fa-fb6cb4ddf9b8)

### Prompt Game Over
1. Load: me2e4me7e5mg1f3mb8c6md2d4me5d4mf3d4mf8c5mc2c3md8f6md4c6mf6f2me1f2
2. Move black bishop to F2 or input: mC5F2

 ## Installation/Usage
  Execution
  1. ``git submodule update --init --recursive``
  2. ``cmake .``
  3. ``make``
  4. ``./play``
  
  Playing
  * You can input multiple inputs in one if it is appropriate aka md2d4 (moves d2 to d4).
  * Saving creates a file of these multiple inputs with the game name as the file name.
  * Load gives you instructions how to use the save file.
  * New game prompts for a new game name and resets the board.
  * Quit ends the program/game.
 ## Testing
    We used the google test submodule to run our unit tests. We created a total of 9 tests composited into 5 test suites testing different squares. Each test tested different aspects of the square such as the type of piece that was on the square and the color associated on the square. 

    To run google tests execute the test.exe file after completing installation.
 
