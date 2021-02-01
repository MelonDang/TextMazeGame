#pragma warning (disable : 4996)

#include "maze_game.h"

#include <windows.h>
#include <conio.h>

int main()
{
	MazeGame maze_game;

	maze_game.InitMaze();

	while (true)
	{
		system("cls");

		maze_game.UpdateMaze();

		printf("��ġ�� ��ź ���� : %d / %d\n", maze_game.getPlantBombsCount(), MAX_BOMB_COUNT);
		printf("T : ��ź ��ġ, U : ��ź ��Ʈ����\n");
		printf("W : ��, S : �Ʒ�, A : ����, D : ������, Q : ����\n");

		if (maze_game.IsArrived())
		{
			MessageBox(0, L"Ŭ����!", L"Maze Game", MB_OK);
			break;
		}

		char input = _getch();

		if (input == 'q' || input == 'Q') { break; }

		maze_game.InputKey(input);
	}
}