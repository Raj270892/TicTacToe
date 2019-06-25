////////////////////////////////////////////////////////////////////////
// File Name : TicTacToe.h
// Author : Raj Gupta
// Date: 05/05/2019
// Description : This file contains is the header file for TicTacToe 
//               game. This file defines all the methods and members
//               required by TicTacToe class. This class reuire the 
//               player number, row and column to update the  board.
//               This class can display the values in the board.
//               This class returns status as 3 if the game is a draw or
//               return status as player number if any player has won 
//               the game. This class also validate the player. If 
//               current player received is not equal to expected 
//               player then it returns -1 as invalid status. This 
//               class also check for valid move and returns -1 for 
//               any invalid move. Invalid moves include rows/ column
//               value beyond the size of board or row and column values
//               which is already occupied.
////////////////////////////////////////////////////////////////////////
#ifndef _TICTACTOE_
#define _TICTACTOE_

#include <iostream>
#include <stdlib.h>
#define BOARDSIZE 3   ///define the size of board

class TicTacToe {
private:
    int currentPlayer;   ///Keep track of current player.
    int moveCount;       /// Maintain the count of number of moves performed.
    char board[BOARDSIZE][BOARDSIZE];    /// TicTacToe board.

    int status;          /// Specify the status of the game. 

    /// Count array for each row. To maintain the number of times a specific 
    /// player has inserted value in the specified row.
    int rowCount[BOARDSIZE];     

    /// Count array for each column. To maintain the number of times a 
    /// specific player has inserted value in the specified column.
    int columnCount[BOARDSIZE]; 

    /// Count array for each diagonal. To maintain the number of times a 
    /// specific player has inserted value in the specified diagonal.
    int diagonalCount[BOARDSIZE-1];

public:
    /// Constructor to initialize all values.
    TicTacToe();

    /// Function to display the board values.
    void displayBoard();

    /// Function to update the value of board.
    bool updateBoard(int location);

    /// Function to get the expected current player. 
    int getCurrentPlayer();

    /// Function to make a move by player in specified row and column.
    void makeMove(int player, int location);

    /// Function to update the count for row and column and digonal.
    void updateCount(int player, int location);

    /// Check if the game is over or not. 
    bool isGameOver();

    /// Display the result whether there is a winner or it is a draw.
    void displayResult();

    /// Display the instruction and menu for the game.
    void displayMenu();

    /// Reset Game setting to default
    void resetGame();

};
#endif //_TICTACTOE_
