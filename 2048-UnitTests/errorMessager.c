#include "errorMessager.h"
#include <stdio.h>
#include <locale.h>

void showErrorMessageByCode(int code) {
	setlocale(LC_ALL, "");

	printf("���������: ");

	switch (code)
	{
		case WRONG_RETURNED_VALUE_ERROR: 
			printf("������������ ������������ ��������!\n");
			break;
		case RIGHT_RETURNED_VALUE:
			printf("������ ������������ ��������!\n");
			break;
		case WRONG_SLIDED_FIELD_ERROR:
			printf("�������� ���� ����� �����!\n");
			break;
		case RIGHT_SLIDED_FIELD:
			printf("������ ���� ����� �����!\n");
			break;
		default:
			printf("����������� ������!\n");
			break;
	}
}