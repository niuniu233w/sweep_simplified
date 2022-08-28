#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("**********1.play**************\n");
	printf("**********0.exit**************\n");
	printf("******************************\n");
}


void game()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//��ӡ����
	//DisplayBoard(show, ROW, COL);
	
	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//�Ų���
	SearchMine(mine,show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("��ѡ��\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}