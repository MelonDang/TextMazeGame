#pragma once

#include <cstdio>
#include <string>

constexpr static short MAX_BOMB_COUNT = 5;

class MazeGame
{
	struct Point
	{
		short x;
		short y;
	};

	char maze_[21][21] = { 0, };

	Point player_pos_ = { 0, };
	Point start_pos_ = { 0, };
	Point end_pos_ = { 19, 19 };

	short plant_bombs_count_ = 0;
	Point bombs_pos_[5];

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void movePlayer(const char input);

	void createBomb();
	void fireBomb();
public:
	short getPlantBombsCount() const { return plant_bombs_count_; }

	void InitMaze();

	void InputKey(const char input);
	bool IsArrived();

	void UpdateMaze();
};
