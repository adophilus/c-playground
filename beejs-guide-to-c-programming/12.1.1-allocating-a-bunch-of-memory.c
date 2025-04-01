#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hook_exit(void) {
  int num;

  printf("Press <Enter> to exit\n");
  scanf("%d", &num);
}

size_t gb_to_bytes (int gb) {
  return (size_t) gb * 1024 * 1024 * 1024;
}

int bytes_to_gb (size_t bytes) {
  return (bytes / (1024 * 1024 * 1024));
}

int main (void) {
  size_t mem_size = gb_to_bytes(10);

  printf("Attempting to allocate %d GB of memory\n", bytes_to_gb(mem_size));
  void *mem = malloc(mem_size);

  char *writable = mem;

  for (size_t i = 0; i < mem_size; i++)
    writable[i] = 'a';

  hook_exit();

  return 0;
}
