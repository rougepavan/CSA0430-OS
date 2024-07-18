#include <stdio.h>

int main() {
    int n, i, total_time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n];
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    for (i = 0; i < n; i++) {
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", i + 1, total_time, total_time + burst_time[i]);
        total_waiting_time += total_time;
        total_turnaround_time += total_time + burst_time[i];
        total_time += burst_time[i];
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
return 0; 
}
