
#include "trilobite/xdata/tuple.h"
#include <stdio.h>

int main() {
    // Define the data types for each element of the tuple
    enum DataType tupleTypes[] = {INTEGER_TYPE, DOUBLE_TYPE, STRING_TYPE, CHAR_TYPE, BOOLEAN_TYPE};
    size_t tupleSize = sizeof(tupleTypes) / sizeof(tupleTypes[0]);

    // Create a tuple with the specified data types
    TriloTuple* tuple = trilo_xdata_tuple_create(tupleTypes, tupleSize);

    // Insert values into the tuple
    trilo_xdata_tuple_set(tuple, 0, trilo_xdata_tofu_create_from_integer(42));
    trilo_xdata_tuple_set(tuple, 1, trilo_xdata_tofu_create_from_double(3.14159));
    trilo_xdata_tuple_set(tuple, 2, trilo_xdata_tofu_create_from_string("Hello, World!"));
    trilo_xdata_tuple_set(tuple, 3, trilo_xdata_tofu_create_from_char('A'));
    trilo_xdata_tuple_set(tuple, 4, trilo_xdata_tofu_create_from_boolean(true));

    // Print the contents of the tuple
    printf("Tuple contents:\n");
    for (size_t i = 0; i < tupleSize; i++) {
        printf("Element %zu (Type: %d): ", i, tupleTypes[i]);
        TriloTofu element = trilo_xdata_tuple_get(tuple, i);

        switch (element.type) {
            case INTEGER_TYPE:
                printf("%d\n", trilo_xdata_tofu_get_integer(element));
                break;
            case DOUBLE_TYPE:
                printf("%lf\n", trilo_xdata_tofu_get_double(element));
                break;
            case STRING_TYPE:
                printf("%s\n", trilo_xdata_tofu_get_string(element));
                break;
            case CHAR_TYPE:
                printf("%c\n", trilo_xdata_tofu_get_char(element));
                break;
            case BOOLEAN_TYPE:
                printf("%s\n", trilo_xdata_tofu_get_boolean(element) ? "true" : "false");
                break;
            default:
                printf("Unknown type\n");
                break;
        }
    }

    // Clean up and destroy the tuple
    trilo_xdata_tuple_destroy(tuple);

    return 0;
} // end of func
