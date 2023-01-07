#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void clearBoard();
void printBoard();
int checkFree();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
    clearBoard();
    while(winner == ' ' && checkFree() != 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFree() == 0)
        {
            break;
        }
        
        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFree() == 0)
        {
            break;
        }
    }
    printBoard();
    printWinner(winner);
    return 0;
}

void clearBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

}
void printBoard()
{
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFree()
{
    int freeSpaces = 9;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces -= 1;
            }
        }
    }
    return freeSpaces;
}
void playerMove()
{
    int x,y;
    do
    {
    
    printf("Enter row #(1-3): ");
    scanf("%d", &x);
    // since indexing starts at 0 (but the player does not know this so we have to manually account for it)
    x -= 1;
    
    printf("Enter columns #(1-3): ");
    scanf("%d", &y);
    // since indexing starts at 0 (but the player does not know this so we have to manually account for it)
    y -= 1;
    
    // if there is already a move made on in this slot, it is an invalid move
    if (board[x][y] != ' ')
    {
        printf("Invalid move!\n");
    }
    else
    {
        board[x][y] = PLAYER;
        break;
    }
    } while (board[x][y] != ' ');
}
void computerMove()
{
    // creates a seed based on current time
    srand(time(0));
    int x, y;
    if (checkFree() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}
char checkWinner()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //  check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[i][0];
        }
    }
    // check diagnoal 1
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
    // check diagonal 2
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    
    return ' ';

}
void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("YOU WIN!!");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("Its a tie!");
    }
}
