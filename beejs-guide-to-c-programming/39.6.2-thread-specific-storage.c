#include <stdio.h>
#include <threads.h>
#include <stdlib.h>
#define THREAD_COUNT 10

tss_t str;

void worker_fn(void) {
    char *tss_string = tss_get(str);
    
    printf("TSS string: %s\n", tss_string);
}

int thread_fn(void *arg) {
    int serial = *(int*) arg;
    free(arg);
    
    char *s = malloc(64);
    sprintf(s, "thread %d! :)", serial);
    
    tss_set(str, s);
    
    worker_fn();

    return 0;
}

int main (void) {
    thrd_t t[THREAD_COUNT];
    
    tss_create(&str, free);

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *n = malloc(sizeof(int));
        *n = i;
        thrd_create(t + i, thread_fn, n);
    }
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        thrd_join(t[i], NULL);
    }
    
    tss_delete(str);

    return 0;
}
