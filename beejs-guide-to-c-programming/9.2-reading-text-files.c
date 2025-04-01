#include <stdio.h>

int main (void) {
  FILE *fp;
  fp = fopen("hello.txt", "r");

  int c;

  while ((c = fgetc(fp)) != EOF)
    printf("%c", c);

  fclose(fp);
  return 0;
}
