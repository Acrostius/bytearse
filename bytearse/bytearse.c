#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[])
{
    // Initialize default chunk values to 0.
    Chunk chunk;
    initChunk(&chunk);
    
    // Add constant value 1.2f to constant pool. Needs to have precision lowered.
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    // -- ONLY FOR TESTING PURPOSES (REMOVE LATER)
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);

    return 0;
}
