#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define N 10 // Количество сотрудников

// Структура "Сотрудник"
typedef struct {
    char lastName[50];
    int id;          // Табельный номер
    int department;  // Номер отдела
    float salary;    // Оклад
} Employee;

// Прототипы функций
void fillEmployees(Employee *arr, int n);
void printTable(const Employee *arr, int n);
void sortById(Employee *arr, int n);

#endif