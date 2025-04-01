#include <stdio.h>
#include <string.h>

void* custom_memcpy(void* dest, void* src, size_t byte_count) {
  char *s = src, *d = dest;

  while (byte_count-- > 0)
    *d++ = *s++;

  return dest;
}

int main (void) {
  char *source_str = "Goats!";
  char dest_str[10];

  memcpy(dest_str, source_str, strlen(source_str));
  printf("dest_str = '%s'\n", dest_str);

  const int INT_ARRAY_LENGTH = 3;
  int source_ints[] = { 10, 20, 30 };
  int dest_ints[INT_ARRAY_LENGTH];

  custom_memcpy(dest_ints, source_ints, sizeof(int) * INT_ARRAY_LENGTH);

  printf("dest_ints = ");
  for (int i = 0; i < INT_ARRAY_LENGTH; i++)
    printf("%d, ", dest_ints[i]);
  printf("\n");

  return 0;
}
