#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"
#define RECORD_SIZE sizeof(Employee)

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void writeRecord(int position, Employee emp) {
    FILE *file = fopen(FILE_NAME, "r+");
    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    fseek(file, position * RECORD_SIZE, SEEK_SET);
    fwrite(&emp, RECORD_SIZE, 1, file);
    fclose(file);
}

void readRecord(int position) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    Employee emp;
    fseek(file, position * RECORD_SIZE, SEEK_SET);
    fread(&emp, RECORD_SIZE, 1, file);
    fclose(file);

    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Salary: %.2f\n", emp.salary);
}

void addRecord() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    Employee emp;
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf(" %[^\n]", emp.name);  // Read string with spaces
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    fwrite(&emp, RECORD_SIZE, 1, file);
    fclose(file);
}

int main() {
    int choice, position;
    while (1) {
        printf("1. Add Record\n");
        printf("2. Read Record\n");
        printf("3. Update Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                printf("Enter position of record to read: ");
                scanf("%d", &position);
                readRecord(position);
                break;
            case 3:
                printf("Enter position of record to update: ");
                scanf("%d", &position);
                Employee emp;
                printf("Enter new employee ID: ");
                scanf("%d", &emp.id);
                printf("Enter new employee name: ");
                scanf(" %[^\n]", emp.name);
                printf("Enter new employee salary: ");
                scanf("%f", &emp.salary);
                writeRecord(position, emp);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

