#ifndef __MEMORY_MANAGER_H__
#define __MEMORY_MANAGER_H__

#ifdef __cplusplus
extern "C" {

typedef unsigned char byte
typedef unsigned long ulong

//Quanta is two ulongs (on 32-bit architecture this is total of 16 bytes)

//Keep track of free list (free blocks) and used list (used blocks)

//Each chunk of allocation has a header
//which keeps track of size of allocation and
//Pointer to next free block of memory in free list
typedef struct {
  struct mem_header_t *next;
  ulong size;
} mem_header_t;

//Minimum allocation size. If requested allocation is smaller than this
// set it equal to the size of a block (this value)
#define MIN_POOL_ALLOC_QUANTAS  8

//The static memory pool that all allocations/deallocations will be from
//This is like the "heap"
#define POOL_SIZE   8 * 1024 //~8Kbytes

//Initialize memory manager
void memoryMgr_init(void);

void *memoryMgr_alloc(ulong nBytes);

void memoryMgr_free(void*);


#ifdef __cplusplus
}
#endif

#endif
