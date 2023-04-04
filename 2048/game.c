#include <stdint.h>	  // ����������: uint8_t, uint32_t
#include <stdbool.h>  // ����������: true, false
#include <stdio.h> // ����������: getchar
#include "controller.h";
#include "view.h";

int main() {
	uint8_t board[SIZE][SIZE];
	uint32_t score = 0;

	init(board);

	while (true) {
		updateUserInterface(board, score);

		auto direction = convertToDirection(getchar());

		if (moveTo(board, &score, direction)) createRandomBlock(board);
	}
}