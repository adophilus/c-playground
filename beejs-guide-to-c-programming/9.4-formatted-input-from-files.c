#include <stdio.h>

int main (void) {
  FILE *fp = fopen("whales.txt", "r");

  char name[255];
  float length;
  int mass;

  while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF) {
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);
  }

  fclose(fp);

  return 0;
}
