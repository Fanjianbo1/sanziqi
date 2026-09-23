#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void initchess(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
//   |   |
//---|---|---
//   |   |   
//---|---|---
//   |   |   

void printchess(char arr[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
int isfull(char arr[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
void player(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走棋\n");
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("该位置已经有棋子了，请重新输入\n");
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
			printchess(arr, row, col);
		}
	}
}
void computer(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		printf("电脑下棋\n");
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}
char iswin(char arr[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];
		}
	}
	for (int i = 0;i < col;i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
		{
			return arr[0][i];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[1][1];
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] != ' ')
		return arr[1][1];
	if (isfull(arr, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'A';
}