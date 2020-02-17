/*
 * Usman Farooqi
 * Comp 1410 - Tic-Tac-Toe-Assignment
 * 105219637
 * Winter 2020
 */
#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
int _input(); // this is a function used for input
char str_input();
// Question 1 - Initialize the board
void InitializeBoard (int m, int n, char board[][n]){ // Makes a empty board upon start up
    int c = 1;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            board[i][j] = c + '0';
            c++;
        }
    }
}
// Question 2 - print a tic-tac-toe board
void PrintBoard(int m, int n, char board[][n]){ // prints the board in the desired format
    for(int i = 0; i < m; i ++){
        printf("       |       |       \n");
        for(int j = 0; j < n; j ++) {
            j == 1 ? printf("|   %c   |", board[i][j]) : printf("   %c   ", board[i][j]);
        }
        if(i < 2) {
            printf("\n_______|_______|_______\n");
        }
    }
    printf("\n       |       |       \n\n");
}
// Question 3 - create a tic-tac-toe board
void createBoard(int m, int n, char board[][n]){ // creates a board given user values
    int num; // number for cell
    char type; // X or O
    while(1) {
        PrintBoard(m, n, board);
        puts("Enter the number of cell where you want to put X or O, enter -1 to exit:");
        num = _input(); // calls input function to take the input
        if(num > 0 && num < 10) {
            type = str_input(); // calls string input function to take X or O input
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == num + '0') { // if the board value is same as the user entered cell value
                        board[i][j] = type; // set it to X or O
                    }
                }
            }
        }
        if(num == -1){ // if the user enters -1 break
            break;
        }
    }
}
// Question 4 - Check if board is valid
int IsValidBoard(int m, int n, char board[][n]){ // checks if the current board is valid or not
    int x_count = 0, o_count = 0; // counters for x and o
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(board[i][j] == 'X'){ // search for an X and if its found
                x_count ++; // increase X counter
            }
            else if(board[i][j] == 'O'){ // search for O
                o_count ++; // if found increase O counter
            }
        }
    }
    if(abs(x_count - o_count) == 0 || abs(x_count - o_count) == 1){ // take the absolute value so no negative value is given
        return 1; // return 1 or true if the difference between x and o is 1 or 0
    }
    else{
        return 0; // else return 0
    }
}
void PrintArray(char arr [], int size){ // helper function used to print for question 5
    for(int i = 0; i < size; i ++){
        printf("%c ", arr[i]);
    }
}
//Question 5 - Checks for winning move
void ListWinningCells(int m, int n, char board[][n]){ // checks if there is a possible winning move
    int diagx, diago, k = 2, xcount, ocount, x_arrcount = -1, o_arrcount = -1;
    //   diagonal for x, diagonal for O, k for columns, x counter, o counter, x array position, o array position
    bool p1, p2; // this is to check which player was winner
    char x_win[3] = {""}, o_win[3] = {""},  xpos, diagpos = ' ';
    //  x winners array, o winners array, position, diagonal position
    if(IsValidBoard(m, n, board)){ // checks if the board is valid
        diago = 0, diagx = 0, p1 = false, p2 = false;
        for(int i = 0; i < m; i ++){
            xcount = 0, ocount = 0, xpos = ' ';
            (board[i][i] == 'X') ? diagx ++ : (board[i][i] == 'O') ? diago++ : (diagpos = board[i][i]); // runs diagonals
            for(int j = 0; j < n; j ++){
                (board[i][j] == 'X') ? xcount++ : (board[i][j] == 'O') ? ocount++ : (xpos = board[i][j]); // checks for columns
                    // if there is an x increase x counter --- else increase o counter --- else store the cell position
            }
            if(xcount == 2 && ocount == 0){
                x_win[++x_arrcount] = xpos; // if there is 2 X on the board and then number store it in winning array
                p1 = true; // set the player1 winning to true
            }
            if(xcount == 0 && ocount == 2){ // if there is 2 O on the board and number
                o_win[++o_arrcount] = xpos; // store the cell
                p2 = true;// set the player2 winning to true
            }
            (diagx == 2 && diago == 0) ? ((x_win[++x_arrcount] = diagpos), (p1 = true)) : (diagx == 0 && diago == 2) ? ((o_win[++o_arrcount] = diagpos), (p2 = true)) : '0';
        }
        diago = 0, diagx = 0;
        for(int i = 0; i < m; i ++){ // runs columns
            xcount = 0, ocount = 0, xpos = ' ';
            (board[i][k] == 'X') ? diagx ++ : (board[i][k] == 'O') ? diago++ : (diagpos = board[i][k]); // runs diagonals
            k--;
            for(int j = 0; j < n; j ++){
                (board[j][i] == 'X') ? xcount++ : (board[j][i] == 'O') ? ocount++ : (xpos = board[j][i]); // checks for columns
            }
            if(xcount == 2 && ocount == 0){
                x_win[++x_arrcount] = xpos;
                p1 = true;
            }
            if(xcount == 0 && ocount == 2){
                o_win[++o_arrcount] = xpos;
                p2 = true;
            }
            (diagx == 2 && diago == 0) ? ((x_win[++x_arrcount] = diagpos), (p1 = true)) : (diagx == 0 && diago == 2) ? ((o_win[++o_arrcount] = diagpos), (p2 = true)) : '0';
        }
        if(p1){ // if X can win next turn
            printf("Player X is winning at cell number(s): ");
            PrintArray(x_win, 3); // list winning cells
            printf("\n");
        }
        if(p2){ // if O can win next turn
            printf("Player O is winning at cell number(s): ");
            PrintArray(o_win, 3); // list winning cells
            printf("\n");
        }
        if(!p1 && !p2){ // if neither can win
            puts("No winning cells for X or O");
        }
        printf("\n");
    }
}
char check(int m, char arr[], int pos){ // recursive function which checks for 3 X's or 3 O's in a 1d array
    if(pos == 4){
        return 'D'; // print if nothing is found
    }
    if((arr[m] == arr[pos]) && (arr[pos] == arr[pos + 1])){ // if 3 X's are found or 3 O's are found
        return arr[m];
    }
    return check(m, arr, pos + 1); // recall function
}
char WhoIsTheWinner(int m, int n, char board[][n]){
    char winner = 'D', winner_row, winner_col, winner_diagL, winner_diagR;
    for(int i = 0; i < m; i++){
        char temp[3] = {board[0][i], board[1][i], board[2][i]}; // converts columns into 1d array
        winner_row = check(i, board[i], 1); // checks for winning row
        winner_col = check(i, temp,1); // checks for winning column

        char diag_left[3] = {board[0][0], board[1][1], board[1][2]}, diag_right[3] = {board[0][2], board[1][1], board[2][0]}; // creates 1d array for both diagonals
        winner_diagL = check(i, diag_left, 1); // checks for left diagonal
        winner_diagR = check(i, diag_right, 1); // checks for right
        if(winner_row == 'X' || winner_col == 'X' || winner_diagL == 'X' || winner_diagR == 'X'){ // if there is a winning for X
            winner = 'X'; // set final winner to X
            break;
        }
        if(winner_row == 'O' || winner_col == 'O' ||  winner_diagL == 'O' || winner_diagR == 'O'){ // if there is a winnign for O
            winner = 'O'; // set final winner to O
            break;
        }
    }
    return winner; // return the winner
}

int main(void){ // main function
    int m = 3, n = 3;
    char board[m][n], ans; // 3 x 3 board
    bool running = true; // running boolean
    InitializeBoard(m,n,board); //calls InitializeBoard - Question 1
    while(running){ // while the game is running
        printf("press 'p' to print the tic-tac-toe board\n"
               "press 'c' to create a tic-tac-toe board with some X and O cells\n"
               "press 't' to test if a tic-tac-toe board is valid or invalid board\n"
               "press 'w' to predict winning cell for player X or O\n"
               "press 'q' to display the winner\n"
               "press 'e' to exit\n");
        scanf(" %c", &ans); // takes input for choice
        switch (ans){
            case 'p': PrintBoard(m, n, board);
                break;
            case 'c': createBoard(m ,n, board);
                break;
            case 't' : IsValidBoard(m, n, board) == 0 ? puts("The board is invalid") : puts("The board is valid");
                break;
            case 'w' : ListWinningCells(m, n, board);
                break;
            case 'q' : printf("%c\n", WhoIsTheWinner(m, n, board));
                break;
            case 'e': running = false;
                break;
            default: puts("Invalid input!"); // if the user enters in anything other than the correct choices
        }
    }
}
int _input(){ // a function that takes user input for numbers
    int x;
    scanf("%d", &x);
    return x;
}
char str_input(){ // a function that takes user input for integer
    char x;
    while(1) {
        puts("Enter X or O");
        scanf(" %c", &x);
        if (x != 'X' && x != 'O') {
            continue;} else {
            break;}
    }
    return x;
}