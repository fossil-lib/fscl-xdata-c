/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloGraphNode* trilo_xdata_graph_node_create(const char* key, TriloTofu data) {
    TriloGraphNode* node = (TriloGraphNode*)malloc(sizeof(TriloGraphNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    strcpy(node->key, key); // Copy the key
    node->data = data;
    node->edges = NULL;
    node->next = NULL;
    return node;
} // end of func

TriloGraph* trilo_xdata_graph_create(enum DataType graph_type) {
    TriloGraph* graph = (TriloGraph*)malloc(sizeof(TriloGraph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    graph->nodes = NULL;
    graph->graph_type = graph_type;
    return graph;
} // end of func

void trilo_xdata_graph_destroy(TriloGraph* graph) {
    while (graph->nodes != NULL) {
        TriloGraphNode* current = graph->nodes;
        graph->nodes = graph->nodes->next;
        free(current->key);
        free(current);
    } // end while
    free(graph);
} // end of func

TriloGraphNode* trilo_xdata_graph_find_node(TriloGraph* graph, const char* key) {
    TriloGraphNode* current = graph->nodes;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        } // end if
        current = current->next;
    } // end while
    return NULL;
} // end of func

void trilo_xdata_graph_insert_node(TriloGraph* graph, const char* key, TriloTofu data) {
    // Ensure the data type matches the graph type
    if (data.type != graph->graph_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    if (trilo_xdata_graph_find_node(graph, key) != NULL) {
        fprintf(stderr, "Node with the same key already exists!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloGraphNode* newNode = trilo_xdata_graph_node_create(key, data);
    newNode->next = graph->nodes;
    graph->nodes = newNode;
} // end of func

void trilo_xdata_graph_remove_node(TriloGraph* graph, const char* key) {
    TriloGraphNode* current = graph->nodes;
    TriloGraphNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Remove edges pointing to this node
            TriloGraphNode* node = graph->nodes;
            while (node != NULL) {
                trilo_xdata_graph_remove_edge(graph, node->key, key);
                node = node->next;
            } // end while

            if (prev == NULL) {
                // The node to remove is the first node in the list
                graph->nodes = current->next;
            } else {
                prev->next = current->next;
            } // end if else

            free(current->key);
            free(current);
            return;
        } // end if
        prev = current;
        current = current->next;
    } // end while
} // end of func

void trilo_xdata_graph_insert_edge(TriloGraph* graph, const char* from_key, const char* to_key) {
    TriloGraphNode* from_node = trilo_xdata_graph_find_node(graph, from_key);
    TriloGraphNode* to_node = trilo_xdata_graph_find_node(graph, to_key);

    if (from_node == NULL || to_node == NULL) {
        fprintf(stderr, "Nodes not found for edge insertion!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloGraphEdge* newEdge = (TriloGraphEdge*)malloc(sizeof(TriloGraphEdge));
    if (newEdge == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    newEdge->destination = to_node;
    newEdge->next = from_node->edges;
    from_node->edges = newEdge;
} // end of func

void trilo_xdata_graph_remove_edge(TriloGraph* graph, const char* from_key, const char* to_key) {
    TriloGraphNode* from_node = trilo_xdata_graph_find_node(graph, from_key);
    if (from_node == NULL) {
        fprintf(stderr, "From node not found for edge removal!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloGraphEdge* current = from_node->edges;
    TriloGraphEdge* prev = NULL;

    while (current != NULL) {
        if (current->destination != NULL && strcmp(current->destination->key, to_key) == 0) {
            if (prev == NULL) {
                // The edge to remove is the first edge in the list
                from_node->edges = current->next;
            } else {
                prev->next = current->next;
            } // end if else
            free(current);
            return;
        } // end if
        prev = current;
        current = current->next;
    } // end while
} // end of func

bool trilo_xdata_graph_contains_node(TriloGraph* graph, const char* key) {
    return trilo_xdata_graph_find_node(graph, key) != NULL;
} // end of func

bool trilo_xdata_graph_contains_edge(TriloGraph* graph, const char* from_key, const char* to_key) {
    TriloGraphNode* from_node = trilo_xdata_graph_find_node(graph, from_key);
    if (from_node == NULL) {
        return false;
    } // end if

    TriloGraphEdge* current = from_node->edges;

    while (current != NULL) {
        if (current->destination != NULL && strcmp(current->destination->key, to_key) == 0) {
            return true;
        } // end if
        current = current->next;
    } // end while

    return false;
} // end of func

void trilo_xdata_graph_print(TriloGraph* graph) {
    TriloGraphNode* current = graph->nodes;
    while (current != NULL) {
        printf("Node: %s\n", current->key);
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

        printf("Edges: ");
        TriloGraphEdge* edge = current->edges;
        while (edge != NULL) {
            printf("%s -> ", edge->destination->key);
            edge = edge->next;
        } // end while
        printf("NULL\n");

        current = current->next;
    } // end while
} // end of func
