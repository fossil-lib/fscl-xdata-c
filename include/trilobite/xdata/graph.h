/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_GRAPH_H
#define TRILOBITE_XDATA_GRAPH_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_GRAPH_TYPE_MISMATCH = -1,
    TRILO_XDATA_GRAPH_OUT_OF_RANGE  = -2
};

// Node structure for the graph
typedef struct TriloGraphNode {
    char* key;
    TriloTofu data;
    struct TriloGraphEdge* edges; // Adjacency list of edges
    struct TriloGraphNode* next; // Next node in the graph
} TriloGraphNode;

// Edge structure for the graph
typedef struct TriloGraphEdge {
    struct TriloGraphNode* destination;
    struct TriloGraphEdge* next;
} TriloGraphEdge;

// Graph structure
typedef struct TriloGraph {
    TriloGraphNode* nodes;
    enum DataType graph_type; // Type of the graph
} TriloGraph;

// Function to create a new TriloGraph
TriloGraph* trilo_xdata_graph_create(enum DataType graph_type);

// Function to destroy the TriloGraph
void trilo_xdata_graph_destroy(TriloGraph* graph);

// Function to insert a TriloTofu data into the graph as a node
void trilo_xdata_graph_insert_node(TriloGraph* graph, const char* key, TriloTofu data);

// Function to remove a node and its associated edges from the graph
void trilo_xdata_graph_remove_node(TriloGraph* graph, const char* key);

// Function to insert an edge between two nodes in the graph
void trilo_xdata_graph_insert_edge(TriloGraph* graph, const char* from_key, const char* to_key);

// Function to remove an edge between two nodes in the graph
void trilo_xdata_graph_remove_edge(TriloGraph* graph, const char* from_key, const char* to_key);

// Function to check if a node exists in the graph
bool trilo_xdata_graph_contains_node(TriloGraph* graph, const char* key);

// Function to check if an edge exists between two nodes in the graph
bool trilo_xdata_graph_contains_edge(TriloGraph* graph, const char* from_key, const char* to_key);

// Function to print the nodes and edges in the graph
void trilo_xdata_graph_print(TriloGraph* graph);

#ifdef __cplusplus
}
#endif

#endif
