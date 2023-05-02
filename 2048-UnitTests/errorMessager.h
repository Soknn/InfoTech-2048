#pragma once

#define WRONG_RETURNED_VALUE_ERROR 0x001 

#define RIGHT_RETURNED_VALUE 0x002

#define WRONG_SLIDED_FIELD_ERROR 0x003

#define RIGHT_SLIDED_FIELD 0x004

void showErrorMessageByCode(int code);