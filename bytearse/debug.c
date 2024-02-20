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
	if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1])
	{
		printf("   | ");
	}
	else
	{
		printf("%4d ", chunk->lines[offset]);
	}

	// Reads single byte from bytecode at the given offset.
	uint8_t instruction = chunk->code[offset];
	switch (instruction)
	{
	case OP_CONSTANT:
		return constantInstruction("OP_CONSTANT", chunk, offset);
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

static int constantInstruction(const char* name, Chunk* chunk, int offset)
{
	uint8_t constant = chunk->code[offset + 1];
	printf("%-16s %4d '", name, constant);
	printValue(chunk->constants.values[constant]);
	printf("'\n");

	// Here we return a offset to the beginning of the next instruction.
	// We return 2 bytes because 1 byte is for the opcode and the other for the operand -
	// e.g value being added.
	return offset + 2;
}