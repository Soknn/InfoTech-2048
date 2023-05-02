#include "view.h"
#include "errorProcessor.h"

void processError(int errorCode) {
	switch (errorCode)
	{
		case WRONG_INPUT_ERROR_CODE:
			showError("�������� ���� ����������� ������!");
			break;
		default:
			showError("����������� ������!");
			break;
	}
}