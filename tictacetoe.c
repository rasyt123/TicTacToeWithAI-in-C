#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
double minimax(char** board, int depth, bool isMax);
double aiwinchecker(char** board);
int anymovesleft(char** board);
int evaluate(char** board);
void findBestMove(char** board);

int impossibleaigameboard(char** board, int whoseturn);
int gameboard(char** board, int whoseturn);
bool edges(int row, int column, char** board);
bool corners(int moverow, int movecolumn, char** board);
int hardaigameboard(char** board, int whoseturn);
bool determineaiwinner(char** board, int currentplayer);
bool diagonalwin(char** board, int currentplayer);
bool determinewinner(char** board, int currentplayer, bool choice);
bool verticalwin(char** board, int currentplayer);
bool horizontalwin(char** board, int currentplayer);
bool tie(char** board);
int easyai(char** board, int whoseturn);
bool hardai(char** board);
char** boardcreation();
int bestmoverow, bestmovecolumn;
int moverow;
int movecolumn;
char player = 'X', ai = 'O';

char** boardcreation()
{
    char boardslot = '1';
    char** board = (char**) malloc(3 * sizeof(char*));
    for (int row = 0; row < 3; ++row) 
    {
        board[row] = (char*) malloc(3 * sizeof(char));
        for (int col = 0; col < 3; ++col) 
        {
            board[row][col] = boardslot;
            boardslot++;
        }
    }
    return board;
}


void clean_up(char*** board, const int num_rows, const int num_cols) {
  for(int row = 0; row < num_rows; ++row){
    free((*board)[row]);
  }
  free(*board);
  *board = 0;
}

int main()
{
    char** board = boardcreation();
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
    
    printf("You have three choices for opponents. C for easy ai, M for medium ai, H for hard ai, or P for Player: ");
    scanf(" %c", &playerchoice);
    if (playerchoice == 'c' || playerchoice == 'C') 
    {
        computer = true;
        playerturn = easyai(board, 1);
        while (!determinewinner(board, playerturn, computer)) 
        {
            playerturn = easyai(board, playerturn);
        }
        clean_up(&board, 3, 3);
    }
    else if (playerchoice == 'M' || playerchoice == 'm') 
    {
        computer = true;
        playerturn = hardaigameboard(board, 1);
        while(!determinewinner(board, playerturn, computer)) 
        {
            playerturn = hardaigameboard(board, playerturn);
        }
        clean_up(&board, 3, 3);
    }
    else if (playerchoice == 'H' || playerchoice == 'h') 
    {
        computer = true;
        playerturn = impossibleaigameboard(board, 1);
        while (!determinewinner(board, playerturn, computer)) 
        {
            playerturn = impossibleaigameboard(board, playerturn);
        }
        clean_up(&board, 3, 3);
    }
    else if (playerchoice == 'p' || playerchoice == 'P') 
    {
        computer = false;
        playerturn = gameboard(board, 1);
        while (!determinewinner(board, playerturn, computer)) 
        {
            playerturn = gameboard(board, playerturn);
        } 
        clean_up(&board, 3, 3);
    }
    return 0;
}


int gameboard(char** board, int whoseturn)
{
    int rows, columns;
    char numberyouwant;
    bool spaceoccupied, correctlymarked;
    spaceoccupied = false;
    correctlymarked = true;
    if (whoseturn == 1) 
    {
        while (!spaceoccupied && correctlymarked == true) 
        {
            printf("Player 1, please enter the number of the square where you want to place your X: ");
            scanf(" %c", &numberyouwant);
            for (rows = 0; rows < 3;rows++) 
            {
                for (columns = 0; columns < 3;columns++) 
                {
                    if (board[rows][columns] == numberyouwant) 
                    {
                        if (board[rows][columns] == 'X' || board[rows][columns] == 'O') 
                        {
                            spaceoccupied = true;
                            printf("The space is occupied, please try again.");
                        }
                        else 
                        {
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
    else if (whoseturn == 2) 
    {
        while (!spaceoccupied && correctlymarked == true) 
        {
            printf("Player 2, please enter the number of the square where you want to place your O: ");
            scanf(" %c", &numberyouwant);
            for (rows = 0; rows < 3 ;rows++) 
            {
                for (columns = 0; columns < 3; columns++) 
                {
                    if (board[rows][columns] == numberyouwant) 
                    {
                        if (board[rows][columns] == 'X' || board[rows][columns] == 'O') 
                        {
                            spaceoccupied = true;
                            printf("The space is occupied, please try again.");
                        }
                        else 
                        {
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

int easyai(char** board, int whoseturn)
{
    int rows, columns, randomrow, randomcolumn, found;
    char numberyouwant;
    bool spaceoccupied, correctlymarked;
    spaceoccupied = false;
    correctlymarked = true;
    if (whoseturn == 1) 
    {
        while (!spaceoccupied && correctlymarked == true) 
        {
            printf("Player 1, please enter the number of the square where you want to place your X: ");
            scanf(" %c", &numberyouwant);
            for (rows = 0; rows < 3;rows++) 
            {
                for (columns = 0; columns < 3;columns++) 
                {
                    if (board[rows][columns] == numberyouwant) 
                    {
                        if (board[rows][columns] == 'X' || board[rows][columns] == 'O') 
                        {
                            spaceoccupied = true;
                            printf("The space is occupied, please try again.");
                        }
                        else 
                        {
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
    else if (whoseturn == 2) 
    {
        while (!spaceoccupied && correctlymarked == true) 
        {
            printf("The Computer has selected his move!");
            randomrow = rand() % 3;
            randomcolumn = rand() % 3;
            for (rows = 0; rows < 3; rows++) 
            {
                for (columns = 0; columns < 3; columns++) 
                {
                    if (board[randomrow][randomcolumn] == 'X' || board[randomrow][randomcolumn] == 'O') 
                    {
                        ;
                    }
                    else 
                    {
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


    if (whoseturn == 1) 
    {
        whoseturn = whoseturn + 1;
    }
    else if (whoseturn == 2) 
    {
        whoseturn = whoseturn - 1;
    }
    return whoseturn;

}

int hardaigameboard(char** board, int whoseturn)
{
    int rows, columns, randomrow, randomcolumn, found;
    char numberyouwant;
    bool spaceoccupied, correctlymarked;
    spaceoccupied = false;
    correctlymarked = true;
    if (whoseturn == 1) 
    {
        while (!spaceoccupied && correctlymarked == true) 
        {
            putchar('\n');
            printf("Player 1, please enter the number of the square where you want to place your X: ");
            scanf(" %c", &numberyouwant);
            putchar('\n');
            for (rows = 0; rows < 3;rows++) 
            {
                for (columns = 0; columns < 3;columns++) 
                {
                    if (board[rows][columns] == numberyouwant) 
                    {
                        if (board[rows][columns] == 'X' || board[rows][columns] == 'O') 
                        {
                            spaceoccupied = true;
                            printf("The space is occupied, please try again.");
                        }
                        else 
                        {
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
            putchar('\n');
        }
    }
    else if (whoseturn == 2) 
    {
        while (!spaceoccupied && correctlymarked == true) 
        {
            putchar('\n');
            printf("The computer has made his move.");
            putchar('\n');
            if (hardai(board) == true) 
            {
                correctlymarked = false;
                putchar('\n');
                printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
                printf("- - - - - - \n");
                printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
                printf("- - - - - - \n");
                printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
                putchar('\n');
            }
        }

    }
    if (whoseturn == 1) 
    {
        whoseturn = whoseturn + 1;
    }
    else if (whoseturn == 2) 
    {
        whoseturn = whoseturn - 1;
    }
    return whoseturn;
}





bool horizontalwin(char** board, int currentplayer)
{
    int rows, columns;
    columns = 0;
    for (rows = 0; rows <= 2; rows++) 
    {
        if (board[rows][columns] == board[rows][columns + 1] && board[rows][columns + 2] == board[rows][columns + 1]) 
        {
            return true;
        }
    }
    return false;
}

bool diagonalwin(char** board, int currentplayer)
{
    int rows, columns;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        return true;
    }
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) 
    {
        return true;
    }
    else 
    {
        return false;
    }

}

bool determinewinner(char** board, int currentplayer, bool aichoice)
{
    if (horizontalwin(board, currentplayer) == true || diagonalwin(board, currentplayer) == true || verticalwin(board, currentplayer) == true && aichoice == false) 
    {
        if (currentplayer == 1) 
        {
            currentplayer++;
        }
        else 
        {
            currentplayer--;
        }
        printf("Player %d wins. Ending tic tac toe now", currentplayer);
        return true;
    }
    else if (horizontalwin(board, currentplayer) == true || diagonalwin(board, currentplayer) == true || verticalwin(board, currentplayer) == true && aichoice == true) 
    {
        if (currentplayer == 1) 
        {
            currentplayer++;
        }
        else 
        {
            currentplayer--;
        }
        if (currentplayer == 1) 
        {
            printf("Player %d wins, Ending tic tac toe now.", currentplayer);
        }
        else 
        {
            printf("The Computer wins!");
        }
        return true;
    }
    else 
    {
        if (tie(board) == true) 
        {
            printf("This is a tie. Nobody Wins.");
            return true;
        }
        else 
        {
            return false;
        }
    }

}

bool determineaiwinner(char** board, int currentplayer)
{
    if (horizontalwin(board, currentplayer) == true || diagonalwin(board, currentplayer) == true || verticalwin(board, currentplayer) == true) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}


bool verticalwin(char** board, int currentplayer)
{
    int columns;
    for (columns = 0; columns < 3; columns++) 
    {
        if (board[0][columns] == board[1][columns] && board[0][columns] == board[2][columns]) 
        {
            return true;
        }
    }
    return false;
}


bool tie(char** board)
{
    int rows, columns, counter;
    counter = 0;
    for (rows = 0; rows < 3; rows++) 
    {
        for (columns = 0; columns < 3; columns++) 
        {
            if (board[rows][columns] == 'O' || board[rows][columns] == 'X') 
            {
                counter++;
            }
        }
    }
    if (counter == 9) 
    {
        return true;
    }
    else {
        return false;
    }
}



bool hardai(char** board)
{
    int rows, columns, i, numberofcorners, numberofedges, j, a, b;
    char move;
    int moverow, movecolumn;
    char** possibleMoves = boardcreation();
    int currentplayer = 2;
    numberofcorners = 0;
    numberofedges = 0;
    bool winner;
    srand(time(NULL));
    for (rows = 0; rows < 3; rows++) 
    {
        for (columns = 0; columns < 3; columns++) 
        {
                possibleMoves[rows][columns] = board[rows][columns];
        }      
    }

    for (rows = 0; rows < 3; rows++) 
    {
        for (columns = 0; columns < 3; columns++) 
        {
            if ((possibleMoves[rows][columns] != 'O' && possibleMoves[rows][columns] != 'X')) 
            {
                possibleMoves[rows][columns] = 'O';
                winner = determineaiwinner(possibleMoves, 2);
                if (winner == true) 
                {
                    moverow = rows;
                    movecolumn = columns;
                    board[moverow][movecolumn] = 'O';
                    return true;
                }
                for (i = 0; i < 3; i++) 
                {
                    for (j = 0; j < 3; j++) 
                    {
                        possibleMoves[i][j] = board[i][j];
                    }
                }
            }
        }
    }
    

    for (rows = 0; rows < 3; rows++) 
    {
        for (columns = 0; columns < 3; columns++) 
        {
            if ((possibleMoves[rows][columns] != 'O' && possibleMoves[rows][columns] != 'X')) 
            {
                possibleMoves[rows][columns] = 'X';
                winner = determineaiwinner(possibleMoves, 2);
                if (winner == true) 
                {
                    moverow = rows;
                    movecolumn = columns;
                    board[moverow][movecolumn] = 'O';
                    return true;
                }
                 for (a = 0; a < 3; a++) 
                 {
                    for (b = 0; b < 3; b++) 
                    {
                        possibleMoves[a][b] = board[a][b];
                    }
                }
            }
        }
    }


    for (rows = 0; rows < 3; rows++) 
    {
        for (columns = 0; columns < 3; columns++) 
        {
            if (possibleMoves[rows][columns] == possibleMoves[0][0] || possibleMoves[rows][columns] == possibleMoves[0][2] || possibleMoves[rows][columns] == possibleMoves[2][0] || possibleMoves[rows][columns] == possibleMoves[2][2]) 
            {
                if (possibleMoves[rows][columns] != 'X' && possibleMoves[rows][columns] != 'O') 
                {
                    ++numberofcorners;
                }
            }
        }
    }

    if (numberofcorners > 0) 
    {
        do 
        {
            moverow = rand() % 3;
            movecolumn = rand() % 3;
        } while (corners(moverow, movecolumn, board) == true);
        board[moverow][movecolumn] = 'O';
        return true;
    }

  if (possibleMoves[1][1] != 'O' && possibleMoves[1][1] != 'X') 
  {
       board[1][1] = 'O';
       return true;
  }
  

    for (rows = 0; rows < 3; rows++) 
    {
        for (columns = 0; columns < 3; columns++) 
        {
            if (possibleMoves[rows][columns] == possibleMoves[0][0] || possibleMoves[rows][columns] == possibleMoves[0][2] || possibleMoves[rows][columns] == possibleMoves[2][0] || possibleMoves[rows][columns] == possibleMoves[2][2]) 
            {
                if (possibleMoves[rows][columns] != 'X' || possibleMoves[rows][columns] != 'O') 
                {
                    ++numberofedges;
                }
            }
        }
    }
    if (numberofedges > 0) 
    {
        do 
        {
            moverow = rand() % 3;
            movecolumn = rand() % 3;
        } while (edges(moverow, movecolumn, board) == true);
        board[moverow][movecolumn] = 'O';                               
        return true;
    }

    return false;
}

bool corners(int row, int column, char** board) 
{
  if (board[row][column] == 'O' || board[row][column] == 'X')
   {
    return true;
  }
  else 
  {
    if (row == 0 && column == 0) 
    {
        return false;
    }
    else if (row == 0 && column == 2) 
    {
      return false;
    }
    else if (row == 2 && column == 0) 
    {
      return false; 
    }
    else if (row == 2 && column == 2) 
    {
      return false;
    }
    else 
    {
      return true;
    }
  }  
}

bool edges(int row, int column, char** board)
{
  if (board[row][column] == 'O' || board[row][column] == 'X') 
    {
        return true;
    }
  else {
    if (row == 0 && column == 1) 
    {
        return false;
    }
    else if (row == 1 && column == 0) 
    {
      return false;
    }
    else if (row == 1 && column == 2) 
    {
      return false; 
    }
    else if (row == 2 && column == 1) 
    {
      return false;
    }
    else {
      return true;
    }
  }
}

double aiwinchecker(char** board)
{
    int rows, columns;
    columns = 0;
    for (rows = 0; rows <= 2; rows++) 
    {
        if (board[rows][columns] == board[rows][columns + 1] && board[rows][columns + 2] == board[rows][columns + 1]) 
        {
            if (board[rows][columns] == ai) 
            {
                return 10;
            } 
            else if (board[rows][columns] == player) 
            {
                return -10;
            }
        }
    }

    for (columns = 0; columns < 3; columns++) 
    {
        if (board[0][columns] == board[1][columns] && board[0][columns] == board[2][columns]) 
        {
            if (board[0][columns] == ai) 
            {
                return 10;
            }
            else if (board[0][columns] == player) 
            {
                return -10;
            }
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        if (board[0][0] == ai) 
        {
            return 10;
        }
        else if (board[0][0] == player) 
        {
            return -10;
        }
    }
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) 
    {
       if (board[2][0] == ai) 
       {
           return 10;
       }
       else if (board[2][0] == player) 
       {
           return -10;
       }
    }
    return 0;
}

double minimax(char** board, int depth, bool isMax)
{
    double score = aiwinchecker(board);
    char oldmove;

    if (score == 10.0) 
    {
        return score;
    }
    if (score == -10.0) 
    {
        return score;
    }
    if (anymovesleft(board) == false) 
    {
        return 0;
    }
    if (isMax)
    {
        double best = -1000;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] != 'O' && board[i][j] != 'X') 
                {
                    oldmove = board[i][j];
                    board[i][j] = ai;
                    best = fmax(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = oldmove;
                }
            }
        }
        return best;
    }
    else 
    {
        double best = 1000;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] != 'O' && board[i][j] != 'X') 
                {
                    oldmove = board[i][j];
                    board[i][j] = player;
                    best = fmin(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = oldmove;
                }
            }
        }
        return best;
    }

}

int anymovesleft(char** board)
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4' || board[i][j] == '5' || board[i][j] == '6' || board[i][j] == '7' || board[i][j] == '8' || board[i][j] == '9') {
                return true;
            }
        }
    }
    return false;
}

void findBestMove(char** board)
{
    char oldmove;
    double bestval = -1000;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != 'O' && board[i][j] != 'X') 
            {
                oldmove = board[i][j];
                board[i][j] = ai;
                int moveVal = minimax(board, 0, false);
                board[i][j] = oldmove;

                if (moveVal > bestval) 
                {
                    bestmoverow = i;
                    bestmovecolumn = j;
                    bestval = moveVal;
                }
            }
        }
    }
}


int impossibleaigameboard(char** board, int whoseturn)
{
    int rows, columns, randomrow, randomcolumn, found;
    char numberyouwant;
    bool spaceoccupied, correctlymarked;
    spaceoccupied = false;
    correctlymarked = true;
    if (whoseturn == 1) 
    {
        while (!spaceoccupied && correctlymarked == true) 
        {
            putchar('\n');
            printf("Player 1, please enter the number of the square where you want to place your X: ");
            scanf(" %c", &numberyouwant);
            putchar('\n');
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
            putchar('\n');
        }
    }
    else if (whoseturn == 2) 
    {
            findBestMove(board);
            board[bestmoverow][bestmovecolumn] = 'O';
            putchar('\n');
            printf("The computer has made his move.");
            putchar('\n');

            putchar('\n');
            printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
            printf("- - - - - - \n");
            printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
            printf("- - - - - - \n");
            printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
            putchar('\n');
    }
    if (whoseturn == 1) 
    {
        whoseturn = whoseturn + 1;
    }
    else if (whoseturn == 2) 
    {
        whoseturn = whoseturn - 1;
    }
    return whoseturn;
}
