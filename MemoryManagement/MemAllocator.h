#ifndef __MEM_ALLOCATOR_H__
#define __MEM_ALLOCATOR_H__

/**
* Learned concepts from these references:
* https://danluu.com/malloc-tutorial/
*  http://tharikasblogs.blogspot.com/p/how-to-write-your-own-malloc-and-free.html
*/

#include <stddef.h>
#include <assert.h>

//Memory block header
struct mem_block_header {
  size_t size;
  int free;
  struct mem_block_header* next;
}

//Size of a mem_block metadata header
#define META_SIZE  sizeof(struct mem_block_header)

//Size of memory pool for all new allocations
//Effective the "heap" size, but for embedded, this will be a
//statically allocated array at program start up
#define MEM_POOL_SIZE  8 * 1024

typedef struct mem_block_header mem_block_header

#ifdef __cplusplus
extern "C" {
#endif

void *mem_alloc(size_t size);
void mem_free(void* ptr);

#ifdef __cplusplus
}
#endif

#endif
