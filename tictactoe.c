#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
};
void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
};
bool checkFreeSpaces()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return true;
            }
        }
    }
    return false;
};

bool playerMove() // returns true or false based on whether answer was valid
{
    // assuming there are available spaces
    int playerRow;
    int playerCol;
    printf("Enter row and column (1-3) seperated by comma, no spaces:\n");

    if (scanf(" %d,%d", &playerRow, &playerCol) == 2)
    {
        printf("\n");
        playerRow--;
        playerCol--;
        if (board[playerRow][playerCol] == '-')
        {
            // space is empty
            board[playerRow][playerCol] = 'X';
            return true;
        }
        else
        {
            printf("Space is taken.\n");
            playerMove();
        }
    }
    else
    {
        printf("Invalid answer, restart.\n");
        return false;
    }
};

void computerMove()
{
    int xcount = 0;
    int ocount = 0;

    // check rows
    for (int i = 0; i < 3; i++)
    {
        xcount = 0;
        ocount = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
            {
                xcount++;
            }
            else if (board[i][j] == 'O')
            {
                ocount++;
            }
        }

        if (ocount == 2)
        {
            printf("possible win at row %d", i);
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    board[i][j] = 'O';
                    return;
                }
            }
        }
        if (xcount == 2)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    board[i][j] = 'O';
                    return;
                }
            }
        }
    }
    xcount = 0;
    ocount = 0;

    // check columns
    for (int i = 0; i < 3; i++)
    {
        xcount = 0;
        ocount = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == 'X')
            {
                xcount++;
            }
            else if (board[j][i] == 'O')
            {
                ocount++;
            }
        }
        if (ocount == 2)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] == '-')
                {
                    board[j][i] = 'O';
                    return;
                }
            }
        }
        if (xcount == 2)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] == '-')
                {
                    board[j][i] = 'O';
                    return;
                }
            }
        }
    }
    xcount = 0;
    ocount = 0;

    // check main diag
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] == 'X')
        {
            xcount++;
        }
        else if (board[i][i] == 'O')
        {
            ocount++;
        }
    }
    if (ocount == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][i] == '-')
            {
                board[i][i] = 'O';
                return;
            }
        }
    }
    if (xcount == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][i] == '-')
            {
                board[i][i] = 'O';
                return;
            }
        }
    }
    xcount = 0;
    ocount = 0;

    // check other diag
    for (int i = 0; i < 3; i++)
    {
        if (board[i][2 - i] == 'X')
        {
            xcount++;
        }
        else if (board[i][2 - i] == 'O')
        {
            ocount++;
        }
    }
    if (ocount == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][2 - i] == '-')
            {
                board[i][2 - i] = 'O';
                return;
            }
        }
    }
    if (xcount == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][2 - i] == '-')
            {
                board[i][2 - i] = 'O';
                return;
            }
        }
    }
    xcount = 0;
    ocount = 0;

    // if no wins or blocks possible, play random available spot
    int spots = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                spots++;
            }
        }
    }

    srand(time(NULL));
    int r = rand() % spots;
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (counter == r && board[i][j] == '-')
            {
                board[i][j] = 'O';
                return;
            }
            if (board[i][j] == '-')
            {
                counter++;
            }
        }
    }
};

char checkWinner()
{
    int xcount = 0;
    int ocount = 0;
    // check rows
    for (int i = 0; i < 3; i++)
    {
        xcount = 0;
        ocount = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
            {
                xcount++;
            }
            else if (board[i][j] == 'O')
            {
                ocount++;
            }
        }
        if (xcount == 3)
        {
            return 'X';
        }
        else if (ocount == 3)
        {
            return 'O';
        }
    }
    xcount = 0;
    ocount = 0;

    // check columns
    for (int i = 0; i < 3; i++)
    {
        xcount = 0;
        ocount = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == 'X')
            {
                xcount++;
            }
            else if (board[j][i] == 'O')
            {
                ocount++;
            }
        }
        if (xcount == 3)
        {
            return 'X';
        }
        else if (ocount == 3)
        {
            return 'O';
        }
    }
    xcount = 0;
    ocount = 0;

    // check main diag
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] == 'X')
        {
            xcount++;
        }
        else if (board[i][i] == 'O')
        {
            ocount++;
        }
    }
    if (xcount == 3)
    {
        return 'X';
    }
    else if (ocount == 3)
    {
        return 'O';
    }
    xcount = 0;
    ocount = 0;

    // check other diag
    for (int i = 0; i < 3; i++)
    {
        if (board[i][2 - i] == 'X')
        {
            xcount++;
        }
        else if (board[i][2 - i] == 'O')
        {
            ocount++;
        }
    }
    if (xcount == 3)
    {
        return 'X';
    }
    else if (ocount == 3)
    {
        return 'O';
    }
    xcount = 0;
    ocount = 0;

    // if no winners, return '-'
    return '-';
};

void main()
{
    resetBoard();
    printBoard();
    while (checkFreeSpaces() && checkWinner() == '-')
    {
        if (playerMove() == false)
        {
            return;
        }

        if (checkFreeSpaces() && checkWinner() == '-')
        {
            printf("Computer playing...\n");
            computerMove();
        }
        printBoard();
    }
    if (checkWinner() == '-')
    {
        printf("Tie!\n");
    }
    else
    {
        printf("-------\n");
        printf("%c wins!\n", checkWinner());
    }
}