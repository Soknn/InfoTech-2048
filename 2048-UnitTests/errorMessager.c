#define _CRT_SECURE_NO_WARNINGS
#include "errorMessager.h"
#include <stdio.h>
#include <locale.h>

void showErrorMessageByCode(int code) {

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
		case RIGHT_SCORE:
			printf("������ ����������� �����!\n");
			break;
		case RIGHT_GAME_OVER:
			printf("������ ����������� �������� ��������� ����!\n");
			break;
		case WRONG_GAME_OVER:
			printf("�������� ����������� �������� ��������� ����!\n");
			break;
		case WRONG_SCORE:
			printf("�������� ����������� �����!\n");
			break;
		case ABSENT_SOURCE_ACT:
			printf("���������� ���� ���������� ��������!\n");
		case ABSENT_SOURCE_EXPECT:
			printf("���������� ���� ���������� ��������!\n");
			break;
		case RIGHT_UPDATE_USER_INTERFACE:
			printf("������ ���������� ����������!\n");
			break;
		case WRONG_UPDATE_USER_INTERFACE:
			printf("�������� ���������� ����������!\n");
			break;
		case RIGHT_SHOW_ERROR:
			printf("������ ����������� ������!\n");
			break;
		case WRONG_SHOW_ERROR:
			printf("�������� ����������� ������!\n");
			break;
		case RIGHT_CONVERT_TO_DIRECTION:
			printf("������ �������������� ��������� �����������!\n");
			break;
		case WRONG_CONVERT_TO_DIRECTION:
			printf("�������� �������������� ��������� �����������!\n");
			break;
		case RIGHT_PROCESS_INPUT_ERROR:
			printf("������ ��������� ������ �����!\n");
			break;
		case WRONG_PROCESS_INPUT_ERROR:
			printf("�������� ��������� ������ �����!\n");
			break;
		case RIGHT_PROCESS_UNKNOWN_ERROR:
			printf("������ ��������� ����������� ������!\n");
			break;
		case WRONG_PROCESS_UNKNOWN_ERROR:
			printf("�������� ��������� ����������� ������!\n");
			break;
		default:
			printf("����������� ������!\n");
			break;
	}
}