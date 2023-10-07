/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/graph.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestGraphData) {
    TriloGraph *graph;
}graph_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_graph_of_int_create_and_destroy) {
    // Test creating and destroying a TriloGraph
    graph_data.graph = trilo_xdata_graph_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(graph_data.graph);
    XASSERT_INT_EQUAL(INTEGER_TYPE, graph_data.graph->graph_type);
    trilo_xdata_graph_destroy(graph_data.graph);
}

XTEST_CASE(xdata_let_graph_of_int_add_vertex_and_get_vertices) {
    // Test adding vertices to the TriloGraph and getting vertices
    graph_data.graph = trilo_xdata_graph_create(INTEGER_TYPE);

    TriloTofu vertex1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu vertex2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu vertex3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_graph_add_vertex(graph_data.graph, vertex1);
    trilo_xdata_graph_add_vertex(graph_data.graph, vertex2);
    trilo_xdata_graph_add_vertex(graph_data.graph, vertex3);

    TriloTofu* vertices = NULL;
    int num_vertices = trilo_xdata_graph_get_vertices(graph_data.graph, &vertices);

    XASSERT_INT_EQUAL(3, num_vertices);

    // Check the values of the vertices
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(vertices[0]));
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(vertices[1]));
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(vertices[2]));

    // Clean up allocated memory for vertices
    free(vertices);
    
    trilo_xdata_graph_destroy(graph_data.graph);
}

XTEST_CASE(xdata_let_graph_of_int_add_edge_and_get_edges) {
    // Test adding edges to the TriloGraph and getting edges
    graph_data.graph = trilo_xdata_graph_create(INTEGER_TYPE);

    TriloTofu vertex1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu vertex2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu vertex3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_graph_add_vertex(graph_data.graph, vertex1);
    trilo_xdata_graph_add_vertex(graph_data.graph, vertex2);
    trilo_xdata_graph_add_vertex(graph_data.graph, vertex3);

    trilo_xdata_graph_add_edge(graph_data.graph, vertex1, vertex2);
    trilo_xdata_graph_add_edge(graph_data.graph, vertex2, vertex3);

    TriloTofu* edges = NULL;
    int num_edges = trilo_xdata_graph_get_edges(graph_data.graph, &edges);

    XASSERT_INT_EQUAL(2, num_edges);

    // Check the values of the edges
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(edges[0]));
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(edges[1]));

    // Clean up allocated memory for edges
    free(edges);
    
    trilo_xdata_graph_destroy(graph_data.graph);
}

XTEST_CASE(xdata_let_graph_of_int_type_mismatch) {
    // Test adding edges with different vertex types to the TriloGraph
    graph_data.graph = trilo_xdata_graph_create(INTEGER_TYPE);

    TriloTofu vertex1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu vertex2 = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to add an edge with a different vertex type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_GRAPH_TYPE_MISMATCH, trilo_xdata_graph_add_edge(graph_data.graph, vertex1, vertex2));

    trilo_xdata_graph_destroy(graph_data.graph);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_graph_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for graph:");

    XTEST_RUN_UNIT(xdata_let_graph_of_int_create_and_destroy,          runner);
    XTEST_RUN_UNIT(xdata_let_graph_of_int_add_vertex_and_get_vertices, runner);
    XTEST_RUN_UNIT(xdata_let_graph_of_int_add_edge_and_get_edges,      runner);
    XTEST_RUN_UNIT(xdata_let_graph_of_int_type_mismatch,               runner);
} // end of func
