#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

#define MAXLEN 1024
#define MAXSTR 10

void InitializeBoard (int m, int n, char board[][n]){
    int c = 1;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            board[i][j] = c + '0';
            c++;
        }
    }
}
void PrintBoard(int m, int n, char board[][n]){
    for(int i = 0; i < m; i ++){
        printf("\t   |\t    |\n");
        for(int j = 0; j < n; j ++) {
            j == 1 ? printf("|   %c    |", board[i][j]) : printf("   %c   ", board[i][j]);
        }
        if(i < 2) {
            printf("\n_______|________|________\n");
        }
    }
    printf("\n\t   |\t    |\n");
}

int main(void){
    int m = 3, n = 3;
    char board[3][3];
    InitializeBoard(m,n,board);
    PrintBoard(m,n,board);

}
