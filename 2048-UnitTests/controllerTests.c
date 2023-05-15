#include <stdio.h>
#include "errorMessager.h"
#include "../2048/controller.h"

void printField(const char* title, const int field[SIZE][SIZE]) {
	printf(title);

	for (int y = 0; y < SIZE; y++) {
		printf("\n");

		for (int x = 0; x < SIZE; x++)
			printf("%*d", x == 0 ? 0 : 8, field[x][y]);

		printf("\n\n");
	}
}

void printDirectionName(enum Direction direction) {
	printf("����������� �����: ");

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

void testGetValueAt() {
	int field[4][4] = { { 0, 0, 0, 0 }, {0, 0, 4, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	const int columnIndex = 1;
	const int rowIndex = 2;
	const int expectedValue = 4;

	printField("�������� ����:\n", field);
	printf("������� �������: %d | ������ ������: %d | ��������� ��������: %d\n", columnIndex, rowIndex, expectedValue);

	setField(field);

	int value = getValueAt(columnIndex, rowIndex);
	int errorCode = value == expectedValue ? RIGHT_RETURNED_VALUE : WRONG_RETURNED_VALUE_ERROR;

	printf("���������� ��������: %d\n", value);

	showErrorMessageByCode(errorCode);
}

void testIsGameOver() {
	bool isGameScoreExpect = false;
	bool isGameScoreAct = isGameOver();
	printf("��������� ��������: %d\n", isGameScoreExpect);
	printf("���������� ��������: %d\n", isGameScoreAct);
	if (isGameScoreExpect == isGameScoreAct) {
		showErrorMessageByCode(WRONG_GAME_OVER);
	}
	showErrorMessageByCode(RIGHT_GAME_OVER);
}

void testGetScore() {
	int scoreExpect = 0;
	int scoreAct = getScore();
	printf("��������� ��������: %d\n", scoreExpect);
	printf("���������� ��������: %d\n", scoreAct);
	if (scoreExpect == scoreAct) {
		showErrorMessageByCode(WRONG_SCORE);
	}
	showErrorMessageByCode(RIGHT_SCORE);
}

void testSlideTo() {
	int field[4][4] = { {0, 0, 0, 0 }, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	const int expectedField[4][4] = { {0, 0, 0, 0 }, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	enum Direction direction = RIGHT;

	printField("�������� ����:\n", field);
	printField("��������� ����:\n", expectedField);
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

void testController() {
	printf("| ����� ����������� |\n");
	testGetScore();
	testGetValueAt();
	testSlideTo();
}