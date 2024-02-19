#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize)
{
    // If oldSize is 0 we free memory being pointed to by pointer.
    if (newSize == 0)
    {
        free(pointer);
        return NULL;
    }

    // Reallocates new memory of size newSize and assign pointer to it to pointer.
    // realloc will return the same pointer we gave it if newSize is smaller than oldSize.
    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1); // If we didn't have enough memory for reallocation.
    return result; // Return a pointer to newly allocated memory.
}
