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
			writeError("������������ ������������ ��������!\n");
			break;
		case RIGHT_RETURNED_VALUE:
			writeError("������ ������������ ��������!\n");
			break;
		case WRONG_SLIDED_FIELD_ERROR:
			writeError("�������� ���� ����� �����!\n");
			break;
		case RIGHT_SLIDED_FIELD:
			writeError("������ ���� ����� �����!\n");
			break;
		case ABSENT_SOURCE_ACT:
			writeError("���������� ���� ���������� ��������!\n");
		case ABSENT_SOURCE_EXPECT:
			writeError("���������� ���� ���������� ��������!\n");
			break;
		case RIGHT_UPDATE_USER_INTERFACE:
			writeError("������ ���������� ����������!\n");
			break;
		case WRONG_UPDATE_USER_INTERFACE:
			writeError("�������� ���������� ����������!\n");
			break;
		case RIGHT_SHOW_ERROR:
			writeError("������ ����������� ������!\n");
			break;
		case WRONG_SHOW_ERROR:
			writeError("�������� ����������� ������!\n");
			break;
		case RIGHT_CONVERT_TO_DIRECTION:
			writeError("������ �������������� ��������� �����������!\n");
			break;
		case WRONG_CONVERT_TO_DIRECTION:
			writeError("�������� �������������� ��������� �����������!\n");
			break;
		default:
			writeError("����������� ������!\n");
			break;
	}
}