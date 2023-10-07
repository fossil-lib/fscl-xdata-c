
#include "trilobite/xdata/graph.h"
#include <stdio.h>

int main() {
    // Create a graph
    TriloGraph* graph = trilo_xdata_graph_create();

    // Add vertices to the graph
    trilo_xdata_graph_add_vertex(graph, trilo_xdata_tofu_create_from_string("A"));
    trilo_xdata_graph_add_vertex(graph, trilo_xdata_tofu_create_from_string("B"));
    trilo_xdata_graph_add_vertex(graph, trilo_xdata_tofu_create_from_string("C"));
    trilo_xdata_graph_add_vertex(graph, trilo_xdata_tofu_create_from_string("D"));

    // Add edges to the graph
    trilo_xdata_graph_add_edge(graph, trilo_xdata_tofu_create_from_string("A"), trilo_xdata_tofu_create_from_string("B"));
    trilo_xdata_graph_add_edge(graph, trilo_xdata_tofu_create_from_string("A"), trilo_xdata_tofu_create_from_string("C"));
    trilo_xdata_graph_add_edge(graph, trilo_xdata_tofu_create_from_string("B"), trilo_xdata_tofu_create_from_string("D"));
    trilo_xdata_graph_add_edge(graph, trilo_xdata_tofu_create_from_string("C"), trilo_xdata_tofu_create_from_string("D"));

    // Check if vertices and edges exist in the graph
    if (trilo_xdata_graph_has_vertex(graph, trilo_xdata_tofu_create_from_string("A"))) {
        printf("Vertex 'A' exists in the graph.\n");
    } else {
        printf("Vertex 'A' does not exist in the graph.\n");
    }

    if (trilo_xdata_graph_has_edge(graph, trilo_xdata_tofu_create_from_string("B"), trilo_xdata_tofu_create_from_string("C"))) {
        printf("Edge from 'B' to 'C' exists in the graph.\n");
    } else {
        printf("Edge from 'B' to 'C' does not exist in the graph.\n");
    }

    // Print the graph
    printf("Graph contents:\n");
    trilo_xdata_graph_print(graph);

    // Clean up and destroy the graph
    trilo_xdata_graph_destroy(graph);

    return 0;
} // end of func
