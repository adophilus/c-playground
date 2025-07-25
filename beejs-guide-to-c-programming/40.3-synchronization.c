#include <stdio.h>
#include <threads.h>

int x = 0, y = 0;

int thread_fn1(void *arg) {
    (void)arg;
    
    x = 2;
    y = 3;

    return 0;
}

int thread_fn2(void *arg) {
    (void)arg;
    
    while (y != 3) {}
    printf("x is now %d\n", x);

    return 0;
}

int main (void) {
    thrd_t t1, t2;

    thrd_create(&t1, thread_fn1, NULL);
    thrd_create(&t2, thread_fn2, NULL);
    
    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    return 0;
}
