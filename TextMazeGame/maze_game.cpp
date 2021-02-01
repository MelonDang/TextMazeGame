#pragma warning (disable : 4996)

#include "maze_game.h"

/*
* 0 : 벽
* 1 : 길
* 2 : 시작점
* 3 : 도착점
*/

void MazeGame::InitMaze()
{
	player_pos_.x = start_pos_.x;
	player_pos_.y = start_pos_.y;

	std::strcpy(maze_[0],  "21100000000000000000");
	std::strcpy(maze_[1],  "00111111111100000000");
	std::strcpy(maze_[2],  "00100010000111111100");
	std::strcpy(maze_[3],  "01100010000000000100");
	std::strcpy(maze_[4],  "01000011110001111100");
	std::strcpy(maze_[5],  "01000000001111000000");
	std::strcpy(maze_[6],  "00000000001000000000");
	std::strcpy(maze_[7],  "00100000001111111000");
	std::strcpy(maze_[8],  "00001110000000001000");
	std::strcpy(maze_[9],  "01111011111111111000");
	std::strcpy(maze_[10], "01000000000000000000");
	std::strcpy(maze_[11], "01111100111111100000");
	std::strcpy(maze_[12], "00000111100000111110");
	std::strcpy(maze_[13], "01111100000000000010");
	std::strcpy(maze_[14], "01000000001111111110");
	std::strcpy(maze_[15], "01111111001000000000");
	std::strcpy(maze_[16], "00000010011000000000");
	std::strcpy(maze_[17], "01111110011111000000");
	std::strcpy(maze_[18], "01000000000001100000");
	std::strcpy(maze_[19], "11000000000000111113");
}

void MazeGame::moveUp()
{
	if (maze_[player_pos_.y - 1][player_pos_.x] == '0' || player_pos_.y - 1 < 0) { return; }

	--player_pos_.y;
}

void MazeGame::moveDown()
{
	if (maze_[player_pos_.y + 1][player_pos_.x] == '0' || player_pos_.y + 1 > 19) { return; }

	++player_pos_.y;
}

void MazeGame::moveLeft()
{
	if (maze_[player_pos_.y][player_pos_.x - 1] == '0' || player_pos_.x - 1 < 0) { return; }

	--player_pos_.x;
}

void MazeGame::moveRight()
{
	if (maze_[player_pos_.y][player_pos_.x + 1] == '0' || player_pos_.x + 1 > 19) { return; }

	++player_pos_.x;
}

bool MazeGame::IsAlived()
{
	return player_pos_.x == end_pos_.x && player_pos_.y == end_pos_.y;
}

void MazeGame::MovePlayer(const char input)
{
	switch (input)
	{
	case 'w':
	case 'W':
		moveUp();
		break;
	case 's':
	case 'S':
		moveDown();
		break;
	case 'a':
	case 'A':
		moveLeft();
		break;
	case 'd':
	case 'D':
		moveRight();
		break;
	}
}

void MazeGame::PrintMaze()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (player_pos_.x == j && player_pos_.y == i)
			{
				printf("☆");
			}
			else if (maze_[i][j] == '0')
			{
				printf("■");
			}
			else if (maze_[i][j] == '1')
			{
				printf("  ");
			}
			else if (maze_[i][j] == '2')
			{
				printf("★");
			}
			else if (maze_[i][j] == '3')
			{
				printf("◎");
			}

		}
		printf("\n");
	}
}