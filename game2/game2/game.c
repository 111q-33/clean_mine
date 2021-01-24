#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char arr[ROWS][COLS], int x, int y,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			arr[i][j] = set ;
		}
	}

}
void Display(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}


}
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void player(char showboard[ROWS][COLS], char mineboard[ROWS][COLS], int row, int col)
{
	int count = row*col - EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count)
	{
		printf("请输入坐标。\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mineboard[x][y] == '1')
			{
				printf("你被炸死了。\n");
				break;
			}
			else
			{
				showboard[x][y] = isfor(mineboard, x, y)+'0';
				Display(showboard, ROW, COL);
				count--;
			}
		}
		else
		{
			printf("输入错误，请重试。\n");
		}
	}
	if (count == 0)
	{
		printf("通关\n");
		Display(mineboard, ROW, COL);
	}
}
int isfor(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] - '0' +
		mine[x - 1][y] - '0' +
		mine[x - 1][y + 1] - '0' +
		mine[x][y + 1] - '0' +
		mine[x + 1][y + 1] - '0' +
		mine[x + 1][y] - '0' +
		mine[x + 1][y - 1] - '0' +
		mine[x][y - 1] - '0';




}