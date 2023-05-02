#include <stdint.h>	  // определяет: uint8_t, uint32_t
#include <stdbool.h>  // определяет: true, false
#include <stdio.h>    // определяет: getchar
#include <locale.h>
#include "controller.h"
#include "view.h"
#include "errorProcessor.h"

int main() {
	setlocale(LC_ALL, "");

	enum Direction direction;

	init();

	while (true) {
		updateUserInterface();

		direction = convertToDirection((char)getchar());

		if (direction == UNDEFINED) {
			processError(WRONG_INPUT_ERROR_CODE);
			continue;
		}

		if (direction == QUIT || isGameOver()) break;

		slideTo(direction);
	}
}