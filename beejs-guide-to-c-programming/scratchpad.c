#include <stdio.h>

int *num;

int main (void) {
    printf("num = %p\n", (void*)num);

    int _num = 10;
    num = &_num;

    printf("num = %p\n", (void*)num);
    printf("*num = %d\n", *num);

    return 0;
}
