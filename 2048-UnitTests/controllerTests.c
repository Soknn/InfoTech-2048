#include <cstdio>
#include "errorMessager.h"
#include "../2048/controller.h"

void testController() {
	testGetValueAt();
	testSlideTo();
}

void testGetValueAt() {
	const int field[4][4] = { {0, 0, 0, 0 }, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	const int columnIndex = 0;
	const int rowIndex = 0;
	const int expectedValue = 0;

	printField("Исходное поле:\n", field);
	printf("Индекса столбца: %d | Индекс строки: %d | Ожидаемое значение: %d\n", columnIndex, rowIndex, expectedValue);

	setField(field);

	int value = getValueAt(columnIndex, rowIndex);
	int errorCode = value == expectedValue ? RIGHT_RETURNED_VALUE : WRONG_RETURNED_VALUE_ERROR;

	printf("Полученное значение: %d\n", value);

	showErrorMessageByCode(errorCode);
}

void testSlideTo() {
	const int field[4][4] = { {0, 0, 0, 0 }, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	const int expectedField[4][4] = { {0, 0, 0, 0 }, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	enum Direction direction = RIGHT;

	printField("Исходное поле:\n", field);
	printField("Ожидаемое поле:\n", expectedField);
	printDirectionName(direction);

	setField(field);

	slideTo(direction);
	
	for (auto column = 0; column < SIZE; column += 1) {
		for (auto row = 0; row < SIZE; row += 1) {
			if (field[column][row] != expectedField[column][row]) {
				showErrorMessageByCode(WRONG_SLIDED_FIELD_ERROR);
				return;
			}
		}
	}

	showErrorMessageByCode(RIGHT_SLIDED_FIELD);
}

void printField(const char* title, const int field[SIZE][SIZE]) {
	printf(title);

	for (auto column = 0; column < SIZE; column += 1) {
		for (auto row = 0; row < SIZE; row += 1) 
			printf("%*d", field[column][row] == 0 ? 0 : 8, field[column][row]);
		
		printf("\n");
	}
}

void printDirectionName(enum Direction direction) {
	printf("Направление смаха: ");
	
	switch (direction)
	{
		case LEFT:
			printf("LEFT\n");
			break;
		case RIGHT:
			printf("RIGHT\n");
			break;
		case UP:
			printf("UP\n");
			break;
		case DOWN:
			printf("DOWN\n");
			break;
		case UNDEFINED:
			printf("UNDEFINED\n");
			break;
		case QUIT:
			printf("QUIT\n");
			break;
	}
}