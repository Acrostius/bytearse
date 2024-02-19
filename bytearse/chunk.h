#ifndef bytearse_chunk_h
#define bytearse_chunk_h

#include "common.h"

// Opcodes dataset.
typedef enum {
    OP_RETURN
} OpCode;

typedef struct {
    int useCount;
    int capacity;
    uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif // bytearse_chunk_h
