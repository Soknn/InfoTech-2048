#include <stdlib.h>   // определяет: srand
#include <stdint.h>	  // определяет: uint8_t, uint32_t
#include <stdbool.h>  // определяет: true, false
#include <time.h>	  // определяет: time
#include "controller.h"

uint8_t findTarget(uint8_t array[SIZE], uint8_t x, uint8_t stop) {
	if (x == 0) return x;

	for (uint8_t t = x - 1;; t -= 1) {
		if (array[t] != 0) return array[t] != array[x] ? t + 1 : t;
		else if (t == stop) return t;
	}

	return x;
}

bool slideArray(uint8_t array[SIZE], uint32_t* score) {
	bool success = false;
	uint8_t x, t, stop = 0;

	for (x = 0; x < SIZE; x += 1) {
		if (array[x] == 0) continue;

		t = findTarget(array, x, stop);

		if (t == x) continue;

		if (array[t] == 0) {
			array[t] = array[x];
		}
		else if (array[t] == array[x]) {
			array[t] += 1;
			*score += (uint32_t)1 << array[t];
			stop = t + 1;
		}

		array[x] = 0;
		success = true;
	}

	return success;
}

void rotateBoard(uint8_t board[SIZE][SIZE]) {
	for (uint8_t i = 0; i < SIZE / 2; i += 1) {
		for (uint8_t j = i; j < SIZE - i - 1; j += 1) {
			uint8_t tmp = board[i][j];
			board[i][j] = board[j][SIZE - i - 1];
			board[j][SIZE - i - 1] = board[SIZE - i - 1][SIZE - j - 1];
			board[SIZE - i - 1][SIZE - j - 1] = board[SIZE - j - 1][i];
			board[SIZE - j - 1][i] = tmp;
		}
	}
}

bool slide(uint8_t board[SIZE][SIZE], uint32_t* score, const int amountOfPreRotations, const int amountOfAfterRotations) {
	for (uint8_t _ = 0; _ < amountOfPreRotations; _ += 1) rotateBoard(board);

	bool movedAny = false;

	for (uint8_t x = 0; x < SIZE; x += 1) movedAny |= slideArray(board[x], score);

	for (uint8_t _ = 0; _ < amountOfAfterRotations; _ += 1) rotateBoard(board);

	return movedAny;
}

bool findPairDown(uint8_t board[SIZE][SIZE]) {
	for (uint8_t x = 0; x < SIZE; x += 1) {
		for (uint8_t y = 0; y < SIZE - 1; y += 1) {
			if (board[x][y] == board[x][y + 1]) return true;
		}
	}

	return false;
}

uint8_t countEmpty(uint8_t board[SIZE][SIZE]) {
	uint8_t count = 0;

	for (uint8_t x = 0; x < SIZE; x++) {
		for (uint8_t y = 0; y < SIZE; y++) {
			if (board[x][y] == 0) count += 1;
		}
	}

	return count;
}

bool isGameOver(uint8_t board[SIZE][SIZE]) {
	if (countEmpty(board) > 0 || findPairDown(board)) return false;

	rotateBoard(board);

	bool isGameOver = !findPairDown(board);

	for (uint8_t _ = 0; _ < 3; _ += 1) rotateBoard(board);

	return isGameOver;
}

void createRandomBlock(uint8_t board[SIZE][SIZE]) {
	static bool isGeneratorInitialized = false;
	uint8_t x, y, r, len = 0;
	uint8_t list[SIZE * SIZE][2];

	if (!isGeneratorInitialized) {
		srand(time(NULL));
		isGeneratorInitialized = true;
	}

	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++) {
			if (board[x][y] == 0) {
				list[len][0] = x;
				list[len][1] = y;
				len++;
			}
		}
	}

	if (len > 0) {
		r = rand() % len;
		x = list[r][0];
		y = list[r][1];
		board[x][y] = (rand() / (RAND_MAX + 1.0) < 0.7) ? 2 : 4;
	}
}

bool moveTo(uint8_t board, uint32_t* score, enum Direction direction) {
	switch (direction) {
	case DOWN: return slide(board, score, 2, 2);
	case UP: return slide(board, score, 0, 0);
	case LEFT: return slide(board, score, 1, 3);
	case RIGHT: return slide(board, score, 3, 1);
	}
}