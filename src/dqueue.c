/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/dqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloDQueue* trilo_xdata_dqueue_create(enum DataType deque_type) {
    TriloDQueue* deque = (TriloDQueue*)malloc(sizeof(TriloDQueue));
    if (deque == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    deque->front = NULL;
    deque->rear = NULL;
    deque->deque_type = deque_type;
    return deque;
} // end of func

void trilo_xdata_dqueue_destroy(TriloDQueue* deque) {
    TriloDQueueNode* current = deque->front;
    TriloDQueueNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while
    free(deque);
} // end of func

bool trilo_xdata_dqueue_is_empty(const TriloDQueue* deque) {
    return deque->front == NULL;
} // end of func

void trilo_xdata_dqueue_push_front(TriloDQueue* deque, TriloTofu data) {
    // Ensure the data type matches the deque type
    if (data.type != deque->deque_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloDQueueNode* new_node = (TriloDQueueNode*)malloc(sizeof(TriloDQueueNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = deque->front;

    if (deque->front == NULL) {
        deque->front = new_node;
        deque->rear = new_node;
    } else {
        deque->front->prev = new_node;
        deque->front = new_node;
    } // end if else
} // end of func

void trilo_xdata_dqueue_push_rear(TriloDQueue* deque, TriloTofu data) {
    // Ensure the data type matches the deque type
    if (data.type != deque->deque_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloDQueueNode* new_node = (TriloDQueueNode*)malloc(sizeof(TriloDQueueNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    new_node->data = data;
    new_node->prev = deque->rear;
    new_node->next = NULL;

    if (deque->rear == NULL) {
        deque->front = new_node;
        deque->rear = new_node;
    } else {
        deque->rear->next = new_node;
        deque->rear = new_node;
    } // end if else
} // end of func

void trilo_xdata_dqueue_pop_front(TriloDQueue* deque) {
    if (deque->front == NULL) {
        fprintf(stderr, "Deque is empty!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloDQueueNode* front = deque->front;
    deque->front = front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    } // end if else
    free(front);
} // end of func

void trilo_xdata_dqueue_pop_rear(TriloDQueue* deque) {
    if (deque->rear == NULL) {
        fprintf(stderr, "Deque is empty!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloDQueueNode* rear = deque->rear;
    deque->rear = rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    } // end if else
    free(rear);
} // end of func

TriloTofu trilo_xdata_dqueue_front(const TriloDQueue* deque) {
    if (deque->front == NULL) {
        fprintf(stderr, "Deque is empty!\n");
        exit(EXIT_FAILURE);
    } // end if
    return deque->front->data;
} // end of func

TriloTofu trilo_xdata_dqueue_rear(const TriloDQueue* deque) {
    if (deque->rear == NULL) {
        fprintf(stderr, "Deque is empty!\n");
        exit(EXIT_FAILURE);
    } // end if
    return deque->rear->data;
} // end of func

void trilo_xdata_dqueue_print_forward(const TriloDQueue* deque) {
    TriloDQueueNode* current = deque->front;
    while (current != NULL) {
        switch (deque->deque_type) {
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

void trilo_xdata_dqueue_print_backward(const TriloDQueue* deque) {
    TriloDQueueNode* current = deque->rear;
    while (current != NULL) {
        switch (deque->deque_type) {
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
        current = current->prev;
    } // end while
    printf("NULL\n");
} // end of func
