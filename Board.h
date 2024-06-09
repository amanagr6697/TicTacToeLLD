#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Cell.h"
#include <stdexcept>
#include <vector>
#include "Player.h"

class Board
{

private:
    int boardSize;
    std::vector<std::vector<Cell>> board;

public:
    Board(int n) : boardSize(n), board(n, std::vector<Cell>(n))
    {
        std::cout << "Board Created!!"<<std::endl;
    }

    void display()
    {
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                std::cout << board[i][j].getCellValue() << " ";
            }
            std::cout << std::endl;
        }
    }

    int makeMove(int row, int col, Player player)
    {
        // checks already done: row and col verified
        if (board[row][col].getCellValue() != 0)
        {
            throw std::invalid_argument("Cell already played");
        }

        int sign = (player.getPlayer() == 0) ? -1 : 1;

        board[row][col].setCellValue(sign);

        // 0-> win for player 1
        // 1-> win for player 2
        // 2->Draw
        // 3->Game not completed
        return getWinner(row, col, player);
    }

private:
    int getWinner(int row, int col, Player player)
    {
        bool isBoardFull = true;
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                if (board[i][j].getCellValue() == 0)
                {
                    isBoardFull = false;
                    break;
                }
            }
        }
        int playerSign = (player.getPlayer() == 0) ? -1 : 1;

        bool rowWin = true, colWin = true, diagWin = true, revDiagnolWin = true;

        for (int i = 0; i < boardSize; i++)
        {
            if (board[row][i].getCellValue() != playerSign)
                rowWin = false;

            if (board[i][col].getCellValue() != playerSign)
                colWin = false;

            if (board[i][i].getCellValue() != playerSign)
                diagWin = false;

            if (board[i][boardSize - 1 - i].getCellValue() != playerSign)
                revDiagnolWin = false;
        }
        if (rowWin || colWin || diagWin || revDiagnolWin)
            return player.getPlayer() == 0 ? 0 : 1;

        if (!isBoardFull)
            return 3;

        return 2;
    }
};

#endif