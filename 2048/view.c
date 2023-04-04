#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <signal.h>
#include "controller.h"
#include "view.h"

uint8_t getDigitCount(uint32_t number)
{
	uint8_t count = 0;
	do
	{
		number /= 10;
		count += 1;
	} while (number);
	return count;
}

void clearConsole() { system("cls"); }

void showGameField(uint8_t board[SIZE][SIZE])
{
	for (uint8_t y = 0; y < SIZE; y++) {
		for (uint8_t x = 0; x < SIZE; x++) {
			printf("\033[38;5;%d;48;5;%dm");
			printf("       ");
		}
		printf("\n");
		for (uint8_t x = 0; x < SIZE; x++) {
			printf("\033[38;5;%d;48;5;%dm");
			if (board[x][y] != 0)
			{
				uint32_t number = 1 << board[x][y];
				uint8_t t = 7 - getDigitCount(number);
				printf("%*s%u%*s", t - t / 2, "", number, t / 2, "");
			}
			else
			{
				printf("   ·   ");
			}
		}
		printf("\n");
		for (uint8_t x = 0; x < SIZE; x++)
		{
			printf("\033[38;5;%d;48;5;%dm");
			printf("       ");
		}
		printf("\n");
	}
}

void showEndGameMenu()
{
	printf("         GAME OVER          \n");
}

void showHint()
{
	printf("\n");
	printf("        ←,↑,→,↓ or q        \n");
}

void updateUserInterface(uint8_t board[SIZE][SIZE], uint32_t score)
{
	clearConsole();
	printf("Счёт: %20d \n\n", score);
	showGameField(board);
	showHint();
}

enum Direction convertToDirection(char keycode)
{
	switch (keycode)
	{
	case 'a':
	case 68: 
		return LEFT;
	case 'd':
	case 67:
		return RIGHT;
	case 'w':
	case 65:
		return UP;
	case 's':
	case 66:
		return DOWN;
	case 'q':
		return QUIT;
	default:
		return UNDEFINED;
	}
}