#include "gcmalloc.h"

static header *free_list;
static header *used_list;

static void add_to_list(header *list, header *block) {
  if (new_block == NULL) {
    warn("add_to_list block is null");
    return;
  }
  if (block <= list) {
    error("add_to_list block's address is less than list head");
    return;
  }
  header p;
  for (p = list; !(p < block && block < p->next); p = p->next) {
    if (p >= p->next) {
      break;
    }
  }
  block->next = p->next;
  p->next = block;
  if (block != block->next && ((void *) block + block->size == (void *) block->next)) {
    block->size += block->next->size;
    
  }
  return;
}

static void add_to_free_list(header *block) {
  add_to_list(free_list, block);
}

static void add_to_used_list(header *block) {
  block->next = used_list->next;
  used_list->next = block;
}

static void extendMemory(size_t nbytes) {
  
}

static void init_list_head() {
  free_list = (header) malloc(sizeof(header) * 2);
  used_list = (header) malloc(sizeof(header) * 2);
  free_list->size = used_list->size = sizeof(header) * 2;
  free_list->next = free_list;
  used_list->next = used_list;
}
