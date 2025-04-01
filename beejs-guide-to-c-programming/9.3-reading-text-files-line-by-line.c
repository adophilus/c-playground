#include <stdio.h>

int main (void) {
  FILE *fp;
  char s[1024];
  int linescount = 0;

  fp = fopen("quote.txt", "r");

  while (fgets(s, sizeof s, fp) != NULL)
    printf("%d: %s", ++linescount, s);

  fclose(fp);

  return 0;
}
