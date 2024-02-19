#include <stdio.h>

#include "debug.h"

void disassembleChunk(Chunk* chunk, const char* name)
{
	printf("== %s == \n", name);

	// Loop through all instructions and print their OpCode and mnemonic.
	for (int offset = 0; offset < chunk->useCount;)
	{
		offset = disassembleInstruction(chunk, offset);
	}
}

int disassembleInstruction(Chunk* chunk, int offset)
{
	printf("%04d ", offset);

	// Reads single byte from bytecode at the given offset.
	uint8_t instruction = chunk->code[offset];
	switch (instruction)
	{
	case OP_RETURN:
		// simpleInstruction will return the offset to the next instruction.
		return simpleInstruction("OP_RETURN", offset);
	default:
		printf("Unknown opcode %d\n", instruction);
		return offset + 1;
	}
}

static int simpleInstruction(const char* name, int offset)
{
	printf("%s\n", name);
	return offset + 1;
}