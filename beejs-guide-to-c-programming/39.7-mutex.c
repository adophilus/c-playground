#include <stdio.h>
#include <threads.h>
#include <stdlib.h>
#define THREAD_COUNT 10

mtx_t serial_mtx;

int thread_fn(void *arg) {
    static int serial = 0;
    
    int n = *(int*)arg;
    free(arg);

    mtx_lock(&serial_mtx);

    printf("Thread %d! %d\n", n, serial);
    serial++;

    mtx_unlock(&serial_mtx);

    return 0;
}

int main(void) {
    thrd_t t[THREAD_COUNT];

    mtx_init(&serial_mtx, mtx_plain);

    for (int i = 0; i < THREAD_COUNT; i++) {
        int* n = malloc(sizeof(int*));
        *n = i;
        thrd_create(t + i, thread_fn, n);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        thrd_join(t[i], NULL);
    }
    
    mtx_destroy(&serial_mtx);

    return 0;
}
