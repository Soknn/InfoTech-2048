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

void updateUserInterface(uint8_t board[SIZE][SIZE], uint32_t score)
{
	printf("\033[H");
	printf("2048.c %17d pts\n\n", score);
	showGameField(board);
	showHint();
}

void showGameField(uint8_t board[SIZE][SIZE])
{
	for (uint8_t y = 0; y < SIZE; y++) {
		for (uint8_t x = 0; x < SIZE; x++) {
			printf("\033[38;5;%d;48;5;%dm");
			printf("       ");
			printf("\033[m");
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
			printf("\033[m");
		}
		printf("\n");
		for (uint8_t x = 0; x < SIZE; x++)
		{
			printf("\033[38;5;%d;48;5;%dm");
			printf("       ");
			printf("\033[m");
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
	printf("\033[A");
}

enum Direction convertToDirection(char keycode)
{
	if (keycode == -1)
	{
		puts("\nError! Cannot read keyboard input!");
	}

	switch (keycode)
	{
	case 97:  // 'a' key
	case 104: // 'h' key
	case 68:  // left arrow
		return LEFT;
	case 100: // 'd' key
	case 108: // 'l' key
	case 67:  // right arrow
		return RIGHT;
	case 119: // 'w' key
	case 107: // 'k' key
	case 65:  // up arrow
		return UP;
	case 115: // 's' key
	case 106: // 'j' key
	case 66:  // down arrow
		return DOWN;
	default:
		return UNDEFINED;
	}
}