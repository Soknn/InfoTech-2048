#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "errorMessager.h"
#include "main.h"
#include "../2048/errorProcess.h"

void testProcessError(char* fileNameAct, char* fileNameExpect, int successErrorCode, int wrongErrorCode, int errorCodeAct) {

    int errorCode;

    freopen(fileNameAct, "w", stdout);
    processError(errorCodeAct);
    freopen(FILE_NAME_RESULT, "a", stdout);

    FILE* fileAct = fopen(fileNameAct, "r");
    FILE* fileExpect = fopen(fileNameExpect, "r");

    if (fileAct == NULL) {
        errorCode = ABSENT_SOURCE_ACT;
    }
    else if (fileExpect == NULL)
    {
        errorCode = ABSENT_SOURCE_EXPECT;
    }
    else
    {
        if (compareFile(fileAct, fileExpect)) {
            errorCode = successErrorCode;
        }
        else {
            errorCode = wrongErrorCode;
        }
        fclose(fileAct);
        fclose(fileExpect);
    }
    showErrorMessageByCode(errorCode);
}

void testProcessInputError() {
    printf("| Тест обработки ошибки ввода |\n");

    char* fileNameAct = "processInputErrorAct.txt";
    char* fileNameExpect = "processInputErrorExpect.txt";
    int codeInputError = WRONG_INPUT_ERROR_CODE;

    testProcessError(fileNameAct, fileNameExpect, RIGHT_PROCESS_INPUT_ERROR, WRONG_PROCESS_INPUT_ERROR, codeInputError);
}

void testProcessUnknownError() {
    printf("| Тест обработки неизвестной ошибки |\n");

    char* fileNameAct = "processUnknownErrorAct.txt";
    char* fileNameExpect = "processUnknownErrorExpect.txt";
    int codeInputError = -100;

    testProcessError(fileNameAct, fileNameExpect, RIGHT_PROCESS_UNKNOWN_ERROR, WRONG_PROCESS_UNKNOWN_ERROR, codeInputError);
}

void testErrorProcess() {
	printf("| Тесты модуля обработки ошибок |\n");
    testProcessInputError();
    testProcessUnknownError();
}