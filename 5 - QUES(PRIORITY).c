#include <stdio.h>

int main() {
    int n = 5,i,j,temp;
    int priorities[] = {3, 1, 4, 2, 5};
    int pids[] = {1, 2, 3, 4, 5};

    for( i = 0; i < n; i++) {
        int maxIndex = i;
        for(j = i + 1; j < n; j++) {
            if (priorities[j] > priorities[maxIndex])
                maxIndex = j;
        }
         temp = priorities[i];
        priorities[i] = priorities[maxIndex];
        priorities[maxIndex] = temp;

        temp = pids[i];
        pids[i] = pids[maxIndex];
        pids[maxIndex] = temp;
    }

    for( i = 0; i < n; i++) {
        printf("Executing process %d with priority %d\n", pids[i], priorities[i]);
    }

    return 0;
}
