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
#include <stdlib.h>
#include <string.h>

// Sample data with strings
ctofu_data data_array[] = {
    {STRING_TYPE, .string_type = "Banana"},
    {STRING_TYPE, .string_type = "Apple"},
    {STRING_TYPE, .string_type = "Orange"},
    {STRING_TYPE, .string_type = "Grapes"},
    {STRING_TYPE, .string_type = "Pineapple"}
};

int main() {
    // Create an array of ctofu
    ctofu* array = NULL;
    ctofu_error create_result = tscl_tofu_create(ARRAY_TYPE, data_array, &array);

    if (create_result == TOFU_SUCCESS) {
        // Sort the array using selection sort (you can replace it with other sorting functions)
        tscl_tofu_sort_selection(array->data.array_type.elements, array->data.array_type.size);

        // Print the sorted array
        printf("Sorted Array:\n");
        for (size_t i = 0; i < array->data.array_type.size; ++i) {
            ctofu_data current_data = tscl_tofu_value_getter(array[i].data.array_type.elements);
            if (array[i].type == STRING_TYPE) {
                printf("%s\n", current_data.string_type);
            }
        }

        // Clean up
        tscl_tofu_erase(array);
    } else {
        printf("Failed to create ctofu array.\n");
    }

    return 0;
}
