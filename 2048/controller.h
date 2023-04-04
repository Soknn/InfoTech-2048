#pragma once

#define SIZE 4

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	UNDEFINED
};

bool isGameOver(uint8_t board[SIZE][SIZE]);

bool moveTo(uint8_t board, uint32_t* score, enum Direction direction);