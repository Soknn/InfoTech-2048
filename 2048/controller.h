#pragma once

#define SIZE 4

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	UNDEFINED,
	QUIT
};

bool isGameOver(uint8_t board[SIZE][SIZE]);

void createRandomBlock(uint8_t board[SIZE][SIZE]);

bool slideTo(uint8_t board[SIZE][SIZE], uint32_t* score, enum Direction direction);

void init(uint8_t board[SIZE][SIZE]);