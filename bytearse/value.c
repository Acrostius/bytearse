#include <stdio.h>

#include "memory.h"
#include "value.h"

// Initialize values array for constant pool.
void initValueArray(ValueArray* array)
{
	array->capacity = 0;
	array->count = 0;
	array->values = NULL;
}

void writeValueArray(ValueArray* array, Value value)
{
	if (array->capacity < array->count + 1)
	{
		int oldCapacity = array->capacity;

		// Updates max capacity to fit new value in array then grows the array.
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
	}

	// After successfully growing the Value Array we can write the new value to it -
	// and increase the value count on the Value Array.
	array->values[array->count] = value;
	array->count++;
}

void freeValueArray(ValueArray* array)
{
	FREE_ARRAY(Value, array->values, array->capacity);
	initValueArray(array);
}

void printValue(Value value)
{
	printf("%g", value);
}