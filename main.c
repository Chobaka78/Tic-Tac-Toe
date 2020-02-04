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

int _input();
char str_input();
static bool valid = true; // static variable valid either true or false

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
        printf("\t   |\t   |\n");
        for(int j = 0; j < n; j ++) {
            j == 1 ? printf("|   %c   |", board[i][j]) : printf("   %c   ", board[i][j]);
        }
        if(i < 2) {
            printf("\n_______|_______|_______\n");
        }
    }
    printf("\n\t   |\t   |\n");
}
// Question 3 - create a tic-tac-toe board
void createBoard(int m, int n, char board[][n]){ // creates a board given user values
    int num;
    char type;
    while(1) {
        PrintBoard(m, n, board);
        puts("Enter the number of cell where you want to put x or 0, enter -1 to exit:");
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
            if(board[i][j] == 'x'){
                x_count ++;
            }
            else if(board[i][j] == 'o'){
                o_count ++;
            }
        }
    }
    if(x_count == 0 && o_count == 0){
        valid = true; // sets valid to true
        return 1;
    }
    else if(abs(x_count - o_count) == 0 || abs(x_count - o_count) == 1){
        valid = true; // sets valid to true
        return 1;
    }
    else{
        valid = false; // sets valid to false
        return 0;
    }
}
//Question 5 - Checks for winning move
void ListWinningCells(int m, int n, char board[][n]){ // checks if there is a possible winning move
//    if(valid){
//
//    }
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
        if (x != 'x' && x != 'o') {
            continue;} else {
            break;}
    }
    return x;
}
