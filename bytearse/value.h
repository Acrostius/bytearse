#ifndef bytearse_value_h
#define bytearse_value_h

#include "common.h"

typedef double Value;

typedef struct
{
	int capacity;
	int count;
	Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif // bytearse_value_h
