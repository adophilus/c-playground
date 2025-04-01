#include <stdio.h>
#include <stdlib.h>

int main (void) {
  FILE *fp = fopen("./source_code.txt", "r");

  int line_count = 0;
  size_t grow_size = 1024;
  size_t buf_size = grow_size;
  int longest_line_length = 0;
  int current_line_length = 0;
  char *buf = malloc(buf_size);
  char c;
  size_t i = 0;

  while (c = fgetc(fp), c != EOF) {
    current_line_length += 1;

    if (i == (buf_size - 1)) {
      char* new_buf = realloc(buf, buf_size + grow_size);
      if (new_buf == NULL) {
        fprintf(stderr, "Error reallocating...\n");

        fclose(fp);
        free(buf);

        return 1;
      }

      buf = new_buf;
    }

    buf[i] = c;

    if (c == '\n') {
      if (current_line_length > longest_line_length) {
        longest_line_length = current_line_length;
      }

      current_line_length = 0;
      line_count++;
    }

    i++;
  }

  printf("METRICS:\n");
  printf("Lines: %d\n", line_count);
  printf("Longest Line: %d\n", longest_line_length);

  /* fclose(fp); */
  /* free(buf); */

  return 0;
}
