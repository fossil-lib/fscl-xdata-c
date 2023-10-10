# Trilobite Data structures - C

The TriloXData library is a versatile and efficient collection of data structures and algorithms designed to handle a wide range of data types and operations. It provides a robust foundation for managing and manipulating data in various applications, with a focus on ease of use, reliability, and performance.

## Intended Audience

This guide is aimed at developers of all levels who wish to utilize the Meson build system for their projects. It assumes a basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before you proceed, ensure you have the following prerequisites installed:

- **Meson Build System**: The project relies on the Meson build system. If you do not have Meson installed, please visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for instructions on how to install it.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions provided on the [Meson website](https://mesonbuild.com/Getting-meson.html) based on your operating system.

## Example

Example of the usage in C

```c
/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include <stdio.h>
#include <trilobite/xdata/dlist.h> // using doubly linked list
#include <trilobite/xdata/tofu.h>  // using tofu data type

// Function to print the shopping list
void print_shopping_list(const TriloDoublyList* shoppingList) {
    if (trilo_xdata_dlist_is_empty(shoppingList)) {
        printf("Your shopping list is empty.\n");
        return;
    } // end if

    printf("Eco-Friendly Shopping List:\n");
    TriloDoublyListNode* current = shoppingList->head;
    while (current != NULL) {
        TriloTofu* item = &current->data;
        printf("- %s\n", trilo_xdata_tofu_get_string(*item));
        current = current->next;
    } // end while
} // end of func

//
// main is where all good examples start
//
int main() {
    TriloDoublyList* shopping_list = trilo_xdata_dlist_create(STRING_TYPE);

    // Add eco-friendly items to the shopping list
    for (int i = 0; i < 5; i++) {
        char item_name[50];
        printf("Enter an eco-friendly item for your shopping list (or 'exit' to finish): ");
        scanf("%s", item_name);

        if (strcmp(item_name, "exit") == 0) {
            break;
        } // end if

        TriloTofu item = trilo_xdata_tofu_create_from_string(item_name);
        trilo_xdata_dlist_insert(shopping_list, item);
    } // end for

    // Print the shopping list
    print_shopping_list(shopping_list);

    // Clean up memory
    trilo_xdata_dlist_destroy(shopping_list);

    return 0;
} // end of func
```

## Contributing

If you're interested in contributing to this project, please consider opening pull requests or raising issues on the [GitHub repository](https://github.com/trilobite-stdlib/trilo-xdata-c) and be sure to read the docs on the owners' [website](https://trilobite.code.blog).

## Feedback and Support

If you come across any issues, have questions, or would like to provide feedback, feel free to open an issue on the [GitHub repository](https://github.com/trilobite-stdlib/trilo-xdata-c/issues).

## License

This project is licensed under the [Apache License 2.0](LICENSE).

---

Thank you for choosing this project with the Meson build system. Enjoy coding and building great projects!

## contact

* * *

If you want to contact me and have a few questions
regarding the solutions in the programming you can
find a method on my [website](https://trilobite.code.blog/contact/).
