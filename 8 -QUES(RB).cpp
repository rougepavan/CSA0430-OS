#include <stdio.h>

#define MAX_PROCESSES 5
#define TIME_QUANTUM 2

typedef struct {
    int pid;
    int burst_time;
} Process;

void round_robin(Process processes[], int n) {
    int time = 0, completed = 0;
    int remaining_burst_time[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                printf("Process %d is executing...\n", processes[i].pid);
                int time_quantum = TIME_QUANTUM;
                while (time_quantum > 0 && remaining_burst_time[i] > 0) {
                    remaining_burst_time[i]--;
                    time_quantum--;
                    time++;
                }
                if (remaining_burst_time[i] == 0) {
                    completed++;
                }
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    round_robin(processes, n);

    return 0;
}
