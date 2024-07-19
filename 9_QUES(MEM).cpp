#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHARED_MEMORY_SIZE 1024

int main() {
    // Create a shared memory segment
    int fd = shm_open("/my_shared_memory", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SHARED_MEMORY_SIZE);
    void* shared_memory = mmap(NULL, SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process writes to shared memory
        sprintf((char*)shared_memory, "Hello from child!");
    } else {
        // Parent process waits for child to finish
        wait(NULL);
        // Parent process reads from shared memory
        printf("%s\n", (char*)shared_memory);
    }

    // Clean up
    munmap(shared_memory, SHARED_MEMORY_SIZE);
    shm_unlink("/my_shared_memory");

    return 0;
}
