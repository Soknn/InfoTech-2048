#pragma once

#include <stdbool.h>

/*
 * @brief Константа, указывающая на размер стороны поля
 * @author Калугин Илья
 */
#define SIZE 4

/*
 * @brief Перечисление, указывающая направление перемещения кубиков на игровом поле
 * @author Калугин Илья
 */
enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	UNDEFINED,
	QUIT
};

/*
 * @brief Функция, возвращающая игровое поле
 * @return игровое поле
 * @author Калугин Илья
 */
int** getField();

/*
 * @brief Функция, возвращающая текущий счёт игрока
 * @return текущий счёт игрока
 * @author Калугин Илья
 */
int getScore();

/*
 * @brief Функция, указывающая закончились ли легальные ходы для игрока
 * @return проиграл ли игрок
 * @author Калугин Илья
 */
bool isGameOver();

/*
 * @brief Функция, перемещающая кубики на поле в определенном направлении
 * @param[in] direction направление, куда направляются кубики
 * @author Калугин Илья
 */
void slideTo(enum Direction direction);

/*
 * @brief Функция, инициализирующая поле и счёт игрока
 * @author Калугин Илья
 */
void init();