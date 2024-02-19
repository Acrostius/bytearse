#ifndef bytearse_debug_h
#define bytearse_debug_h

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif // bytearse_debug_h
