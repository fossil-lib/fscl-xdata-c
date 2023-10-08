/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloPQueue* trilo_xdata_pqueue_create(enum DataType queue_type) {
    TriloPQueue* queue = (TriloPQueue*)malloc(sizeof(TriloPQueue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    queue->front = NULL;
    queue->queue_type = queue_type;
    return queue;
} // end of func

void trilo_xdata_pqueue_destroy(TriloPQueue* queue) {
    TriloPQueueNode* current = queue->front;
    TriloPQueueNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while
    free(queue);
} // end of func

bool trilo_xdata_pqueue_is_empty(const TriloPQueue* queue) {
    return queue->front == NULL;
} // end of func

void trilo_xdata_pqueue_enqueue(TriloPQueue* queue, TriloTofu data, int priority) {
    // Ensure the data type matches the queue type
    if (data.type != queue->queue_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloPQueueNode* new_node = (TriloPQueueNode*)malloc(sizeof(TriloPQueueNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (queue->front == NULL || priority > queue->front->priority) {
        new_node->next = queue->front;
        queue->front = new_node;
    } else {
        TriloPQueueNode* current = queue->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        } // end while
        new_node->next = current->next;
        current->next = new_node;
    } // end if else
} // end of func

void trilo_xdata_pqueue_dequeue(TriloPQueue* queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloPQueueNode* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
} // end of func

TriloTofu trilo_xdata_pqueue_peek(const TriloPQueue* queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty!\n");
        exit(EXIT_FAILURE);
    } // end if
    return queue->front->data;
} // end of func

void trilo_xdata_pqueue_print(const TriloPQueue* queue) {
    TriloPQueueNode* current = queue->front;
    while (current != NULL) {
        switch (queue->queue_type) {
            case INTEGER_TYPE:
                printf("%d (Priority: %d) -> ", current->data.data.integer_type, current->priority);
                break;
            case DOUBLE_TYPE:
                printf("%lf (Priority: %d) -> ", current->data.data.double_type, current->priority);
                break;
            case STRING_TYPE:
                printf("%s (Priority: %d) -> ", current->data.data.string_type, current->priority);
                break;
            case CHAR_TYPE:
                printf("%c (Priority: %d) -> ", current->data.data.char_type, current->priority);
                break;
            case BOOLEAN_TYPE:
                printf("%s (Priority: %d) -> ", current->data.data.boolean_type ? "true" : "false", current->priority);
                break;
            default:
                printf("Unknown type\n");
                break;
        } // end switch
        current = current->next;
    } // end while
    printf("NULL\n");
} // end of func

int trilo_xdata_pqueue_size(const TriloPQueue* pqueue) {
    return pqueue->size;
} // end of func