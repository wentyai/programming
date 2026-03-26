#include <stdio.h>
#include "employee.h"

int main() {
    Employee employees[N];

    printf("=== Программа: База данных сотрудников ===\n");

    // Заполнение массива
    fillEmployees(employees, N);

    // Вывод до сортировки
    printf("\n--- Массив ДО сортировки (по табельному номеру): ---");
    printTable(employees, N);

    // Сортировка
    sortById(employees, N);

    // Вывод после сортировки
    printf("\n--- Массив ПОСЛЕ сортировки (по табельному номеру): ---");
    printTable(employees, N);

    return 0;
}