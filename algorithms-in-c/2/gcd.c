#include <stdio.h>

int gcd(int u, int v) {
  int t;

  while (u > 0) {
    if (u < v) {
      t = u;
      u = v;
      v = t;
    }

    u = u % v;
  }

  return v;
}

int gcd_mod_debug(int u, int v) {
  int t;

  while (u > 0) {
    if (u < v) {
      t = u;
      u = v;
      v = t;
    }

    printf("u = %d, v = %d, u %% v = %d\n", u, v, u % v);

    u = u % v;
  }

  return v;
}

int gcd_traditional(int u, int v) {
  int t;

  while (u > 0) {
    if (u < v) {
      t = u;
      u = v;
      v = t;
    }

    u = u - v;
  }

  return v;
}
