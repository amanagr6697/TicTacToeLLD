#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Board.h"

class Game
{
private:
    Player player1;
    Player player2;
    Player *currentPlayer;

public:
    Game()
    {
        player1.setPlayer(0);
        player2.setPlayer(1);
    }
    void play()
    {
        int boardSize;
        std::cout << "Enter size of the board: " << std::endl;
        std::cin >> boardSize;
        Board board(boardSize);
        currentPlayer = &player1;

        while (1)
        {
            board.display();
            int row, col;
            std::cout << "Enter row and column values to play the move: "<<std::endl;
            std::cin >> row >> col;
            std::cout<<std::endl;
            
            if (row < 0 || row >= boardSize || col < 0 || col >= boardSize)
            {
                std::cout << "Invalid parameters, retry..."<<std::endl;
                continue;
            }
            int result;
            try
            {
                result = board.makeMove(row, col, *currentPlayer);
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
                continue;
            }

            if (result == 0 or result == 1 or result == 2)
            {
                declareAnswer(result);
                break;
            }

            if (currentPlayer == &player2)
                currentPlayer = &player1;
            else
                currentPlayer = &player2;
        }
    }

private:
    void declareAnswer(int x)
    {
        if (x == 0)
        {
            std::cout << "Player 1 won...!";
        }
        else if (x == 1)
        {
            std::cout << "Player 2 won...!";
        }
        else
            std::cout << "Game Drawn!";
    }
};

#endif