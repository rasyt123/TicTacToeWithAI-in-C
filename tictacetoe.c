#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
int gameboard(char board[3][3], int whoseturn);
bool edges(int row, int column, char board[3][3]);
bool corners(int moverow, int movecolumn, char board[3][3]);
int hardaigameboard(char board[3][3], int whoseturn);
bool determineaiwinner(char board[3][3], int currentplayer);
bool diagonalwin(char board[3][3], int currentplayer);
bool determinewinner(char board[3][3], int currentplayer, bool choice);
bool verticalwin(char board[3][3], int currentplayer);
bool horizontalwin(char board[3][3], int currentplayer);
bool tie(char board[3][3]);
int easyai(char board[3][3], int whoseturn);
bool hardai(char board[3][3]);
int moverow;
int movecolumn;
int main()
{
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int rows, columns, player1, player2, win, loss, numberyouwant, playerturn;
    char playerchoice;
    bool computer;
    player1 = 1;
    player2 = 2;
    putchar('\n');
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("- - - - - - \n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("- - - - - - \n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    putchar('\n');
    printf("You have three choices for opponents. C for easy ai, H for hard ai, or P for Player.");
    scanf(" %c", &playerchoice);
    if (playerchoice == 'c' || playerchoice == 'C') {
        computer = true;
        playerturn = easyai(board, 1);
        while (!determinewinner(board, playerturn, computer)) {
            playerturn = easyai(board, playerturn);
        }
    }
    else if (playerchoice == 'H' || playerchoice == 'h') {
        computer = true;
        playerturn = hardaigameboard(board, 1);
        while(!determinewinner(board, playerturn, computer)) {
            playerturn = hardaigameboard(board, playerturn);
        }
    }
    else if (playerchoice == 'p' || playerchoice == 'P') {
        computer = false;
        playerturn = gameboard(board, 1);
        while (!determinewinner(board, playerturn, computer)) {
            playerturn = gameboard(board, playerturn);
        } 
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

int easyai(char board[3][3], int whoseturn)
{
    int rows, columns, randomrow, randomcolumn, found;
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
            printf("The Computer has selected his move!");
            randomrow = rand() % 3;
            randomcolumn = rand() % 3;
            for (rows = 0; rows < 3; rows++) {
                for (columns = 0; columns < 3; columns++) {
                    if (board[randomrow][randomcolumn] == 'X' || board[randomrow][randomcolumn] == 'O') {
                        ;
                    }
                    else {
                        board[randomrow][randomcolumn] = 'O';
                        correctlymarked = false;
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

int hardaigameboard(char board[3][3], int whoseturn)
{
    int rows, columns, randomrow, randomcolumn, found;
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
            printf("The computer has made his move.");
            if (hardai(board) == true) {
                correctlymarked = false;
                putchar('\n');
                printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
                printf("- - - - - - \n");
                printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
                printf("- - - - - - \n");
                printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
            }
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

bool determinewinner(char board[3][3], int currentplayer, bool aichoice)
{
    if (horizontalwin(board, currentplayer) == true || diagonalwin(board, currentplayer) == true || verticalwin(board, currentplayer) == true && aichoice == false) {
        if (currentplayer == 1) {
            currentplayer++;
        }
        else {
            currentplayer--;
        }
        printf("Player %d wins. Ending tic tac toe now", currentplayer);
        return true;
    }
    else if (horizontalwin(board, currentplayer) == true || diagonalwin(board, currentplayer) == true || verticalwin(board, currentplayer) == true && aichoice == true) {
        if (currentplayer == 1) {
            currentplayer++;
        }
        else {
            currentplayer--;
        }
        if (currentplayer == 1) {
            printf("Player %d wins, Ending tic tac toe now.", currentplayer);
        }
        else {
            printf("The Computer wins!");
        }
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

bool determineaiwinner(char board[3][3], int currentplayer)
{
    if (horizontalwin(board, currentplayer) == true || diagonalwin(board, currentplayer) == true || verticalwin(board, currentplayer) == true) {
        return true;
    }
    else {
        return false;
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



bool hardai(char board[3][3])
{
    int rows, columns, i, numberofcorners, numberofedges, j, a, b;
    char move;
    int moverow, movecolumn;
    char possibleMoves[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int currentplayer = 2;
    numberofcorners = 0;
    numberofedges = 0;
    bool winner;
    srand(time(NULL));
    for (rows = 0; rows < 3; rows++) {
        for (columns = 0; columns < 3; columns++) {
                possibleMoves[rows][columns] = board[rows][columns];
        }      
    }

    for (rows = 0; rows < 3; rows++) {
        for (columns = 0; columns < 3; columns++) {
            if ((possibleMoves[rows][columns] != 'O' && possibleMoves[rows][columns] != 'X')) {
                possibleMoves[rows][columns] = 'O';
                winner = determineaiwinner(possibleMoves, 2);
                if (winner == true) {
                    moverow = rows;
                    movecolumn = columns;
                    board[moverow][movecolumn] = 'O';
                    return true;
                }
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        possibleMoves[i][j] = board[i][j];
                    }
                }
            }
        }
    }
    

    for (rows = 0; rows < 3; rows++) {
        for (columns = 0; columns < 3; columns++) {
            if ((possibleMoves[rows][columns] != 'O' && possibleMoves[rows][columns] != 'X')) {
                possibleMoves[rows][columns] = 'X';
                winner = determineaiwinner(possibleMoves, 2);
                if (winner == true) {
                    moverow = rows;
                    movecolumn = columns;
                    board[moverow][movecolumn] = 'O';
                    return true;
                }
                 for (a = 0; a < 3; a++) {
                    for (b = 0; b < 3; b++) {
                        possibleMoves[a][b] = board[a][b];
                    }
                }
            }
        }
    }


    for (rows = 0; rows < 3; rows++) {
        for (columns = 0; columns < 3; columns++) {
            if (possibleMoves[rows][columns] == possibleMoves[0][0] || possibleMoves[rows][columns] == possibleMoves[0][2] || possibleMoves[rows][columns] == possibleMoves[2][0] || possibleMoves[rows][columns] == possibleMoves[2][2]) {
                if (possibleMoves[rows][columns] != 'X' && possibleMoves[rows][columns] != 'O') {
                    ++numberofcorners;
                }
            }
        }
    }

    if (numberofcorners > 0) {
        do {
            moverow = rand() % 3;
            movecolumn = rand() % 3;
        } while (corners(moverow, movecolumn, board) == true);
        board[moverow][movecolumn] = 'O';
        return true;
    }

  if (possibleMoves[1][1] != 'O' || possibleMoves[1][1] != 'X') {
       board[1][1] = 'O';
       return true;
    }
  

    for (rows = 0; rows < 3; rows++) {
        for (columns = 0; columns < 3; columns++) {
            if (possibleMoves[rows][columns] == possibleMoves[0][0] || possibleMoves[rows][columns] == possibleMoves[0][2] || possibleMoves[rows][columns] == possibleMoves[2][0] || possibleMoves[rows][columns] == possibleMoves[2][2]) {
                if (possibleMoves[rows][columns] != 'X' || possibleMoves[rows][columns] != 'O') {
                    ++numberofedges;
                }
            }
        }
    }
    if (numberofedges > 0) {
        do {
            moverow = rand() % 3;
            movecolumn = rand() % 3;
        } while (edges(moverow, movecolumn, board) == true);
        board[moverow][movecolumn] = 'O';                               
        return true;
    }

    return false;
}

bool corners(int row, int column, char board[3][3]) 
{
  if (board[row][column] == 'O' || board[row][column] == 'X') {
    return true;
  }
  else {
    if (row == 0 && column == 0) {
    return false;
    }
    else if (row == 0 && column == 2) {
      return false;
    }
    else if (row == 2 && column == 0) {
      return false; 
    }
    else if (row == 2 && column == 2) {
      return false;
    }
    else {
      return true;
    }
  }  
}

bool edges(int row, int column, char board[3][3])
{
  if (board[row][column] == 'O' || board[row][column] == 'X') {
        return true;
    }
  else {
    if (row == 0 && column == 1) {
        return false;
    }
    else if (row == 1 && column == 0) {
      return false;
    }
    else if (row == 1 && column == 2) {
      return false; 
    }
    else if (row == 2 && column == 1) {
      return false;
    }
    else {
      return true;
    }
  } 

}
