#include "memoryMgr.h"

//Empty block to start
static mem_header_t base;

//Pointer to free blocks list
static mem_header_t* freep = 0;

//Initialize the static memory pool
byte pool[POOL_SIZE] = {0};
