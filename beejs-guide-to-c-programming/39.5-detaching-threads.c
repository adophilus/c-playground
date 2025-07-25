#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define THREAD_COUNT 10

int run (void *arg) {
    int i = *(int*)arg;
    
    free(arg);

    printf("THREAD %d: running!\n", i);
    
    return i;
}

int main (void) {
    thrd_t t[THREAD_COUNT];
    int i;
    
    printf("Launching threads\n");
    
    for (i = 0; i < THREAD_COUNT; i++) {
        int *arg = malloc(sizeof *arg);
        *arg = i;
        thrd_create(t + i, run, arg);
        thrd_detach(t[i]);
    }
    
    printf("Doing other things while the threads run\n");
    
    thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);

    return 0;
} 
