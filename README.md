# TicTacToeWithAI-in-C
My name is Justin and I'm a CS freshman at UC Davis. I've been coding for a few months, and I'm still a beginner but this is my first programming project :), so excuse me for the messy code. I'll make it spicier by adding pointers/dynamic memory allocation later.

I created a Tic Tac Toe game in which the user can decide to play against another player or the computer. I created an easy ai, medium ai, and hard ai to distinguish the levels
of strength the computer can play at.

1. Easy Ai - The computer randomly generates a move on any open board space and selects it. I used srand() and rand to produce this random effect and generated rows and columns
with the modulo function.

2. Medium Ai - I used Tech with Tim's idea for this. Firstly, the computer checks for a win for the player and itself and chooses to block or select a winning move. If there is
no immediate winning combination, the computer places a move into the corners of the board. If all the corners are occupied but the center isn't, the computer will select a move
in the center. If the center is occupied, the computer will choose a random edge to place an O in. If all of these conditions are false, then we know that the game will be a tie.

3. Hard AI - Implemented using MiniMax Algorithim in which most of the possible combinations of 'O's or 'X's are recursively called into several boards and are given scores of
10, -10, or 0 to find the best move. When all the combinations are rated with minmax the maximum of the scores is the best move. It is impossible to beat. 

   ![alt text](https://media.geeksforgeeks.org/wp-content/uploads/TIC_TAC.jpg)
