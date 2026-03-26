#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "employee.h"

static const char* getRandomLastName() {
    const char *names[] = {"Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов",
                           "Попов", "Васильев", "Соколов", "Михайлов", "Фёдоров"};
    return names[rand() % 10];
}

void fillEmployees(Employee *arr, int n) {
    srand((unsigned int)time(NULL)); 
    for (int i = 0; i < n; i++) {
        strcpy(arr[i].lastName, getRandomLastName());
        arr[i].id = i + 1; 
        arr[i].department = rand() % 5 + 1; 
        arr[i].salary = (rand() % 30000 + 20000) + (rand() % 100) / 100.0f; 
    }
}

void printTable(const Employee *arr, int n) {
    printf("\n+-----+----------------------+-------------+----------+--------------+\n");
    printf("|  №  |      Фамилия         | Табельный № | Отдел    | Оклад (руб.) |\n");
    printf("+-----+----------------------+-------------+----------+--------------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %-20s | %11d | %8d | %12.2f |\n",
               i + 1, arr[i].lastName, arr[i].id, arr[i].department, arr[i].salary);
    }
    printf("+-----+----------------------+-------------+----------+--------------+\n");
}

void sortById(Employee *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].id < arr[minIndex].id) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Employee temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}