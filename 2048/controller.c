#include <stdlib.h>   // определяет: srand
#include <stdbool.h>  // определяет: true, false
#include <time.h>	  // определяет: time
#include "controller.h"

static int _field[SIZE][SIZE];

static int _score;

int** getField() {
	return _field;
}

int getScore() { return _score; }

int findTarget(int column[SIZE], int x, int stop) {
	if (x == 0) return x;

	for (int t = x - 1; ; t -= 1) {
		if (column[t] != 0) return column[t] != column[x] ? t + 1 : t;
		else if (t == stop) return t;
	}

	return x;
}

bool slideColumn(int column[SIZE]) {
	bool success = false;
	int x, t, stop = 0;

	for (x = 0; x < SIZE; x += 1) {
		if (column[x] == 0) continue;

		t = findTarget(column, x, stop);

		if (t == x) continue;

		if (column[t] == 0) {
			column[t] = column[x];
		}
		else if (column[t] == column[x]) {
			column[t] += 1;
			_score += (int)1 << column[t];
			stop = t + 1;
		}

		column[x] = 0;
		success = true;
	}

	return success;
}

void rotateField() {
	for (int i = 0; i < SIZE / 2; i += 1) {
		for (int j = i; j < SIZE - i - 1; j += 1) {
			int tmp = _field[i][j];
			_field[i][j] = _field[j][SIZE - i - 1];
			_field[j][SIZE - i - 1] = _field[SIZE - i - 1][SIZE - j - 1];
			_field[SIZE - i - 1][SIZE - j - 1] = _field[SIZE - j - 1][i];
			_field[SIZE - j - 1][i] = tmp;
		}
	}
}

bool slide(const int amountOfPreRotations, const int amountOfAfterRotations) {
	for (auto _ = 0; _ < amountOfPreRotations; _ += 1) rotateField();

	bool movedAny = false;

	for (int columnIndex = 0; columnIndex < SIZE; columnIndex += 1)
		movedAny |= slideColumn(_field[columnIndex]);

	for (auto _ = 0; _ < amountOfAfterRotations; _ += 1) rotateField();

	return movedAny;
}

bool findPairDown() {
	for (auto x = 0; x < SIZE; x += 1) {
		for (auto y = 0; y < SIZE - 1; y += 1) {
			if (_field[x][y] == _field[x][y + 1]) return true;
		}
	}

	return false;
}

int countEmpty() {
	int count = 0;

	for (auto x = 0; x < SIZE; x++) {
		for (auto y = 0; y < SIZE; y++) {
			if (_field[x][y] == 0) count += 1;
		}
	}

	return count;
}

bool isGameOver() {
	if (countEmpty() > 0 || findPairDown()) return false;

	rotateField();

	bool isGameOver = !findPairDown();

	for (auto _ = 0; _ < 3; _ += 1) rotateField();

	return isGameOver;
}

void createRandomBlock() {
	static bool isGeneratorInitialized = false;
	int x, y, r, len = 0;
	int list[SIZE * SIZE][2];

	if (!isGeneratorInitialized) {
		srand(time(NULL));
		isGeneratorInitialized = true;
	}

	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++) {
			if (_field[x][y] == 0) {
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
		_field[x][y] = (rand() / (RAND_MAX + 1.0) < 0.7) ? 1 : 2;
	}
}

void slideTo(enum Direction direction) {
	bool wasSlid = false;

	switch (direction) {
		case DOWN: wasSlid = slide(2, 2); break;
		case UP: wasSlid = slide(0, 0); break;
		case LEFT: wasSlid = slide(1, 3); break;
		case RIGHT: wasSlid = slide(3, 1); break;
	}

	if (wasSlid) createRandomBlock();
}

void init() {
	_score = 0;

	for (auto x = 0; x < SIZE; x += 1)
		for (auto y = 0; y < SIZE; y += 1)
			_field[x][y] = 0;

	createRandomBlock(_field);
	createRandomBlock(_field);
}