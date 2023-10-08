/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloQueue* trilo_xdata_queue_create(enum DataType queue_type) {
    TriloQueue* queue = (TriloQueue*)malloc(sizeof(TriloQueue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    queue->front = NULL;
    queue->rear = NULL;
    queue->queue_type = queue_type;
    return queue;
} // end of func

void trilo_xdata_queue_destroy(TriloQueue* queue) {
    TriloQueueNode* current = queue->front;
    TriloQueueNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while
    free(queue);
} // end of func

bool trilo_xdata_queue_is_empty(const TriloQueue* queue) {
    return queue->front == NULL;
} // end of func

void trilo_xdata_queue_enqueue(TriloQueue* queue, TriloTofu data) {
    TriloQueueNode* newNode = trilo_xdata_queue_node_create(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    } // end if else
    queue->size++;  // Increment the size
} // end of func

void trilo_xdata_queue_dequeue(TriloQueue* queue) {
    if (queue->front != NULL) {
        TriloQueueNode* temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        } // end if
        free(temp);
        queue->size--;  // Decrement the size
    } // end if
} // end of func

TriloTofu trilo_xdata_queue_peek(const TriloQueue* queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty!\n");
        exit(EXIT_FAILURE);
    } // end if
    return queue->front->data;
} // end of func

void trilo_xdata_queue_print(const TriloQueue* queue) {
    TriloQueueNode* current = queue->front;
    while (current != NULL) {
        switch (queue->queue_type) {
            case INTEGER_TYPE:
                printf("%d -> ", current->data.data.integer_type);
                break;
            case DOUBLE_TYPE:
                printf("%lf -> ", current->data.data.double_type);
                break;
            case STRING_TYPE:
                printf("%s -> ", current->data.data.string_type);
                break;
            case CHAR_TYPE:
                printf("%c -> ", current->data.data.char_type);
                break;
            case BOOLEAN_TYPE:
                printf("%s -> ", current->data.data.boolean_type ? "true" : "false");
                break;
            default:
                printf("Unknown type\n");
                break;
        } // end switch
        current = current->next;
    } // end while
    printf("NULL\n");
} // end of func

int trilo_xdata_queue_size(const TriloQueue* queue) {
    return queue->size;
} // end of func
