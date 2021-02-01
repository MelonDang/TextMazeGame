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

		printf("W : 위, S : 아래, A : 왼쪽, D : 오른쪽, Q : 종료\n");

		char input = _getch();

		if (input == 'q' || input == 'Q') { break; }

		maze_game.MovePlayer(input);

		if (maze_game.IsAlived())
		{
			printf("도착했슴미다\n");
			break;
		}
	}
}