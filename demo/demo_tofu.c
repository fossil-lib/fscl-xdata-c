/*  ----------------------------------------------------------------------------
    File: demo_tofu.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xdata/tofu.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Create ctofu instances from different data types
    ctofu intTofu = trilo_xdata_tofu_create_from_integer(42);
    ctofu doubleTofu = trilo_xdata_tofu_create_from_double(3.14159);
    ctofu stringTofu = trilo_xdata_tofu_create_from_string("Hello, World!");
    ctofu charTofu = trilo_xdata_tofu_create_from_char('A');
    ctofu boolTofu = trilo_xdata_tofu_create_from_boolean(true);

    // Print the data stored in each ctofu instance
    printf("Integer Value: %d\n", trilo_xdata_tofu_get_integer(intTofu));
    printf("Double Value: %lf\n", trilo_xdata_tofu_get_double(doubleTofu));
    printf("String Value: %s\n", trilo_xdata_tofu_get_string(stringTofu));
    printf("Character Value: %c\n", trilo_xdata_tofu_get_char(charTofu));
    printf("Boolean Value: %s\n", trilo_xdata_tofu_get_boolean(boolTofu) ? "true" : "false");

    // Create an array of ctofu instances and perform sorting and searching
    ctofu arr[] = {intTofu, doubleTofu, stringTofu, charTofu, boolTofu};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using insertion sort
    trilo_xdata_tofu_insertion_sort(arr, arrSize);

    // Print the sorted array
    printf("\nSorted Array:\n");
    for (size_t i = 0; i < arrSize; i++) {
        trilo_xdata_tofu_print(arr[i]);
    } // end for

    // Perform a binary search for a specific ctofu instance
    ctofu targetTofu = trilo_xdata_tofu_create_from_double(3.14159);
    int result = trilo_xdata_tofu_binary_search(arr, arrSize, targetTofu);
    if (result != -1) {
        printf("\nTarget Value Found at Index: %d\n", result);
    } else {
        printf("\nTarget Value Not Found\n");
    } // end if else

    return 0;
} // end of func
