#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];

void* philosopher(void* arg) {
    int id = *(int*)arg;
    int left_fork = id;
    int right_fork = (id + 1) % N;

    while (1) {
        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d is eating\n", id);
        usleep(rand() % 1000000);
        pthread_mutex_unlock(&forks[right_fork]);
        pthread_mutex_unlock(&forks[left_fork]);
        usleep(rand() % 1000000);
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N] = {0, 1, 2, 3, 4};

    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}_
