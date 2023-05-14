#include "controllerTests.h"
#include "viewTests.h"
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	testView();
	testController();
}