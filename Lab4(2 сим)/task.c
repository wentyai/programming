#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_LEVEL_LEN 20
#define MAX_LINE_LEN 200
#define MAX_EMPLOYEES 1000


typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    char level[MAX_LEVEL_LEN];
} Employee;

void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}


void printTable(Employee *employees, int count) {
    if (count == 0) {
        printf("Нет данных для отображения.\n");
        return;
    }
    
    printf("\n");
    printf("+------------------------------------+-------+----------+\n");
    printf("| %-34s | %-5s | %-8s |\n", "Имя", "ID", "Уровень");
    printf("+------------------------------------+-------+----------+\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-34s | %-5d | %-8s |\n", 
               employees[i].name, 
               employees[i].id, 
               employees[i].level);
    }
    
    printf("+------------------------------------+-------+----------+\n");
    printf("Всего сотрудников: %d\n", count);
}

int loadFromCSV(const char *filename, Employee **employees) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return -1;
    }
    
    *employees = (Employee*)malloc(MAX_EMPLOYEES * sizeof(Employee));
    if (*employees == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        fclose(file);
        return -1;
    }
    
    char line[MAX_LINE_LEN];
    int count = 0;
    
    while (fgets(line, sizeof(line), file) != NULL && count < MAX_EMPLOYEES) {

        trimNewline(line);
        

        if (strlen(line) == 0) {
            continue;
        }
        
        char *token = strtok(line, ";");
        if (token == NULL) continue;
        strcpy((*employees)[count].name, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        (*employees)[count].id = atoi(token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy((*employees)[count].level, token);
        
        count++;
    }
    
    fclose(file);
    return count;
}


int saveToBinary(const char *filename, Employee *employees, int count) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка: не удалось создать файл %s\n", filename);
        return -1;
    }
    

    size_t written = fwrite(&count, sizeof(int), 1, file);
    if (written != 1) {
        printf("Ошибка: не удалось записать количество сотрудников\n");
        fclose(file);
        return -1;
    }
    

    written = fwrite(employees, sizeof(Employee), count, file);
    if (written != (size_t)count) {
        printf("Ошибка: не удалось записать данные сотрудников\n");
        fclose(file);
        return -1;
    }
    
    fclose(file);
    printf("Данные успешно сохранены в файл %s\n", filename);
    return 0;
}

int loadFromBinary(const char *filename, Employee **employees) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return -1;
    }
    
    int count;

    size_t read = fread(&count, sizeof(int), 1, file);
    if (read != 1) {
        printf("Ошибка: не удалось прочитать количество сотрудников\n");
        fclose(file);
        return -1;
    }
    
    if (count <= 0 || count > MAX_EMPLOYEES) {
        printf("Ошибка: некорректное количество сотрудников (%d)\n", count);
        fclose(file);
        return -1;
    }
    
    *employees = (Employee*)malloc(count * sizeof(Employee));
    if (*employees == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        fclose(file);
        return -1;
    }
    

    read = fread(*employees, sizeof(Employee), count, file);
    if (read != (size_t)count) {
        printf("Ошибка: не удалось прочитать данные сотрудников\n");
        free(*employees);
        fclose(file);
        return -1;
    }
    
    fclose(file);
    return count;
}


void searchEmployee(Employee *employees, int count) {
    if (count <= 0) {
        printf("Ошибка: нет данных для поиска\n");
        return;
    }
    
    int searchId;
    printf("Введите ID сотрудника для поиска: ");
    
    if (scanf("%d", &searchId) != 1) {
        printf("Ошибка: введите корректное число\n");
        while (getchar() != '\n'); // очистка буфера
        return;
    }
    
    int found = -1;
    for (int i = 0; i < count; i++) {
        if (employees[i].id == searchId) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        printf("\nСотрудник найден:\n");
        printf("   Имя: %s\n", employees[found].name);
        printf("   ID: %d\n", employees[found].id);
        printf("   Уровень: %s\n", employees[found].level);
    } else {
        printf(" Ошибка: сотрудник с ID %d не найден\n", searchId);
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Использование: %s <файл.csv>\n", argv[0]);
        printf("Пример: %s staff.csv\n", argv[0]);
        return 1;
    }
    
    const char *csvFilename = argv[1];
    Employee *employees = NULL;
    

    printf("Загрузка данных из файла: %s\n", csvFilename);
    int count = loadFromCSV(csvFilename, &employees);
    
    if (count < 0) {
        return 1;
    }
    
    if (count == 0) {
        printf("В файле нет данных или файл пуст\n");
        free(employees);
        return 1;
    }
    
    printf("Загружено %d сотрудников\n", count);
    

    printf("\n=== ОТФОРМАТИРОВАННАЯ ТАБЛИЦА ===\n");
    printTable(employees, count);

    printf("\n=== СОХРАНЕНИЕ В БИНАРНЫЙ ФАЙЛ ===\n");
    if (saveToBinary("database.dat", employees, count) != 0) {
        free(employees);
        return 1;
    }
    

    free(employees);
    employees = NULL;
    
    printf("\n=== ПОИСК СОТРУДНИКА ===\n");
    count = loadFromBinary("database.dat", &employees);
    
    if (count < 0) {
        return 1;
    }
    
    printf("Загружено %d сотрудников из бинарного файла\n", count);
    
    searchEmployee(employees, count);
    
    free(employees);
    
    return 0;
}