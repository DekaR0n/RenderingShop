#include <stdio.h>
#include <malloc.h>
#include "shop.h"

const int MAX_CUSTOMER_TIME = 5;
const int MAX_CASHIER_QUEUE = 7;
const int MAX_CASHIERS = 5;
const int MAX_NEXT_CUSTOMER = 4;
const int MAX_CUSTOMER_CHECK = 2;

const int MAX_CASHIER_NUMBER = 6;

void render(CashRegister *registers) {
    for (int i = 1; i < MAX_CASHIER_NUMBER+1; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < MAX_CASHIER_NUMBER; i++) {
        registers->visitor_value = 0;
        printf("%d ", registers->visitor_value);
    }
    printf("\n");
    for (int i = 0; i < MAX_CASHIER_NUMBER; i++) {
        printf(registers->val == 1 ? "+ " : "- ");
    }
    printf("\n");
    for (int i = 0; i < MAX_CASHIER_NUMBER; i++) {
        for (int j = 1; j < (MAX_CASHIER_QUEUE); j++) {
            printf("| ");
        }
        printf("\n");
    }
    printf("Время: \n"
           "Следующие посетители: \n");
}

int main() {
    CashRegister *registers = (CashRegister *) malloc(sizeof(CashRegister));
    render(registers);
    return 0;
}


