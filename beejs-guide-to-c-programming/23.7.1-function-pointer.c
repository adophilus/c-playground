#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int mul(int x, int y)
{
    return x * y;
}

void print_math(int (*math_fn)(int, int), int x, int y)
{
    int z = math_fn(x, y);

    printf("The result is %d\n", z);
}

int main(void)
{
    int x = 25;
    int y = 16;

    print_math(add, x, y);

    return 0;
}