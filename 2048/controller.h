#pragma once

#include <stdbool.h>

/*
 * @brief Константа, определяющая размер стороны поля
 * @author Клюшин Максим
 */
#define SIZE 4

/*
* @brief Константа, опредляющая начальное значение кубика
* @author Клюшин Максим
*/
#define BASE_VALUE 2

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
int getValueAt(int column, int row);

/*
 * @brief Функция, возвращающая текущий счёт игрока
 * @return текущий счёт игрока
 * @author Клюшин Максим
 */
int getScore();

/*
 * @brief Функция, указывающая закончились ли легальные ходы для игрока
 * @return проиграл ли игрок
 * @author Клюшин Максим
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

/*
 * @brief Функция, устанавливающая новое поле
 * @author Калугин Илья
 */
void setField(int field[SIZE][SIZE]);
