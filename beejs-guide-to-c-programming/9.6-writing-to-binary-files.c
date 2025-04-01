#include <stdio.h>

int main (void) {
  const int BYTE_LENGTH = 6;
  unsigned char bytes[BYTE_LENGTH] = { 5, 37, 0, 88, 255, 12 };
  FILE *fp = fopen("output.bin", "wb");

  fwrite(bytes, sizeof(char), BYTE_LENGTH, fp);

  fclose(fp);

  return 0;
}
