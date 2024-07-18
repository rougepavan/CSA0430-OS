#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, priority, burst_time, arrival_time;
} Process;

void pre_emptive_priority_scheduling(Process *processes, int n) {
    int time = 0;
    while (1) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].burst_time > 0) {
                flag = 1;
                printf("Process %d is running...\n", processes[i].pid);
                processes[i].burst_time--;
                time++;
            }
        }
        if (!flag) break;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *processes = (Process *)malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].priority, &processes[i].burst_time, &processes[i].arrival_time);
    }
    pre_emptive_priority_scheduling(processes, n);
    free(processes);
    return 0;
}
