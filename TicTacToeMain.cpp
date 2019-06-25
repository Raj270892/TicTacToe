////////////////////////////////////////////////////////////////////////
// File Name : TicTacToeMain.cpp
// Author : Raj Gupta
// Date: 05/05/2019
// Description : This file contains a main in order to test the 
//               TicTacToe class. It takes number of input first and 
//               then take all the input in pair of 3 where. First 
//               value of pair indicates the player number, second 
//               value indicates the row for board, third value 
//               indicates the column for board where player want to 
//               insert its value. This main function creates an 
//               object of TicTacToe class and display the board value 
//               at first. It performs series of moves given in input 
//               and then uses the return status to find the invalid 
//               or won or draw status. It display the value of board 
//               at the end of all moves. 
////////////////////////////////////////////////////////////////////////

#include "TicTacToe.h"

int main()
{
    int lengthOfInput;
    TicTacToe ttt;
    int player;
    int location;
    int invalidChoice;
    char choice = 'y';
    ttt.displayMenu();
    while(choice == 'y' || choice == 'Y')
    {
        invalidChoice = 30;
        while(!ttt.isGameOver())
        {
            std::cout<<"Player "<<ttt.getCurrentPlayer()<<" please select location"<<std::endl;
            std::cin>>player;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cout<<"Invalid player number"<<std::endl;
                continue;      
                }
                std::cin>>location;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cout<<"Invalid location"<<std::endl;
                continue;      
            }
            ttt.makeMove(player, location);
        }
        ttt.displayResult();
        while(invalidChoice--)
        {
            std::cout<<"Do you want to continue?(y/Y or n/N)"<<std::endl;
            std::cin>>choice;
            if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
                std::cout<<"Invalid choice"<<std::endl;
            else
            {
                ttt.resetGame();
                break;
            }
        }

    }
    return 0;
}
