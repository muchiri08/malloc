#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024
#define HEAP_FREED_CAP 1024

typedef struct {
  void *start;
  size_t size;
} Chunk;

typedef struct {
  size_t count;
  Chunk chunks[HEAP_ALLOCED_CAP];
} Chunk_List;

void chunk_list_dump(const Chunk_List *list) {
  printf("Chunks (%zu):\n", list->count);
  for (size_t i = 0; i < list->count; i++) {
    printf("start: %p, size: %zu\n", list->chunks[i].start,
           list->chunks[i].size);
  }
}

int chunk_list_find(const Chunk_List *list, void *ptr) {
  assert(false && "TODO: chunk_list_find is not implemented!");
}

void chunk_list_insert(Chunk_List *list, void *ptr, size_t size) {
  assert(false && "TODO: chunk_list_insert is not implemented!");
}

void chunk_list_remove(Chunk_List *list, size_t index) {
  assert(false && "TODO: chunk_list_remove is not implemented!");
}

char heap[HEAP_CAP] = {0};
size_t heap_size = 0;

Chunk_List alloced_chunks = {0};
Chunk_List freed_chunks = {0};

void *heap_alloc(size_t size) {
  // for simplicity, if size zero return NULL
  if (size == 0) {
    return NULL;
  }
  assert(heap_size + size <= HEAP_CAP);
  void *ptr = heap + heap_size;
  heap_size += size;
  chunk_list_insert(&alloced_chunks, ptr, size);
  return ptr;
}

void heap_free(void *ptr) {
  (void)ptr;
  assert(false && "TODO: heap_free is not implemented!");
}

void heap_collect() {}

int main() {
  for (size_t i = 0; i < 100; i++) {
    void *p = heap_alloc(i);
  }
  chunk_list_dump(&alloced_chunks);
  return 0;
}
