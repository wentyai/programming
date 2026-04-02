#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define N 10 

typedef struct {
    char lastName[50];
    int id;          
    int department;  
    float salary;    
} Employee;

void fillEmployees(Employee *arr, int n);
void printTable(const Employee *arr, int n);
void sortById(Employee *arr, int n);

#endif