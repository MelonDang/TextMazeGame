#pragma once

#include <stdint.h>
#include <cstdio>
#include <list>
#include <string>

class MazeGame
{
	struct Point
	{
		uint16_t x;
		uint16_t y;
	};

	char maze_[21][21] = { 0, };

	Point player_pos_ = { 0, };
	Point start_pos_ = { 0, };
	Point end_pos_ = { 19, 19 };

	constexpr static uint16_t MAX_BOMB_COUNT = 5;

	uint16_t plant_bombs_count_ = 0;
	Point bombs_pos_[5];

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void movePlayer(const char input);

	void createBomb();
	void fireBomb();
public:
	uint16_t getPlantBombsCount() const { return plant_bombs_count_; }

	void InitMaze();

	void InputKey(const char input);
	bool IsArrived();

	void UpdateMaze();
};
