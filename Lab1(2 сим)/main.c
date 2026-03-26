#include <stdio.h>
#include "employee.h"

int main() {
    Employee employees[N];

    printf("=== Программа: База данных сотрудников ===\n");

    fillEmployees(employees, N);

    printf("\n--- Массив ДО сортировки (по табельному номеру): ---");
    printTable(employees, N);

    sortById(employees, N);

    printf("\n--- Массив ПОСЛЕ сортировки (по табельному номеру): ---");
    printTable(employees, N);

    return 0;
}