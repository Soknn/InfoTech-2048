#include "errorMessager.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>


void writeError(char* message) {
	FILE* fileResult = fopen("errorResult.txt", "a");
	fputs(message, fileResult);
	fclose(fileResult);
}

void showErrorMessageByCode(int code) {

	switch (code)
	{
		case WRONG_RETURNED_VALUE_ERROR: 
			writeError("Неправильное возвращенное значение!\n");
			break;
		case RIGHT_RETURNED_VALUE:
			writeError("Верное возвращенное значение!\n");
			break;
		case WRONG_SLIDED_FIELD_ERROR:
			writeError("Неверное поле после смаха!\n");
			break;
		case RIGHT_SLIDED_FIELD:
			writeError("Верное поле после смаха!\n");
			break;
		case ABSENT_SOURCE_ACT:
			writeError("Отсутсвует файл полученных значений!\n");
		case ABSENT_SOURCE_EXPECT:
			writeError("Отсутсвует файл ожадиаемых значений!\n");
			break;
		case RIGHT_UPDATE_USER_INTERFACE:
			writeError("Верное обновление интерфейса!\n");
			break;
		case WRONG_UPDATE_USER_INTERFACE:
			writeError("Неверное обновление интерфейса!\n");
			break;
		case RIGHT_SHOW_ERROR:
			writeError("Верное отображение ошибки!\n");
			break;
		case WRONG_SHOW_ERROR:
			writeError("Неверное отображение ошибки!\n");
			break;
		case RIGHT_CONVERT_TO_DIRECTION:
			writeError("Верное преобразование введённого направления!\n");
			break;
		case WRONG_CONVERT_TO_DIRECTION:
			writeError("Неверное преобразование введённого направления!\n");
			break;
		default:
			writeError("Неизвестная ошибка!\n");
			break;
	}
}