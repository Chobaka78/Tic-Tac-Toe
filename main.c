/*
 * Usman Farooqi
 * Comp 1410 - Tic-Tac-Toe-Assignment
 * 105219637
 * Winter 2020
 */
#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"
#define Player1 'X'
#define Player2 'O'

int _input();
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
    int num;
    char type;
    while(1) {
        PrintBoard(m, n, board);
        puts("Enter the number of cell where you want to put X or O, enter -1 to exit:");
        num = _input();
        if(num > 0 && num < 10) {
            type = str_input();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == num + '0') {
                        board[i][j] = type;
                    }
                }
            }
        }
        if((num < 0 || num > 0) && num != -1){
            continue;
        }
        if(num == -1){
            break;
        }
    }
}
// Question 4 - Check if board is valid
int IsValidBoard(int m, int n, char board[][n]){ // checks if the current board is valid or not
    int x_count = 0, o_count = 0;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(board[i][j] == Player1){
                x_count ++;
            }
            else if(board[i][j] == Player2){
                o_count ++;
            }
        }
    }
    if(abs(x_count - o_count) == 0 || abs(x_count - o_count) == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int *Array(int arr[], int size, int arr1[]){
    for(int i = 0; i < size; i ++){
        if(arr[i] != 0 && arr1[i] != arr[i]){
            arr1[i] = arr[i];
        }
    }
    return arr1;
}

//Question 5 - Checks for winning move
void ListWinningCells(int m, int n, char board[][n]){ // checks if there is a possible winning move
    int num[] = {0};
    int xcount = 0, ocount = 0, xpos[9] = {0}, ypos[9] = {0}, *val;
    if(IsValidBoard(m, n, board)){ // checks if the board is valid
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                (board[i][j] == 'X') ? xcount++ : board[i][j] == 'O' ? ocount ++ : (xpos[(i*3) + j] = board[i][j] - '0');
            }

        }

        if(xcount == 2 && ocount == 0){
            val = Array(xpos, 9, num);
            printf("X: ");
            for(int i = 0; i < sizeof(val); i ++){
                printf("%d ", val[i]);
            }
            printf("\n");
        }
    }

}
int main(void){ // main function
    int m = 3, n = 3;
    char board[m][n], ans; // 3 x 3 board
    bool running = true; // running boolean
    InitializeBoard(m,n,board); //calls InitializeBoard - Question 1
    while(running){
        printf("press 'p' to print the tic-tac-toe board\n"
               "press 'c' to create a tic-tac-toe board with some X and O cells\n"
               "press 't' to test if a tic-tac-toe board is valid or invalid board\n"
               "press 'w' to predict winning cell for player X or O\n"
               "press 'e' to exit\n");
        scanf(" %c", &ans);
        switch (ans){
            case 'p': PrintBoard(m, n, board);
                break;
            case 'c': createBoard(m ,n, board);
                break;
            case 't' : IsValidBoard(m, n, board) == 0 ? puts("The board is invalid") : puts("The board is valid");
                break;
            case 'w' : ListWinningCells(m, n, board);
                break;
            case 'e': running = false;
                break;
            default: puts("Invalid input!");
        }
    }
}
int _input(){
    int x;
    scanf("%d", &x);
    return x;
}
char str_input(){
    char x;
    while(1) {
        puts("Enter x or o");
        scanf(" %c", &x);
        if (x != 'X' && x != 'O') {
            continue;} else {
            break;}
    }
    return x;
}
