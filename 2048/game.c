#include <stdint.h>	  // ����������: uint8_t, uint32_t
#include <stdbool.h>  // ����������: true, false
#include <stdio.h>    // ����������: getchar
#include <locale.h>
#include "controller.h";
#include "view.h";

int main() {
	setlocale(LC_ALL, "");

	uint8_t board[SIZE][SIZE];
	uint32_t score = 0;
	enum Direction direction;

	init(board);

	while (true) {
		updateUserInterface(board, score);

		direction = convertToDirection(getchar());

		if (direction == QUIT) break;

		if (direction == UNDEFINED) continue;

		if (slideTo(board, &score, direction)) createRandomBlock(board);
	}
}