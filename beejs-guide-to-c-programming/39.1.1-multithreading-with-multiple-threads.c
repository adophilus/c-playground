#include <stdio.h>
#include <threads.h>

#define THREAD_COUNT 5

int run (void *arg) {
    int i = *(int*)arg;

    printf("THREAD %d: running!\n", i);
    
    return i;
}

int main (void) {
    thrd_t t[THREAD_COUNT];
    int i;
    
    printf("Launching threads\n");
    
    for (i = 0; i < THREAD_COUNT; i++)
        thrd_create(t + i, run, &i);
    
    printf("Doing other things while the threads run\n");
    
    printf("Waiting for threads to complete...\n");
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        int res;
        thrd_join(t[i], &res);
        
        printf("Thread %d complete!\n", res);
    }

    printf("All threads complete!\n");

    return 0;
} 
