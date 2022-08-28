#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char tmp)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = tmp;
		}
	}
}



void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = difficulty;
	while (count)
	{
		int tmp_1 = (rand() % row) + 1;
		int tmp_2 = (rand() % col) + 1;
		if (board[tmp_1][tmp_2] == '0')
		{
			board[tmp_1][tmp_2] = '1';
			count--;
		}
	}
}



void SearchMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		if (IsWin(show, row, col))
		{
			printf("winner winner chicken dinner!\n");
			break;
		}
		printf("请输入要排查的坐标：\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
		{
			if (mine[x][y] == '1')
			{
				printf("踩雷了！游戏结束\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = 0;
				count = GetMine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
			}
		}
		else 
		{
			printf("坐标不合法，请重新输入坐标\n");
		}
	}
}


int GetMine(char mine[ROWS][COLS], int row, int col)
{
	return mine[row - 1][col - 1] + mine[row - 1][col] + mine[row - 1][col + 1] +
		mine[row][col - 1] + mine[row][col + 1] +
		mine[row + 1][col - 1] + mine[row + 1][col] + mine[row + 1][col + 1] - 8 * '0';
}


int IsWin(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] != '*')
				flag++;
		}
	}
	if(flag == ROW * COL - difficulty)
		return 1;
	else
		return 0;
}