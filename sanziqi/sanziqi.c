#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void game()
{
	char ret = '0';
	printf("游戏开始\n");
	char arr[ROW][COL] = { 0 };
	initchess(arr, ROW, COL);
	printchess(arr, ROW, COL);
	while (1)
	{
		//玩家下棋
		player(arr, ROW, COL);
		printchess(arr, ROW, COL);
		ret = iswin(arr,ROW,COL);
		if (ret !='A')
		{
			break;
		}
		//电脑下棋
		computer(arr, ROW, COL);
		printchess(arr, ROW, COL);
		ret = iswin(arr,ROW,COL);
		if (ret != 'A')
		{
			break;
		}
	}
	if (ret == 'X')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");

}
void menu()
{
	printf("***********************************\n");
	printf("************三子棋游戏*************\n");
	printf("************1.play*****************\n");
	printf("************0.exit*****************\n");

}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do

	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}