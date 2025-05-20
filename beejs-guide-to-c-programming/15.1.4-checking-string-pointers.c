#include <stdio.h>
#include <stdlib.h>

void check_name(char *name, char *errptr) {
  printf("char *errptr = %p\n", (void*)errptr);

  /* errptr = &name[1]; */
  /* errptr = &name[1]; */
  /* *errptr = name[1]; */
  *errptr = 'a';
  /* errptr = &name[1]; */
  /* errptr = name + 1; */
  /* printf("&name[1] = %p\n", (void*)errptr); */
}

int main (void) {
  char *name = "Marcus Aurelius";
  /* char *badstr = malloc(1); */
  char *badstr;

  printf("Before `check_name(...)`, badstr = %p, badstr = %s\n", (void*)badstr, badstr);

  check_name(name, badstr);

  printf("After `check_name(...)`, badstr = %p, badstr = %s\n", (void*)badstr, badstr);

  return 0;
}
