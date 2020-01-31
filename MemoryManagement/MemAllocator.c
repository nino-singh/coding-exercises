#include "MemAllocator.h"

//Pointer to head of free list
//Memory allocator will keep track of all free blocks in a singly
//linked list
static mem_block_header *base;

//Index position in the statically allocated array of memory
static int free_pool_pos;

//Helper functions
static void* request_mem(mem_block_header *last, size_t size);
static void* split(mem_block_header* b, size_t allocSize);
static void merge(void);

/**
* Initialize head of free list
*/
void mem_init(void) {
  return;
}

/**
* Used to request more memory from the heap which is managed by the OS
* In this case, we have a large statically allocated array as the "heap"
* If there are no free blocks that have been malloced and freed for reuse,
* request more space from this allocation pool
*/
static void* request_mem(mem_block_header *last, size_t size)
{
  return NULL;
}

/**
* If we found a free block to use and its bigger than the memory
* we requested, split the free block and return a block of exact size
*/
static void* split(mem_block_header* b, size_t allocSize)
{
  return NULL;
}

/**
* This would get called if there is no free block that is greater than or
* equal to the requested memory. Merge one or more blocks together to form
* a free block to allocate.
*/
static void merge(void);

/**
* Allocate memory of requested size. Search the free blocks list to see if
* an existing memory block can be reused. If not, request new memory from
* memory pool and update the free pool pointer
*/
void *mem_alloc(size_t size)
{
  return NULL;
}


/**
* Access the associated metadata header for this pointer and
* and update its parameters including the free flag and its next pointer
* Then deallocate the memory that ptr points to by simply returning the block to the
* free list
*/
void mem_free(void* ptr)
{
  return;
}
