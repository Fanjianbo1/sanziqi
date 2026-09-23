#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initchess(char arr[ROW][COL], int row, int col);
void printchess(char arr[ROW][COL], int row, int col);
void player(char arr[ROW][COL], int row, int col);
void computer(char arr[ROW][COL], int row, int col);
char iswin(char arr[ROW][COL], int row,int col);
int isfull(char arr[ROW][COL], int row, int col);