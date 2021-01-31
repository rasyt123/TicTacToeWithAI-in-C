#include <stdio.h>
#include <stdbool.h>
int gameboard(char board[3][3], int whoseturn);
bool diagonalwin(char board[3][3], int currentplayer);
bool determinewinner(char board[3][3], int currentplayer);
bool verticalwin(char board[3][3], int currentplayer);
bool horizontalwin(char board[3][3], int currentplayer);
bool tie(char board[3][3]);


int main()
{
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int rows, columns, player1, player2, win, loss, numberyouwant, playerturn;
    player1 = 1;
    player2 = 2;
    putchar('\n');
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("- - - - - - \n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("- - - - - - \n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    playerturn = gameboard(board, 1);
    while (!determinewinner(board, playerturn)) {
         playerturn = gameboard(board, playerturn);
    }
    return 0;
}


int gameboard(char board[3][3], int whoseturn)
{
    int rows, columns;
    char numberyouwant;
    bool spaceoccupied, correctlymarked;
    spaceoccupied = false;
    correctlymarked = true;
    if (whoseturn == 1) {
        while (!spaceoccupied && correctlymarked == true) {
            printf("Player 1, please enter the number of the square where you want to place your X: ");
            scanf(" %c", &numberyouwant);
            for (rows = 0; rows < 3;rows++) {
                for (columns = 0; columns < 3;columns++) {
                    if (board[rows][columns] == numberyouwant) {
                        if (board[rows][columns] == 'X' || board[rows][columns] == 'O') {
                            spaceoccupied = true;
                            printf("The space is occupied, please try again.");
                        }
                        else {
                            board[rows][columns] = 'X';
                            correctlymarked = false;
                        }
                    }
                }
            }
            putchar('\n');
            printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
            printf("- - - - - - \n");
            printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
            printf("- - - - - - \n");
            printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
        }
    }
    else if (whoseturn == 2) {
        while (!spaceoccupied && correctlymarked == true) {
            printf("Player 2, please enter the number of the square where you want to place your O: ");
            scanf(" %c", &numberyouwant);
            for (rows = 0; rows < 3 ;rows++) {
                for (columns = 0; columns < 3; columns++) {
                    if (board[rows][columns] == numberyouwant) {
                        if (board[rows][columns] == 'X' || board[rows][columns] == 'O') {
                            spaceoccupied = true;
                            printf("The space is occupied, please try again.");
                        }
                        else {
                            board[rows][columns] = 'O';
                            correctlymarked = false;
                        }
                   }
               }
           }
            putchar('\n');
            printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
            printf("- - - - - - \n");
            printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
            printf("- - - - - - \n");
            printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
        }
    }
    if (whoseturn == 1) {
        whoseturn = whoseturn + 1;
    }
    else if (whoseturn == 2) {
        whoseturn = whoseturn - 1;
    }
    return whoseturn;
}

bool horizontalwin(char board[3][3], int currentplayer)
{
    int rows, columns;
    columns = 0;
    for (rows = 0; rows <= 2; rows++) {
        if (board[rows][columns] == board[rows][columns + 1] && board[rows][columns + 2] == board[rows][columns + 1]) {
            return true;
        }
    }
    return false;
}

bool diagonalwin(char board[3][3], int currentplayer)
{
    int rows, columns;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        return true;
    }
    else {
        return false;
    }

}

bool determinewinner(char board[3][3], int currentplayer)
{
    if (horizontalwin(board, currentplayer) == true || diagonalwin(board, currentplayer) == true || verticalwin(board, currentplayer) == true) {
        if (currentplayer == 1) {
            currentplayer++;
        }
        else {
            currentplayer--;
        }
        printf("Player %d wins. Ending tic tac toe now", currentplayer);
        return true;
    }
    else {
        if (tie(board) == true) {
            printf("This is a tie. Nobody Wins.");
            return true;
        }
        else {
            return false;
        }
    }

}


bool verticalwin(char board[3][3], int currentplayer)
{
    int columns;
    for (columns = 0; columns < 3; columns++) {
        if (board[0][columns] == board[1][columns] && board[0][columns] == board[2][columns]) {
            return true;
        }
    }
    return false;
}


bool tie(char board[3][3])
{
    int rows, columns, counter;
    counter = 0;
    for (rows = 0; rows < 3; rows++) {
        for (columns = 0; columns < 3; columns++) {
            if (board[rows][columns] == 'O' || board[rows][columns] == 'X') {
                counter++;
            }
        }
    }
    if (counter == 9) {
        return true;
    }
    else {
        return false;
    }
}
