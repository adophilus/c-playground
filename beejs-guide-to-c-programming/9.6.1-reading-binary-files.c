#include <stdio.h>

int main (void) {
  FILE *fp = fopen("output.bin", "rb");
  unsigned char c;

  /* while (fread(&c, sizeof(char), 1, fp) > 0) */
  while (fread(&c, sizeof(char), 1, fp) > 0)
    printf("%d\n", c);

  return 0;
}
