#ifndef GCMALLOC_H
#define GCMALLOC_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCK_SIZE 4

typedef struct header_t {
  void *next;
  size_t size;
} header;

#endif
