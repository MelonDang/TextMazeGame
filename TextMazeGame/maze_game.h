#pragma once

#include <cstdio>
#include <string>

class MazeGame
{
	struct Point
	{
		int x;
		int y;
	};

	char maze_[21][21] = { 0, };

	Point player_pos_ = { 0, };
	Point start_pos_ = { 0, };
	Point end_pos_ = { 19, 19 };

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
public:
	void InitMaze();

	void MovePlayer(const char input);
	bool IsAlived();

	void PrintMaze();
};
