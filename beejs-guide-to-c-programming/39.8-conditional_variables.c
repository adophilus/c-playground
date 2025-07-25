#include <stdio.h>
#include <threads.h>
#define ARRAY_LENGTH 5

int current_array_length = 0;
int nums[ARRAY_LENGTH];

mtx_t value_mtx;
cnd_t value_cnd;

int child_thread_fn(void* arg) {
    (void)arg;
     
    while (true) {
        mtx_lock(&value_mtx);

        if (current_array_length < ARRAY_LENGTH) {
            printf("Thread: is waiting\n");
            cnd_wait(&value_cnd, &value_mtx);
        }
        
        printf("Thread: is awake!\n");
        
        int t = 0;

        for (int i = 0; i < current_array_length; i++) {
            t += nums[i];
        }
        
        printf("Thread: total is %d\n", t);
        
        current_array_length = 0;
        
        mtx_unlock(&value_mtx);
    }

    return 0;
}

int main(void) {
    thrd_t t;

    thrd_create(&t, child_thread_fn, NULL);
    thrd_detach(t);

    mtx_init(&value_mtx, mtx_plain);
    cnd_init(&value_cnd);

    while (true) {
        int n;

        scanf("%d", &n);
        
        mtx_lock(&value_mtx);

        nums[current_array_length++] = n;
        
        if (current_array_length == ARRAY_LENGTH) {
            printf("Main: signaling thread\n");
            cnd_signal(&value_cnd);
        }
        
        mtx_unlock(&value_mtx);
    }

    mtx_destroy(&value_mtx);
    cnd_destroy(&value_cnd);

    return 0;
}
