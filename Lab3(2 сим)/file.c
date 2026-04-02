#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
    struct Node* down; 
} Node;

// создание узла
Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = val;
    n->next = NULL;
    n->prev = NULL;
    n->down = NULL;
    return n;
}

// добавление в конец
void append(Node** head, Node* n) {
    if (*head == NULL) {
        *head = n;
        return;
    }

    Node* temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void buildLists(Node** top, Node** bottom, int N) {
    for (int i = N; i >= 1; i--) {
        Node* n = createNode(i);

        if (i % 2 == 0)
            append(top, n);
        else
            append(bottom, n);
    }
}

void connect(Node* top, Node* bottom) {
    Node* t = top;
    Node* b = bottom;

    while (t && b) {
        t->down = b;
        t = t->next;
        b = b->next;
    }
}


void printList(Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void navigate(Node* start) {
    Node* cur = start;
    char cmd;

    printf("\nW/A/S/D или 2/4/6/8, q — выход\n");

    while (1) {
        printf("\nТекущий: %d\n", cur->value);
        printf("Команда: ");
        scanf(" %c", &cmd);

        if (cmd == 'q') break;

        if (cmd == 'd' || cmd == '6') {
            if (cur->next)
                cur = cur->next;
            else
                printf("Конец списка\n");
        }

        else if (cmd == 'a' || cmd == '4') {
            if (cur->prev)
                cur = cur->prev;
            else
                printf("Начало списка\n");
        }

        else if (cmd == 's' || cmd == '2') {
            if (cur->down)
                cur = cur->down;
            else
                printf("Нет перехода вниз\n");
        }

        else if (cmd == 'w' || cmd == '8') {
            printf("Нет перехода вверх\n");
        }
    }
}

int main() {
    int N;
    printf("Введите N: ");
    scanf("%d", &N);

    Node* top = NULL;
    Node* bottom = NULL;

    buildLists(&top, &bottom, N);
    connect(top, bottom);

    printf("\nВерхний список:\n");
    printList(top);

    printf("Нижний список:\n");
    printList(bottom);

    Node* S = top; 
    navigate(S);

    return 0;
}