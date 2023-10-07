
#include "trilobite/xdata/vector.h"
#include <stdio.h>

int main() {
    // Create a vector of integers
    TriloVector* intVector = trilo_xdata_vector_create(INTEGER_TYPE);

    // Insert some values into the vector
    for (int i = 1; i <= 5; i++) {
        int value = i * 10;
        trilo_xdata_vector_push_back(intVector, trilo_xdata_tofu_create_from_integer(value));
    }

    // Print the elements of the vector
    printf("Vector elements: ");
    for (size_t i = 0; i < trilo_xdata_vector_size(intVector); i++) {
        int value = trilo_xdata_tofu_get_integer(trilo_xdata_vector_get(intVector, i));
        printf("%d ", value);
    }
    printf("\n");

    // Remove the last element
    trilo_xdata_vector_pop_back(intVector);

    // Print the elements after removal
    printf("Vector elements after removal: ");
    for (size_t i = 0; i < trilo_xdata_vector_size(intVector); i++) {
        int value = trilo_xdata_tofu_get_integer(trilo_xdata_vector_get(intVector, i));
        printf("%d ", value);
    }
    printf("\n");

    // Clean up and destroy the vector
    trilo_xdata_vector_destroy(intVector);

    return 0;
} // end of func

