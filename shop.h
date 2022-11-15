//
// Created by Margarita on 15.11.2022.
//

#ifndef RENDERINGSHOP_SHOP_H
#define RENDERINGSHOP_SHOP_H

typedef struct Visitor {
    char *name;
    int time;
    int sum;
} Visitor;

// Структура элемента очереди.
typedef struct Queue {
    Visitor *visitor;
    struct Queue *next;
} Queue;

// Структура очереди.
typedef struct QueueCommon {
    struct Queue *last;
    struct Queue *first;
    int length;
} QueueCommon;

// Структура касса.
typedef struct CashRegister {
    int val;
    int visitor_value;
    int cash;
    QueueCommon *current_queue;
    struct CashRegister *next;
} CashRegister;

// ..

Queue *get_last(QueueCommon *queue);

//
void push(Queue *queue);

//
void pop(Queue *queue);

// Возвращает элемент очереди
Visitor *getElement();

// Печать работы магазина
void show();

// Возвращает имя человека в очереди
char *get_name();

// Возвращает сумму покупки.
void get_value();


#endif //RENDERINGSHOP_SHOP_H
