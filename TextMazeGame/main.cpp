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

		printf("¼³Ä¡ÇÑ ÆøÅº °³¼ö : %d / %d\n", maze_game.getPlantBombsCount(), MAX_BOMB_COUNT);
		printf("T : ÆøÅº ¼³Ä¡, U : ÆøÅº ÅÍÆ®¸®±â\n");
		printf("W : À§, S : ¾Æ·¡, A : ¿ÞÂÊ, D : ¿À¸¥ÂÊ, Q : Á¾·á\n");

		if (maze_game.IsArrived())
		{
			MessageBox(0, L"Å¬¸®¾î!", L"Maze Game", MB_OK);
			break;
		}

		char input = _getch();

		if (input == 'q' || input == 'Q') { break; }

		maze_game.InputKey(input);
	}
}