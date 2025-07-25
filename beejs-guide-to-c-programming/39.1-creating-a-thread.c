#include <stdio.h>
#include <threads.h>

int run (void *arg) {
    int *a = arg;

    printf("THREAD: Running thread with arg %d\n", *a);
    
    return 12;
}

int main (void) {
    thrd_t t;
    int arg = 3490;

    printf("Launching a thread\n");
    
    thrd_create(&t, run, &arg);
    
    printf("Doing other things while the thread runs\n");
    
    printf("Waiting for thread to complete...\n");
    
    int res;

    thrd_join(t, &res);

    printf("Thread exited with return value %d\n", res);

    return 0;
} 
