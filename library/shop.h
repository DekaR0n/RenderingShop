//
// Created by Margarita on 15.11.2022.
//

#ifndef RENDERINGSHOP_SHOP_H
#define RENDERINGSHOP_SHOP_H

#include "stdio.h"

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
    //struct QueueCommon *next;
} QueueCommon;

// Структура касса.
typedef struct CashRegister {
    int work_value;
    int visitor_value;
    int cash;
    QueueCommon *current_queue;
} CashRegister;


Queue *temp(QueueCommon* queue_common);
// Creates first element in queue.
QueueCommon *create_first(Visitor *visitor);

// Check if the queue is empty.
int is_empty();

// Check if the queue is full.
int is_full();

// Delete the first element.
QueueCommon *dequeue();

// Add an element to the last side.
QueueCommon *enqueue(Visitor *visitor);

// Returns the first element in queue.
Queue *front();

// Returns the last element in queue.
Queue *last();

int random(int max);

void render();

void start();

int *file_handler();

void const_init();

#endif //RENDERINGSHOP_SHOP_H
