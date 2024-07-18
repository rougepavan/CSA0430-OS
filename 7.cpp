#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, burst_time, arrival_time;
} Process;

void non_preemptive_sjf(Process *processes, int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time > time) time = processes[i].arrival_time;
        printf("Process %d is running...\n", processes[i].pid);
        time += processes[i].burst_time;
        printf("Process %d has completed its burst time.\n", processes[i].pid);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *processes = (Process *)malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].burst_time, &processes[i].arrival_time);
    }
    non_preemptive_sjf(processes, n);
    free(processes);
    return 0;
}
