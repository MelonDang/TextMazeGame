#pragma warning (disable : 4996)

#include "maze_game.h"

/*
* 0 : 벽
* 1 : 길
* 2 : 시작점
* 3 : 도착점
* 4 : 폭탄
* 5 : 폭탄 이펙트
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
	char up = maze_[player_pos_.y - 1][player_pos_.x];

	if (up == '0' || up == '4' || player_pos_.y - 1 < 0) { return; }

	--player_pos_.y;
}

void MazeGame::moveDown()
{
	char down = maze_[player_pos_.y + 1][player_pos_.x];

	if (down == '0' || down == '4' || player_pos_.y + 1 > 19) { return; }

	++player_pos_.y;
}

void MazeGame::moveLeft()
{
	char left = maze_[player_pos_.y][player_pos_.x - 1];

	if (left == '0' || left == '4' || player_pos_.x - 1 < 0) { return; }

	--player_pos_.x;
}

void MazeGame::moveRight()
{
	char right = maze_[player_pos_.y][player_pos_.x + 1];

	if (right == '0' || right == '4' || player_pos_.x + 1 > 19) { return; }

	++player_pos_.x;
}

void MazeGame::movePlayer(const char input)
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

void MazeGame::createBomb()
{
	if (plant_bombs_count_ >= MAX_BOMB_COUNT) { return; }

	for (int i = 0; i < plant_bombs_count_; ++i)
	{
		if (bombs_pos_[i].x == player_pos_.x && bombs_pos_[i].y == player_pos_.y) { return; }
	}

	if (player_pos_.x == start_pos_.x && player_pos_.y == start_pos_.y)
	{
		return;
	}
	else if (player_pos_.x == end_pos_.x && player_pos_.y == end_pos_.y)
	{
		return;
	}

	maze_[player_pos_.y][player_pos_.x] = '4';

	bombs_pos_[plant_bombs_count_] = player_pos_;

	plant_bombs_count_ += 1;
}

void MazeGame::fireBomb()
{
	for (int i = 0; i < plant_bombs_count_; ++i)
	{
		maze_[bombs_pos_[i].y][bombs_pos_[i].x] = '1';

		if (bombs_pos_[i].x == player_pos_.x && bombs_pos_[i].y == player_pos_.y)
		{
			player_pos_ = { 0, };
			continue;
		}

		if (bombs_pos_[i].y - 1 >= 0 && maze_[bombs_pos_[i].y - 1][bombs_pos_[i].x] == '0') //위쪽을 터트릴 경우
		{
			maze_[bombs_pos_[i].y - 1][bombs_pos_[i].x] = '1';
		}
		else if (bombs_pos_[i].y + 1 <= 19 && maze_[bombs_pos_[i].y + 1][bombs_pos_[i].x] == '0') //아래쪽을 터트릴 경우
		{
			maze_[bombs_pos_[i].y + 1][bombs_pos_[i].x] = '1';
		}
		else if (bombs_pos_[i].x - 1 >= 0 && maze_[bombs_pos_[i].y][bombs_pos_[i].x - 1] == '0') //왼쪽을 터트릴 경우
		{
			maze_[bombs_pos_[i].y][bombs_pos_[i].x - 1] = '1';
		}
		else if (bombs_pos_[i].x + 1 <= 19 && maze_[bombs_pos_[i].y][bombs_pos_[i].x + 1] == '0') //오른쪽을 터트릴 경우
		{
			maze_[bombs_pos_[i].y][bombs_pos_[i].x + 1] = '1';
		}
	}

	plant_bombs_count_ = 0;
}

bool MazeGame::IsArrived()
{
	return player_pos_.x == end_pos_.x && player_pos_.y == end_pos_.y;
}

void MazeGame::InputKey(const char input)
{
	if (input == 't' || input == 'T')
	{
		createBomb();
	}
	else if (input == 'u' || input == 'U')
	{
		fireBomb();
	}
	else
	{
		movePlayer(input);
	}
}

void MazeGame::UpdateMaze()
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
			else if (maze_[i][j] == '4')
			{
				printf("♨");
			}
		}
		printf("\n");
	}
}