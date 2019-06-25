////////////////////////////////////////////////////////////////////////
// File Name : TicTacToe.cpp
// Author : Raj Gupta
// Date: 05/05/2019
// Description : This file contains declaration of members required
//               for TicTacToe game. 
////////////////////////////////////////////////////////////////////////

#include "TicTacToe.h"

/**
Constructor to initialize all the memeber values. All the count values 
are initialize to zero and board is initalized with spaces.
*/
TicTacToe::TicTacToe()
{
    ///Initilize board with location values to be used by player. 
    int counter = -1;
    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            board[i][j] = ++counter+'0';
        }
    }

    /// Select player randomly.
    currentPlayer = rand()%2+1;

    ///Initialize all counts to 0
    moveCount = 0;
    status = 0;
    for (int i = 0; i < BOARDSIZE; i++) {
        rowCount[i] = 0;
        columnCount[i] = 0;
    }
    diagonalCount[0] = diagonalCount[1] = 0;
}

/**
Function Name: displayBoard
Description: It displays the values in the board.
*/
void TicTacToe::displayBoard()
{
    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
}

/**
Function Name: updateBoard
Description: It updates the board value for given row and column 
of the board. It validates the row and column value before updating.
If the row or column value is out of range of board size then it 
will return false. If the specified row and column is not empty 
then also false will be returned. If there is no such invalid consition
then it will update the board and return true

@return boolean
        action was valid(true)/not(false)
@param row: row of board
       col: column of board
*/
bool TicTacToe::updateBoard(int location)
{
    int row = location/3;
    int col = location%3;
    if (row < 0 || row >= BOARDSIZE || col < 0 || col >= BOARDSIZE)
    {
        std::cout<<"XXX Specified location is out of bound XXX"<<std::endl;
        return false;
    }
    else if (board[row][col] == 'X' || board[row][col] == 'o')
    {
        std::cout<<"XXX Specified location is not empty XXX"<<std::endl;
        return false;
    }

    if (currentPlayer == 1)
        board[row][col] = 'X';
    else
        board[row][col] = 'o';
    return true;
}

/**
Function Name: updateCount
Description: It update the count for row, column and diagonal.
             It update the row index for rowCount, column index
             for colCount and diagonal array depending upon if the
             update is on diagobnal or not. This count is upodated 
             based on player. This count can be checked later to see
             if any player has won the game.

@param player: player number performing the action
       row: row of board
       col: column of board
*/
void TicTacToe::updateCount(int player, int location)
{
    int row = location/3;
    int col = location%3;
    int add;
    if (player == 1)
        add = 1;
    else
        add = -1;
    
    rowCount[row] += add;
    columnCount[col] += add;
    if (row == col)
        diagonalCount[0] += add;
    if (row + col == BOARDSIZE - 1)
        diagonalCount[1] += add;
}

/**
Function Name: isGameOver
Description: It check if the status has changed or not
@return boolean
        true if game is over, false if not
*/
bool TicTacToe::isGameOver()
{ 
   if (status == 0)
      return false;

   return true;
}

/**
Function Name: makeMove
Description: It is the function used to perform the move action. 
             This function updateBoard value with the help of 
             updateBoard function. 
             It set the status of the game according.
             Following status represent the result of the game:
             status 0 indicates game is still running
             status -1 indicates invalid move
             status 3 indicates that the game is a draw
             status 1 indicates player 1 won the game
             status 2 indicates player 2 won the game

@param player: player number performing the action
       row: row of board
       col: column of board
*/
void TicTacToe::makeMove(int player, int location)
{
    int row = location/3;
    int col = location%3;
    if (player == currentPlayer) {
        if (updateBoard(location)) //update Board depending on number
        {
            moveCount++;
            updateCount(player, location);
            //current player has won the game if any of the count is equal to n
            if (rowCount[row] == BOARDSIZE || columnCount[col] == BOARDSIZE 
                  || diagonalCount[0] == BOARDSIZE || diagonalCount[1] == BOARDSIZE
                  || rowCount[row] == -BOARDSIZE || columnCount[col] == -BOARDSIZE 
                  || diagonalCount[0] == -BOARDSIZE || diagonalCount[1] == -BOARDSIZE){

                 status = currentPlayer;
             }
             // If number of moves is equal to n*n then the board is filled and there is a draw
             else if (moveCount == BOARDSIZE * BOARDSIZE)
             {
                 status = 3;
             }

            else if (currentPlayer == 1) //Toggle player if board update was successfull
                currentPlayer = 2;
            else {
                currentPlayer = 1;
            }
            displayBoard();
        }
    }
    else
        std::cout<<"XXX Wrong Player XXX"<<std::endl;
}

/**
Function Name: getCurrentPlayer
Description: This function returns the expected current player number

@return integer status
        return current player number.
*/

int TicTacToe::getCurrentPlayer()
{
    return currentPlayer;
}

/**
Function Name: displayResult
Description: This function display the result of the game 
*/
void TicTacToe::displayResult()
{
   if (status == 0)
      std::cout<<"Game is incomplete"<<std::endl;
   if (status == 3)
      std::cout<<"There is a draw"<<std::endl;
   if (status == 1 || status == 2)
      std::cout<<"Player "<<status<<" won the game"<<std::endl;
}

/**
Function Name: displayMenu
Description: This function display the menu for the game.
*/
void TicTacToe::displayMenu()
{
    std::cout<<"==================================================================="<<std::endl;
    std::cout<<"Welcome to Tic-Tac-Toe game. "<<std::endl;
    std::cout<<"The specified player should enter the location of the board."<<std::endl;
    std::cout<<"Input format should be :playerName location"<<std::endl;
    std::cout<<"eg: 1 2 means player 1 will fill location 2"<<std::endl;
    std::cout<<"A player should only insert specified location"<<std::endl;
    std::cout<<"Rules of the game:"<<std::endl;
    std::cout<<"    A player wins if it fills all the row or column or either of a diagonal"<<std::endl;
    std::cout<<"    Game is draw if all the locations are filled and there is no winner for the game"<<std::endl;
    std::cout<<"==================================================================="<<std::endl;
    displayBoard();
}

/**
Function Name: resetGame
Description: This function reset all counts to zero and reset board to initial values.
*/
void TicTacToe::resetGame()
{
    int counter = -1;
    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            board[i][j] = ++counter+'0';
        }
    }
    moveCount = 0;
    status = 0;
    for (int i = 0; i < BOARDSIZE; i++) {
        rowCount[i] = 0;
        columnCount[i] = 0;
    }
    diagonalCount[0] = diagonalCount[1] = 0;
    displayBoard();
}
