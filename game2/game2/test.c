#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("################\n");
	printf("#####1.play#####\n");
	printf("#####0.exit#####\n");
	printf("################\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS, '*');
	Setmine(mine,ROW,COL);
	Display(mine, ROW, COL);
	Display(show, ROW, COL);
	player(show, mine, ROW, COL);



}
int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("��ʼ��Ϸ��\n");
			game();
			break;
		case 0:
			printf("������Ϸ��\n");
			break;
		default:
			printf("������������䡣\n");
		}

	} while (n);

	return 0;
}