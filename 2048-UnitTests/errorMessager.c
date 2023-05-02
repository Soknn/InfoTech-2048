#include "errorMessager.h"
#include <stdio.h>
#include <locale.h>

void showErrorMessageByCode(int code) {
	setlocale(LC_ALL, "");

	printf("Результат: ");

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
		default:
			printf("Неизвестная ошибка!\n");
			break;
	}
}