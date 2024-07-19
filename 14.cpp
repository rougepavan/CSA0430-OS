#include <stdio.h>
#include <string.h>

#define MAX_FILES 5
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    int size;
} File;

File dir[MAX_FILES];
int count = 0;

void addFile(char* name, int size) {
    if (count < MAX_FILES) {
        strcpy(dir[count].name, name);
        dir[count].size = size;
        count++;
        printf("File '%s' added\n", name);
    } else {
        printf("Directory is full\n");
    }
}

void listFiles() {
    printf("Files in directory:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%d bytes)\n", dir[i].name, dir[i].size);
    }
}

int main() {
    addFile("file1.txt", 100);
    addFile("file2.txt", 200);
    addFile("file3.txt", 300);
    listFiles();
    return 0;
}
