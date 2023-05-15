#pragma once

/*
 * @brief Константа, код ошибки для неверного пользовательского ввода
 * @author Клюшин Максим
 */
#define WRONG_INPUT_ERROR_CODE 1

/*
  * @brief Функция, обрабатывающая ошибку на основе её кода
  * @param[in] errorCode код ошибки
  * @author Клюшин Максим
  */
void processError(int errorCode);