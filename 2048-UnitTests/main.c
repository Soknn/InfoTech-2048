#define _CRT_SECURE_NO_WARNINGS
#include "controllerTests.h"
#include "viewTests.h"
#include "errorProcessTests.h"
#include "main.h"
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	freopen(FILE_NAME_RESULT, "w", stdout);
	testErrorProcess();
	testView();
	testController();
}