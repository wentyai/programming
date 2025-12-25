#include <stdio.h>
#include <stdlib.h>

// Функция сравнения для целых чисел (по возрастанию)
int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2) return -1; // arg1 меньше arg2
    if (arg1 > arg2) return 1;  // arg1 больше arg2
    return 0;                   // arg1 равно arg2
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Вызов qsort
    qsort(arr, n, sizeof(int), compare_ints);

    printf("Отсортированный массив: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

