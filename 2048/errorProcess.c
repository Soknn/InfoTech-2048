#include "view.h"
#include "errorProcess.h"

void processError(int errorCode) {
	switch (errorCode)
	{
		case WRONG_INPUT_ERROR_CODE:
			showError("Неверный ввод направления свайпа!");
			break;
		default:
			showError("Неизвестная ошибка!");
			break;
	}
}