void swap(int *restrict a, int *restrict b) {
  int t;

  t = *a;
  *a = *b;
  *b = t;
}

int main(void) {
  int x = 10, y = 10;
  swap(&x, &y);
  swap(&x, &x);
  return 0;
}
