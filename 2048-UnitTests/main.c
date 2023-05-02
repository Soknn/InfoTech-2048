#include "controllerTests.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	
	testController();
}