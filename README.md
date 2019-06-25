# TicTacToe
This repository contains TicTacToe game implementation. TicTacToe.cpp file contais TicTacToe class. This class has various API created for TicTacToe game. TicTacToe.h is the header file for the TicTacToe class. TicTacToeMain.cpp file contains main function which calls the API of TicTacToe class and runs the grame interactively for two players. This code can be compiled by following command:
```
g++ TicTacToeMain.cpp TicTacToe.cpp -o TicTacToe
```
"TicTacToe" named executable will be created after this. 
Executing this executable will display a menu for the game and then allow players to select the location for board. Input to the game should be in the format of 
```
playerNumber location
```
where playerNumber indicates player currently inserting the value and location indicates the location in the board.Player 1 is represented by X and player 2 is represented by o in this game.This game will continue till any one of the player wins or till there is a draw. At the end of the game, player gets a choice to continue the game or exit the game. This game can be continued as many times as the user wants
