#pragma warning (disable : 4996)

#include <conio.h>

#include <cstdio>
#include <string>

/*
* 0 : 벽
* 1 : 길
* 2 : 시작점
* 3 : 도착점
*/

void SetMaze(char Maze[21][21])
{
	std::strcpy(Maze[0],  "21100000000000000000");
	std::strcpy(Maze[1],  "00111111111100000000");
	std::strcpy(Maze[2],  "00100010000111111100");
	std::strcpy(Maze[3],  "01100010000000000100");
	std::strcpy(Maze[4],  "01000011110001111100");
	std::strcpy(Maze[5],  "01000000001111000000");
	std::strcpy(Maze[6],  "00000000001000000000");
	std::strcpy(Maze[7],  "00100000001111111000");
	std::strcpy(Maze[8],  "00001110000000001000");
	std::strcpy(Maze[9],  "01111011111111111000");
	std::strcpy(Maze[10], "01000000000000000000");
	std::strcpy(Maze[11], "01111100111111100000");
	std::strcpy(Maze[12], "00000111100000111110");
	std::strcpy(Maze[13], "01111100000000000010");
	std::strcpy(Maze[14], "01000000001111111110");
	std::strcpy(Maze[15], "01111111001000000000");
	std::strcpy(Maze[16], "00000010010000000000");
	std::strcpy(Maze[17], "01111110011111000000");
	std::strcpy(Maze[18], "01000000000001100000");
	std::strcpy(Maze[19], "11000000000000111113");
}

void PrintMaze(char Maze[21][21])
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (Maze[i][j] == '0')
			{
				printf("■");
			}
			else if (Maze[i][j] == '1')
			{
				printf("  ");
			}
			else if (Maze[i][j] == '2')
			{
				printf("★");
			}
			else if (Maze[i][j] == '3')
			{
				printf("◎");
			}

		}
		printf("\n");
	}
}

int main()
{
	char strMaze[21][21];

	SetMaze(strMaze);

	while (true)
	{
		system("cls");

		PrintMaze(strMaze);

		printf("W : 위, S : 아래, A : 왼쪽, D : 오른쪽, Q : 종료");

		char input = _getch();

		if (input == 'q' || input == 'Q') { break; }
	}
}