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

		maze_game.PrintMaze();

		printf("W : ��, S : �Ʒ�, A : ����, D : ������, Q : ����\n");

		char input = _getch();

		if (input == 'q' || input == 'Q') { break; }

		maze_game.MovePlayer(input);

		if (maze_game.IsAlived())
		{
			printf("�����߽��̴�\n");
			break;
		}
	}
}