
#include "trilobite/xdata/flist.h"
#include <stdio.h>

int main() {
    // Create a singly linked list for integers
    TriloForwardList* intList = trilo_xdata_flist_create(INTEGER_TYPE);

    // Insert some integer values
    trilo_xdata_flist_insert(intList, trilo_xdata_tofu_create_from_integer(42));
    trilo_xdata_flist_insert(intList, trilo_xdata_tofu_create_from_integer(123));
    trilo_xdata_flist_insert(intList, trilo_xdata_tofu_create_from_integer(7));

    // Print the list
    printf("List of Integers:\n");
    trilo_xdata_flist_print(intList);

    // Remove an element
    trilo_xdata_flist_remove(intList, trilo_xdata_tofu_create_from_integer(123));

    // Print the updated list
    printf("Updated List of Integers:\n");
    trilo_xdata_flist_print(intList);

    // Reverse the list
    trilo_xdata_flist_reverse(intList);

    // Print the reversed list
    printf("Reversed List of Integers:\n");
    trilo_xdata_flist_print(intList);

    // Destroy the list and free memory
    trilo_xdata_flist_destroy(intList);

    return 0;
} // end of func

