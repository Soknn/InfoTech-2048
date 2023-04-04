#pragma once

#include "controller.h";

#define BLOCK_SIZE 8;

void updateUserInterface(uint8_t board[SIZE][SIZE], uint32_t score);

enum Direction convertToDirection(char keycode);