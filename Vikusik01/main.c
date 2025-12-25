#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;
Date inputDate() {
    Date d;
    printf("Введите день: ");
    scanf("%d", &d.day);
    printf("Введите месяц: ");
    scanf("%d", &d.month);
    printf("Введите год: ");
    scanf("%d", &d.year);
    return d;
}
void printPersonInfo(Date d) {
    printf("Дата рождения: %02d.%02d.%d\n", d.day, d.month, d.year);
    if (d.day <= 10)
        printf("Декада: 1 декада месяца\n");
    else if (d.day <= 20)
        printf("Декада: 2 декада месяца\n");
    else
        printf("Декада: 3 декада месяца\n");
    if (d.month == 12 || d.month <= 2)
        printf("Сезон: Зима\n");
    else if (d.month >= 3 && d.month <= 5)
        printf("Сезон: Весна\n");
    else if (d.month >= 6 && d.month <= 8)
        printf("Сезон: Лето\n");
    else
        printf("Сезон: Осень\n");
    int century = (d.year - 1) / 100 + 1;
    printf("Век: %d век\n\n", century);
}

int main() {
    int N;
    printf("Введите количество людей: ");
    scanf("%d", &N);
    
    Date persons[N];
    for (int i = 0; i < N; i++) {
        printf("\nЧеловек %d:\n", i + 1);
        persons[i] = inputDate();
    }
    printf("\n ---Результаты: \n");
    for (int i = 0; i < N; i++) {
        printf("Человек %d:\n", i + 1);
        printPersonInfo(persons[i]); 
    }
    
    return 0;
}