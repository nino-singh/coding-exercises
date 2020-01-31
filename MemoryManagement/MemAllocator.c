#include "MemAllocator.h"

//Pointer to head of free list
//Memory allocator will keep track of all free blocks in a singly
//linked list
static mem_block_header *base;

//Index position in the statically allocated array of memory
static int free_pool_pos;

//Initialize our static memory pool
static char pool[MEM_POOL_SIZE] = {0};

//Helper functions
static void* request_mem(mem_block_header *last, size_t size);
static mem_block_header* find_free_block(mem_block_header **last, size_t size);
static mem_block_header* split(mem_block_header* b, size_t allocSize);
static void merge(void);

/**
* Initialize head of free list
*/
void mem_init(void) {
  base = NULL;
  free_pool_pos = 0;
}

/**
* Allocate memory of requested size. Search the free blocks list to see if
* an existing memory block can be reused. If not, request new memory from
* memory pool and update the free pool pointer
*/
void *mem_alloc(size_t size)
{
  if(size <= 0) {
    return NULL;
  }

  mem_block_header *blockp = NULL;

  //First call, no free blocks in list yet, request memory from our pool
  if(base == NULL) {
    blockp = (mem_block_header*)request_mem(NULL, size);

    if(blockp == NULL) {
      return NULL;
    } else {
      base = blockp;
    }
  } else {
    mem_block_header* last = base;
    blockp = find_free_block(&last, size);

    if(blockp == NULL) {
      //If no free block exists, request memory from our pool
      blockp = request_mem(last, size);

      if(blockp == NULL) {
        return NULL;
      } else {
        //Todo: Consider splitting block so we give a block of exact size
        //instead of wasting the whole block which could be larger
        blockp->free = 0;
      }
    }
  }
  //return pointer to allocated block space, skip over the block header
  return (blockp + 1);
}


/**
* Access the associated metadata header for this pointer and
* and update its parameters including the free flag and its next pointer
* Then deallocate the memory that ptr points to by simply returning the block to the
* free list
*/
void mem_free(void* ptr)
{
  if(ptr == NULL) {
    return;
  }
  mem_block_header* blockp = (mem_block_header*)(ptr-1);
  assert(blockp->free == 0); //should be equal to 0!
  blockp->free = 1;
}

static void* pool_alloc(size_t size) {

  if(size == 0) {
    return (void *)&pool[free_pool_pos];
  }

  void *freep = (void*)&pool[free_pool_pos];
  free_pool_pos+=size;

  if(free_pool_pos >= MEM_POOL_SIZE) {
      return NULL;
  }
  return freep;
}

/**
* Used to request more memory from the heap which is managed by the OS
* In this case, we have a large statically allocated array as the "heap"
* If there are no free blocks that have been malloced and freed for reuse,
* request more space from this allocation pool
*/
static void* request_mem(mem_block_header *last, size_t size)
{
  mem_block_header* blockp = pool_alloc(0);
  void* requestedp = pool_alloc(size+sizeof(mem_block_header));

  assert((void*)blockp == requestedp);

  if(requestedp == (void*) -1) {
    return NULL; //pool_alloc failed
  }

 //NULL on First request
  if(last != NULL) {
    last->next = blockp;
  }
  blockp->size = size;
  blockp->next = NULL;
  blockp->free = 0;

  return blockp;
}

static mem_block_header* find_free_block(mem_block_header **last, size_t size) {
  mem_block_header *blockp = base;

  while(blockp != NULL && !(blockp->free && blockp->size>=size)) {
    *last = blockp;
    blockp = blockp->next;
  }
  return blockp;
}

/**
* If we found a free block to use and its bigger than the memory
* we requested, split the free block and return a block of exact size
*/
static mem_block_header* split(mem_block_header* b, size_t allocSize)
{
  return NULL;
}

/**
* This would get called if there is no free block that is greater than or
* equal to the requested memory. Merge one or more blocks together to form
* a free block to allocate.
*/
static void merge(void)
{
  return;
}
