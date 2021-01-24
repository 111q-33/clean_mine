#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 80
void Initboard(char arr[ROWS][COLS], int x, int y,char set);
void Display(char arr[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col);
void player(char showboard[ROWS][COLS], char mineboard[ROWS][COLS], int row, int col);
int isfor(char mine[ROWS][COLS],int x,int y);