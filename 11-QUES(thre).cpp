#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int id = *(int*)arg;
    printf("Hello from thread %d!\n", id);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int ids[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_function, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
