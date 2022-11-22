//
// Created by Margarita on 17.11.2022.
//
#include "shop.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"

int CUSTOMER_TIME;
int CASHIER_QUEUE;
int CASHIERS;
int NEXT_CUSTOMER;
int CUSTOMER_CHECK;
int CASHIER_NUMBER;

QueueCommon *root = NULL;


int random(int max) {
    srand(time(NULL));
    return 1 + rand() % max;
}

void render() {
    CashRegister *registers = (CashRegister *) malloc(sizeof(CashRegister));
    for (int i = 1; i < CASHIER_NUMBER + 1; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < CASHIER_NUMBER; i++) {
        registers->visitor_value = 0;
        printf("%d ", registers->visitor_value);
    }
    printf("\n");
    for (int i = 0; i < CASHIER_NUMBER; i++) {
        printf(registers->work_value == 1 ? "+ " : "- ");
    }
    printf("\n");
    for (int i = 0; i < CASHIER_QUEUE; i++) {
        for (int j = 0; j < (CASHIER_NUMBER); j++) {
            printf("| ");
        }
        printf("\n");
    }
    printf("Time: \n"
           "Next visitors: \n"
           "Leaf money: \n");
}

void start() {
    // system("cls");
    render();
    Sleep(600);
    system("cls");
}

int *file_handler() {
    int *file_values = (int *) malloc(6 * sizeof(int));
    FILE *values = fopen("settings.txt", "r");
    int count_space = 0, current;
    char symbol;
    for (int i = 0; i < 6; i++) {
        while (count_space != 2) {
            fscanf(values, "%c", &symbol);
            if (symbol == ' ') {
                count_space++;
            }
        }
        count_space = 0;
        symbol = 0;

        fscanf(values, "%d", &current);
        file_values[i] = random(current);
    }
    return file_values;
}

void const_init() {
    int *file_values = file_handler();
    CUSTOMER_TIME = file_values[0];
    CASHIER_QUEUE = file_values[1];
    CASHIERS = file_values[2];
    NEXT_CUSTOMER = file_values[3];
    CUSTOMER_CHECK = file_values[4];
    CASHIER_NUMBER = file_values[5];

    free(file_values);
}

Queue *temp(QueueCommon* queue_common){
    Queue * temp=root->first;
    while (temp->next!=queue_common->last){
        temp=temp->next;
    }
    return temp;
}
QueueCommon *create_first(Visitor *visitor) {
    root->first->visitor = visitor;
    root->last = NULL;
    root->length=1;
    return root;
}

int is_empty() {
    return root->first == NULL;
}

int is_full() {
    return root->length == CASHIER_QUEUE;
}

QueueCommon *dequeue() {
    QueueCommon *queue_temp = root;
    queue_temp->first = root->first->next;
    root->length--;
    front()->next = NULL;
    free(queue_temp);
    return NULL;
}

QueueCommon *enqueue(Visitor *visitor) {
    if(!is_full()) {
        if (!is_empty()) {
            last()->visitor = visitor;
            last()->next = NULL;
            root->length++;
        } else {
            create_first(visitor);
        }
    }
    return root;
}

Queue *front() {
    return root->first;
}

Queue *last() {
    return root->last;
}
