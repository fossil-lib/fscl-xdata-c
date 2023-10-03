/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tlist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

TriloTernaryListNode* trilo_xdata_tlist_node_create(TriloTofu data) {
    TriloTernaryListNode* node = (TriloTernaryListNode*)malloc(sizeof(TriloTernaryListNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    node->middle = NULL;
    return node;
} // end of func

TriloTernaryList* trilo_xdata_tlist_create() {
    TriloTernaryList* tlist = (TriloTernaryList*)malloc(sizeof(TriloTernaryList));
    if (tlist == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    tlist->head = NULL;
    return tlist;
} // end of func

void trilo_xdata_tlist_destroy(TriloTernaryList* tlist) {
    TriloTernaryListNode* current = tlist->head;
    while (current != NULL) {
        TriloTernaryListNode* temp = current;
        current = current->next;
        free(temp);
    } // end while
    free(tlist);
} // end of func

void trilo_xdata_tlist_insert(TriloTernaryList* tlist, TriloTofu data) {
    TriloTernaryListNode* newNode = trilo_xdata_tlist_node_create(data);
    if (tlist->head == NULL) {
        tlist->head = newNode;
    } else {
        TriloTernaryListNode* current = tlist->head;
        while (current->next != NULL) {
            current = current->next;
        } // end while
        current->next = newNode;
        newNode->prev = current;
    } // end if else
} // end of func

void trilo_xdata_tlist_remove(TriloTernaryList* tlist, TriloTofu data) {
    TriloTernaryListNode* current = tlist->head;
    while (current != NULL) {
        if (current->data.type == data.type) {
            if (current->data.type == INTEGER_TYPE && current->data.data.integer_type == data.data.integer_type) {
                TriloTernaryListNode* temp = current;
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    tlist->head = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(temp);
            } else if (current->data.type == DOUBLE_TYPE && current->data.data.double_type == data.data.double_type) {
                TriloTernaryListNode* temp = current;
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    tlist->head = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(temp);
            } else if (current->data.type == STRING_TYPE && strcmp(current->data.data.string_type, data.data.string_type) == 0) {
                TriloTernaryListNode* temp = current;
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    tlist->head = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(temp);
            } else if (current->data.type == CHAR_TYPE && current->data.data.char_type == data.data.char_type) {
                TriloTernaryListNode* temp = current;
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    tlist->head = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(temp);
            } else if (current->data.type == BOOLEAN_TYPE && current->data.data.boolean_type == data.data.boolean_type) {
                TriloTernaryListNode* temp = current;
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    tlist->head = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(temp);
            } // end if esle if's
        } // end if 
        current = current->next;
    } // end while
} // end of func

bool trilo_xdata_tlist_search(const TriloTernaryList* tlist, TriloTofu data) {
    TriloTernaryListNode* current = tlist->head;
    while (current != NULL) {
        if (current->data.type == data.type) {
            if (current->data.type == INTEGER_TYPE && current->data.data.integer_type == data.data.integer_type) {
                return true;
            } else if (current->data.type == DOUBLE_TYPE && current->data.data.double_type == data.data.double_type) {
                return true;
            } else if (current->data.type == STRING_TYPE && strcmp(current->data.data.string_type, data.data.string_type) == 0) {
                return true;
            } else if (current->data.type == CHAR_TYPE && current->data.data.char_type == data.data.char_type) {
                return true;
            } else if (current->data.type == BOOLEAN_TYPE && current->data.data.boolean_type == data.data.boolean_type) {
                return true;
            } // end if else's
        } // end if
        current = current->next;
    } // end while
    return false;
} // end of func

void trilo_xdata_tlist_print(const TriloTernaryList* tlist) {
    TriloTernaryListNode* current = tlist->head;
    while (current != NULL) {
        printf("Data: ");
        switch (current->data.type) {
            case INTEGER_TYPE:
                printf("%d\n", current->data.data.integer_type);
                break;
            case DOUBLE_TYPE:
                printf("%lf\n", current->data.data.double_type);
                break;
            case STRING_TYPE:
                printf("%s\n", current->data.data.string_type);
                break;
            case CHAR_TYPE:
                printf("%c\n", current->data.data.char_type);
                break;
            case BOOLEAN_TYPE:
                printf("%s\n", current->data.data.boolean_type ? "true" : "false");
                break;
            default:
                printf("Unknown type\n");
                break;
        } // end switch
        current = current->next;
    } // end while
} // end of func
