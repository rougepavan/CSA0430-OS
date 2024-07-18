#include <stdio.h>

int main() {
    int n = 5,i,j;
    int executionTimes[] = {5, 3, 8, 2, 6};
    int pids[] = {1, 2, 3, 4, 5};
    for(i = 0; i < n; i++) {
        int minIndex = i;
        for(j = i + 1; j < n; j++) {
            if (executionTimes[j] < executionTimes[minIndex])
                minIndex = j;
        }
        int temp = executionTimes[i];
        executionTimes[i] = executionTimes[minIndex];
        executionTimes[minIndex] = temp;
        temp = pids[i];
        pids[i] = pids[minIndex];
        pids[minIndex] = temp;
    }
    for(i = 0; i < n; i++) {
        printf("Executing process %d with execution time %d\n", pids[i], executionTimes[i]);
    }
    return 0;
}
