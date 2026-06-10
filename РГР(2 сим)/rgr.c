#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int count = 0;

void swap(char *a, char *b) {

    char t = *a; *a = *b; *b = t;

}

void permute(char *word, int start, int len) {

    if (count >= 10) return;

    

    if (start == len - 1) {

        printf("%s\n", word);

        count++;

        return;

    }

    for (int i = start; i < len; i++) {

        if (count >= 10) return;

        swap(&word[start], &word[i]);

        permute(word, start + 1, len);

        swap(&word[start], &word[i]);

    }

}

int main(int argc, char *argv[]) {

    if (argc != 2) {

        fprintf(stderr, "Использование: %s <файл>\n", argv[0]);

        return 1;

    }

    FILE *f = fopen(argv[1], "r");

    if (!f) {

        perror("Ошибка открытия файла");

        return 1;

    }

    char word[256];

    if (!fgets(word, sizeof(word), f)) {

        fprintf(stderr, "Файл пуст\n");

        fclose(f);

        return 1;

    }

    fclose(f);

    int len = strlen(word);

    if (len > 0 && word[len - 1] == '\n') word[--len] = '\0';

    if (len > 0 && word[len - 1] == '\r') word[--len] = '\0';

    printf("Первые 10 анаграмм слова \"%s\":\n", word);

    permute(word, 0, len);

    return 0;

}