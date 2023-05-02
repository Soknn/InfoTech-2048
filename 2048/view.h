#pragma once

#include "controller.h"

/*
 * @brief Константа, определяющая ширину ячейки поля на консоли
 * @author Аксёнов Руслан
 */
#define BLOCK_SIZE 8;

 /*
  * @brief Функция, обновляющая игровое поле на консоли
  * @author Аксёнов Руслан
  */
void updateUserInterface();

/*
 * @brief Функция, выводящая сообщение ошибка на консоль
 * @param[in] errorMessage сообщение ошибки
 * @author Аксёнов Руслан
 */
void showError(const char* errorMessage);

/*
 * @brief Функция, переводящая клавитурный символ в приятное для обработки направления перемещения кубиков
 * @param[in] keyCode код символа
 * @param[out] Direction направление перемещения кубиков
 * @author Аксёнов Руслан
 */
enum Direction convertToDirection(char keycode);