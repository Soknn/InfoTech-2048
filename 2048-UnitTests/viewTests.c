#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "errorMessager.h"
#include "../2048/view.h"
#include "main.h"

bool compareFile(FILE* firstFile, FILE* secondFile) {
    char firstBuffer[MAX_BUFFER_SIZE];
    fgets(firstBuffer, MAX_BUFFER_SIZE, firstFile);
    char secondBuffer[MAX_BUFFER_SIZE];
    fgets(secondBuffer, MAX_BUFFER_SIZE, secondFile);
    if (strcmp(firstBuffer, secondBuffer) == 0) {
        return true;
    }
    else {
        return false;
    }
    return false;
};

void compareInterfaceActWithExpect(char* fileNameAct, char* fileNameExpect, int successErrorCode, int wrongErrorCode ) {
    int errorCode;
    FILE* fileAct = fopen(fileNameAct, "r");
    FILE* file1Expect = fopen(fileNameExpect, "r");

    if (fileAct == NULL) {
        errorCode = ABSENT_SOURCE_ACT;
    }
    else if (file1Expect == NULL)
    {
        errorCode = ABSENT_SOURCE_EXPECT;
    }
    else
    {


        if (compareFile(fileAct, file1Expect)) {
            errorCode = successErrorCode;
        }
        else {
            errorCode = wrongErrorCode;
        }

        fclose(fileAct);
        fclose(file1Expect);
    }
    showErrorMessageByCode(errorCode);

}


void testUpdateUserInterface() {
    printf("| Тест обновления интерфейса |\n");
    int errorCode;
    char* fileNameAct = "updateUserInterfaceAct.txt";
    char* fileNameExpect = "updateUserInterfaceExpect.txt";

    freopen(fileNameAct, "w", stdout);
    updateUserInterface();
    freopen(FILE_NAME_RESULT, "a", stdout);

    compareInterfaceActWithExpect(fileNameAct, fileNameExpect, RIGHT_UPDATE_USER_INTERFACE, WRONG_UPDATE_USER_INTERFACE);
}

void testShowError() {
    printf("| Тест отображения ошибок |\n");
    char* fileNameAct = "showErrorAct.txt";
    char* fileNameExpect = "showErrorExpect.txt";
    char* testErrorText = "Test error";

    freopen(fileNameAct, "w", stdout);
    showError(testErrorText);
    freopen("errorResult.txt", "a", stdout);

    compareInterfaceActWithExpect(fileNameAct, fileNameExpect, RIGHT_SHOW_ERROR, WRONG_SHOW_ERROR);

}

void testConvertToDirection() {
    printf("| Тест преобразования введённого направления |\n");
    int errorCode;
    char* fileNameAct = "convertToDirectionAct.txt";
    char* fileNameExpect = "convertToDirectionExpect.txt";
    char testInputKeycode = 'a';
    enum Direction directionExpect = LEFT;

    enum Direction directionAct = convertToDirection(testInputKeycode);

    errorCode = directionAct == directionExpect ? RIGHT_CONVERT_TO_DIRECTION : WRONG_CONVERT_TO_DIRECTION;
    showErrorMessageByCode(errorCode);
}

void testView() {
    printf("| Тест модуля графического отображения |\n");
    testShowError();
    testConvertToDirection();
	testUpdateUserInterface();
}