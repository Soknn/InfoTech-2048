#pragma once

#include <stdbool.h>

/*
 * @brief ���������, ������������ ������ ������� ����
 * @author ������� ����
 */
#define SIZE 4

/*
* @brief ���������, ����������� ��������� �������� ������
* @author ������� ����
*/
#define BASE_VALUE 2

/*
 * @brief ������������, ����������� ����������� ����������� ������� �� ������� ����
 * @author ������� ����
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
 * @brief �������, ������������ ������� ����
 * @return ������� ����
 * @author ������� ����
 */
int getValueAt(int column, int row);

/*
 * @brief �������, ������������ ������� ���� ������
 * @return ������� ���� ������
 * @author ������� ����
 */
int getScore();

/*
 * @brief �������, ����������� ����������� �� ��������� ���� ��� ������
 * @return �������� �� �����
 * @author ������� ����
 */
bool isGameOver();

/*
 * @brief �������, ������������ ������ �� ���� � ������������ �����������
 * @param[in] direction �����������, ���� ������������ ������
 * @author ������� ����
 */
void slideTo(enum Direction direction);

/*
 * @brief �������, ���������������� ���� � ���� ������
 * @author ������� ����
 */
void init();