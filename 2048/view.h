#pragma once

#include "controller.h";

void updateUserInterface(uint8_t board[SIZE][SIZE], uint32_t score);

enum Direction convertToDirection(char keycode);