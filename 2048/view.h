#pragma once

#include "controller.h"

/*
 * @brief ���������, ������������ ������ ������ ���� �� �������
 * @author ������ ������
 */
#define BLOCK_SIZE 8;

 /*
  * @brief �������, ����������� ������� ���� �� �������
  * @author ������ ������
  */
void updateUserInterface();

/*
 * @brief �������, ��������� ��������� ������ �� �������
 * @param[in] errorMessage ��������� ������
 * @author ������ ������
 */
void showError(const char* errorMessage);

/*
 * @brief �������, ����������� ����������� ������ � �������� ��� ��������� ����������� ����������� �������
 * @param[in] keyCode ��� �������
 * @param[out] Direction ����������� ����������� �������
 * @author ������ ������
 */
enum Direction convertToDirection(char keycode);