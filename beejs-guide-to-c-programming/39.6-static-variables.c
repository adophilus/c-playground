#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define THREAD_COUNT 5

int run (void *arg) {
    int i = *(int*)arg;
    
    free(arg);
    
    static int foo = 10;
    
    int x = foo;
    
    printf("Thread %d: x = %d, foo = %d\n", i, x, foo);
    
    if (x != foo) {
        printf("Thread %d: Craziness! x != foo! %d != %d\n", i, x, foo);
    }
    
    foo++;

    return 0;
}

int main (void) {
    thrd_t t[THREAD_COUNT];
    int i;
    
    for (i = 0; i < THREAD_COUNT; i++) {
        int *arg = malloc(sizeof *arg);
        *arg = i;
        thrd_create(t + i, run, arg);
    }
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        thrd_join(t[i], NULL);
    }

    return 0;
} 
