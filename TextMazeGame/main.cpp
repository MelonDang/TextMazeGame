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

		printf("¼³Ä¡ÇÑ ÆøÅº °³¼ö : %d / 5\n", maze_game.getPlantBombsCount());
		printf("T : ÆøÅº ¼³Ä¡, U : ÆøÅº ÅÍÆ®¸®±â\n");
		printf("W : À§, S : ¾Æ·¡, A : ¿ÞÂÊ, D : ¿À¸¥ÂÊ, Q : Á¾·á\n");

		int8_t input = _getch();

		if (input == 'q' || input == 'Q') { break; }

		maze_game.InputKey(input);

		if (maze_game.IsArrived())
		{
			printf("µµÂøÇß½¿¹Ì´Ù\n");
			break;
		}
	}
}