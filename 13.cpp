#include <stdio.h>
#include <stdlib.h>

int main() {
    // First-Fit Strategy
    int memory[10] = {0};
    int process1 = 5, process2 = 3, process3 = 7;
    int i;
    for (i = 0; i < 10; i++) {
        if (memory[i] == 0) {
            memory[i] = process1;
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        if (memory[i] == 0) {
            memory[i] = process2;
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        if (memory[i] == 0) {
            memory[i] = process3;
            break;
        }
    }

    // Best-Fit Strategy
    int best_fit_memory[10] = {0};
    int best_fit_process1 = 5, best_fit_process2 = 3, best_fit_process3 = 7;
    int min_diff = 10, index;
    for (i = 0; i < 10; i++) {
        if (best_fit_memory[i] == 0) {
            if (10 - i >= best_fit_process1 && 10 - i - best_fit_process1 < min_diff) {
                min_diff = 10 - i - best_fit_process1;
                index = i;
            }
        }
    }
    for (i = index; i < index + best_fit_process1; i++) {
        best_fit_memory[i] = best_fit_process1;
    }

    // Worst-Fit Strategy
    int worst_fit_memory[10] = {0};
    int worst_fit_process1 = 5, worst_fit_process2 = 3, worst_fit_process3 = 7;
    int max_diff = 0, index2;
    for (i = 0; i < 10; i++) {
        if (worst_fit_memory[i] == 0) {
            if (10 - i >= worst_fit_process1 && 10 - i - worst_fit_process1 > max_diff) {
                max_diff = 10 - i - worst_fit_process1;
                index2 = i;
            }
        }
    }
    for (i = index2; i < index2 + worst_fit_process1; i++) {
        worst_fit_memory[i] = worst_fit_process1;
    }

    return 0;
}
