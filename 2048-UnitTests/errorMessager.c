#define _CRT_SECURE_NO_WARNINGS
#include "errorMessager.h"
#include <stdio.h>
#include <locale.h>

void showErrorMessageByCode(int code) {

	switch (code)
	{
		case WRONG_RETURNED_VALUE_ERROR: 
			printf("Неправильное возвращенное значение!\n");
			break;
		case RIGHT_RETURNED_VALUE:
			printf("Верное возвращенное значение!\n");
			break;
		case WRONG_SLIDED_FIELD_ERROR:
			printf("Неверное поле после смаха!\n");
			break;
		case RIGHT_SLIDED_FIELD:
			printf("Верное поле после смаха!\n");
			break;
		case RIGHT_SCORE:
			printf("Верное возвращение счёта!\n");
			break;
		case RIGHT_GAME_OVER:
			printf("Верное возвращение признака окончания игры!\n");
			break;
		case WRONG_GAME_OVER:
			printf("Неверное возвращение признака окончания игры!\n");
			break;
		case WRONG_SCORE:
			printf("Неверное возвращение счёта!\n");
			break;
		case ABSENT_SOURCE_ACT:
			printf("Отсутсвует файл полученных значений!\n");
		case ABSENT_SOURCE_EXPECT:
			printf("Отсутсвует файл ожадиаемых значений!\n");
			break;
		case RIGHT_UPDATE_USER_INTERFACE:
			printf("Верное обновление интерфейса!\n");
			break;
		case WRONG_UPDATE_USER_INTERFACE:
			printf("Неверное обновление интерфейса!\n");
			break;
		case RIGHT_SHOW_ERROR:
			printf("Верное отображение ошибки!\n");
			break;
		case WRONG_SHOW_ERROR:
			printf("Неверное отображение ошибки!\n");
			break;
		case RIGHT_CONVERT_TO_DIRECTION:
			printf("Верное преобразование введённого направления!\n");
			break;
		case WRONG_CONVERT_TO_DIRECTION:
			printf("Неверное преобразование введённого направления!\n");
			break;
		case RIGHT_PROCESS_INPUT_ERROR:
			printf("Верная обработка ошибки ввода!\n");
			break;
		case WRONG_PROCESS_INPUT_ERROR:
			printf("Неверная обработка ошибки ввода!\n");
			break;
		case RIGHT_PROCESS_UNKNOWN_ERROR:
			printf("Верная обработка неизвестной ошибки!\n");
			break;
		case WRONG_PROCESS_UNKNOWN_ERROR:
			printf("Неверная обработка неизвестной ошибки!\n");
			break;
		default:
			printf("Неизвестная ошибка!\n");
			break;
	}
}