#pragma warning (disable : 4996)

#include "maze_game.h"

#include <conio.h>

int main()
{
	MazeGame maze_game;

	maze_game.InitMaze();

	while (true)
	{
		system("cls");

		maze_game.UpdateMaze();

		printf("��ġ�� ��ź ���� : %d / 5\n", maze_game.getPlantBombsCount());
		printf("T : ��ź ��ġ, U : ��ź ��Ʈ����\n");
		printf("W : ��, S : �Ʒ�, A : ����, D : ������, Q : ����\n");

		int8_t input = _getch();

		if (input == 'q' || input == 'Q') { break; }

		maze_game.InputKey(input);

		if (maze_game.IsArrived())
		{
			printf("�����߽��̴�\n");
			break;
		}
	}
}