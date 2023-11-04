/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TRILOBITE_XDATA_TOFU_H
#define TRILOBITE_XDATA_TOFU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Once upon a time in a small village nestled between rolling green hills,
    there lived a young woman named Mei. Mei was known throughout the village
    for her exceptional cooking skills, particularly when it came to tofu.
    Tofu was a staple in their community, and everyone eagerly awaited Mei's
    tofu dishes.

    Mei's fascination with tofu began when she was a child. Her grandmother,
    a wise and experienced cook, taught her the art of transforming this simple
    soybean product into a delectable masterpiece. From creamy tofu soups to
    crispy tofu stir-fries, Mei's dishes were nothing short of magic.

    One sunny morning, Mei received news that the annual cooking competition was
    just around the corner. The villagers encouraged her to participate, believing
    she had a good chance of winning. Mei, however, was hesitant. She had always
    cooked for the love of it, not for prizes or recognition.

    As the days passed, Mei couldn't shake the idea of the competition. She
    decided that it could be an opportunity to showcase the beauty of tofu to
    a wider audience. But she wanted to do it her way, infusing her dishes
    with love, tradition, and creativity.

    Mei spent weeks experimenting with tofu recipes. She combined traditional
    flavors with exotic spices, creating dishes that were as visually stunning
    as they were delicious. Her tofu stir-fry featured colorful bell peppers,
    crisp snow peas, and a tantalizing ginger sauce. Her tofu dessert was a
    sweet surprise, blending silken tofu with honey and fresh fruit.

    The day of the competition finally arrived. Mei's heart raced as she stood
    in the bustling village square, surrounded by other talented cooks. As she
    presented her dishes to the judges, she poured her heart and soul into every
    plate. She shared the stories behind her recipes, explaining how tofu was a
    symbol of the village's unity and resilience.

    The judges were captivated by Mei's passion and her inventive tofu creations.
    They tasted her dishes, and their faces lit up with delight. The crowd couldn't
    help but cheer as they watched the judges savor Mei's culinary masterpieces.

    When the winners were announced, Mei was overwhelmed with emotion. She had won
    not only first place but also the hearts of everyone in the village. The victory
    was not just hers; it was a celebration of the rich culture and traditions that
    centered around tofu.

    From that day on, Mei's tofu dishes became famous far and wide. People traveled
    from distant lands to taste her creations, and the village flourished as a
    result. But for Mei, the greatest reward was knowing that she had shared the
    magic of tofu with the world and, in doing so, brought her community closer
    together.

    And so, in that small village among the rolling green hills, tofu was no longer
    just a humble ingredient. It was a symbol of Mei's love, creativity, and the
    power of sharing one's passion with the world.
*/

#include <stdbool.h> // Include the header for bool data type
#include <stddef.h>

// Define error constants for tofu operations
typedef enum {
    TRILO_XDATA_TYPE_SUCCESS        = 0,
    TRILO_XDATA_TYPE_WAS_MISMATCH   = -1,
    TRILO_XDATA_TYPE_WAS_BAD_RANGE  = -2,
    TRILO_XDATA_TYPE_WAS_NULLPTR    = -3,
    TRILO_XDATA_TYPE_WAS_BAD_MALLOC = -4,
    TRILO_XDATA_TYPE_WAS_UNKNOWN    = -5
} TofuError;

//
// Generic and secure flavorless data type.
//
enum DataType {
    INTEGER_TYPE,
    DOUBLE_TYPE,
    STRING_TYPE,
    CHAR_TYPE,
    BOOLEAN_TYPE,
    UNKNOWN_TYPE
};

//
// Define a union to hold data of different types
//
typedef union {
    int integer_type;
    double double_type;
    char string_type[50];
    char char_type;
    bool boolean_type;
} TriloTofuData;

//
// Define a struct to represent the data and its type
//
typedef struct {
    enum DataType type;
    TriloTofuData data;
} TriloTofu;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloTofu instance from an integer value.
 *
 * @param value The integer value to create the TriloTofu instance from.
 * @return A TriloTofu instance containing the integer value.
 */
TriloTofu trilo_xdata_tofu_create_from_integer(int value);

/**
 * @brief Creates a new TriloTofu instance from a double value.
 *
 * @param value The double value to create the TriloTofu instance from.
 * @return A TriloTofu instance containing the double value.
 */
TriloTofu trilo_xdata_tofu_create_from_double(double value);

/**
 * @brief Creates a new TriloTofu instance from a string value.
 *
 * @param value The string value to create the TriloTofu instance from.
 * @return A TriloTofu instance containing the string value.
 */
TriloTofu trilo_xdata_tofu_create_from_string(const char* value);

/**
 * @brief Creates a new TriloTofu instance from a character value.
 *
 * @param value The character value to create the TriloTofu instance from.
 * @return A TriloTofu instance containing the character value.
 */
TriloTofu trilo_xdata_tofu_create_from_char(char value);

/**
 * @brief Creates a new TriloTofu instance from a boolean value.
 *
 * @param value The boolean value to create the TriloTofu instance from.
 * @return A TriloTofu instance containing the boolean value.
 */
TriloTofu trilo_xdata_tofu_create_from_boolean(bool value);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Compares two TriloTofu instances and returns the result.
 *
 * @param a The first TriloTofu instance for comparison.
 * @param b The second TriloTofu instance for comparison.
 * @return A TofuError value indicating the comparison result.
 */
TofuError trilo_xdata_tofu_compare(const TriloTofu a, const TriloTofu b);

/**
 * @brief Sorts an array of TriloTofu instances using the insertion sort algorithm.
 *
 * @param arr The array of TriloTofu instances to be sorted.
 * @param n   The number of elements in the array.
 */
void trilo_xdata_tofu_insertion_sort(TriloTofu* arr, size_t n);

/**
 * @brief Sorts an array of TriloTofu instances using the selection sort algorithm.
 *
 * @param arr The array of TriloTofu instances to be sorted.
 * @param n   The number of elements in the array.
 */
void trilo_xdata_tofu_selection_sort(TriloTofu* arr, size_t n);

/**
 * @brief Searches for a target TriloTofu instance in a sorted array using binary search.
 *
 * @param arr    The sorted array of TriloTofu instances.
 * @param n      The number of elements in the array.
 * @param target The TriloTofu instance to search for.
 * @return       The index of the target if found, or -1 if not found.
 */
int trilo_xdata_tofu_binary_search(const TriloTofu* arr, size_t n, TriloTofu target);

/**
 * @brief Searches for a target TriloTofu instance in an array using linear search.
 *
 * @param arr    The array of TriloTofu instances.
 * @param n      The number of elements in the array.
 * @param target The TriloTofu instance to search for.
 * @return       The index of the target if found, or -1 if not found.
 */
int trilo_xdata_tofu_linear_search(const TriloTofu* arr, size_t n, TriloTofu target);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Prints the data in a TriloTofu instance.
 *
 * @param tofu The TriloTofu instance to be printed.
 */
void trilo_xdata_tofu_print(TriloTofu tofu);

/**
 * @brief Gets the integer data from a TriloTofu instance.
 *
 * @param tofu The TriloTofu instance to extract the integer data from.
 * @return     The integer value from the TriloTofu instance.
 */
int trilo_xdata_tofu_get_integer(TriloTofu tofu);

/**
 * @brief Gets the double data from a TriloTofu instance.
 *
 * @param tofu The TriloTofu instance to extract the double data from.
 * @return     The double value from the TriloTofu instance.
 */
double trilo_xdata_tofu_get_double(TriloTofu tofu);

/**
 * @brief Gets the string data from a TriloTofu instance.
 *
 * @param tofu The TriloTofu instance to extract the string data from.
 * @return     A pointer to the string data in the TriloTofu instance.
 */
const char* trilo_xdata_tofu_get_string(TriloTofu tofu);

/**
 * @brief Gets the character data from a TriloTofu instance.
 *
 * @param tofu The TriloTofu instance to extract the character data from.
 * @return     The character value from the TriloTofu instance.
 */
char trilo_xdata_tofu_get_char(TriloTofu tofu);

/**
 * @brief Gets the boolean data from a TriloTofu instance.
 *
 * @param tofu The TriloTofu instance to extract the boolean data from.
 * @return     The boolean value from the TriloTofu instance.
 */
bool trilo_xdata_tofu_get_boolean(TriloTofu tofu);

/**
 * @brief Creates a copy of a TriloTofu instance.
 *
 * This function creates a new TriloTofu instance that is a deep copy of the
 * provided source TriloTofu. The copy includes both the data type and data
 * content, ensuring that any modifications to the copy do not affect the
 * original source.
 *
 * @param tofu The source TriloTofu instance to be copied.
 * @return A new TriloTofu instance that is a copy of the source.
 */
TriloTofu trilo_xdata_tofu_copy(TriloTofu tofu);

/**
 * @brief Checks if two TriloTofu instances are equal.
 *
 * @param a The first TriloTofu instance for comparison.
 * @param b The second TriloTofu instance for comparison.
 * @return true if the instances are equal, false otherwise.
 */
bool trilo_xdata_tofu_equal(const TriloTofu a, const TriloTofu b);

/**
 * @brief Gets the data type of a TriloTofu instance.
 *
 * This function returns the data type of the provided TriloTofu instance.
 *
 * @param tofu The TriloTofu instance to get the data type from.
 * @return The data type of the TriloTofu instance.
 */
enum DataType trilo_xdata_tofu_get_type(const TriloTofu tofu);

#ifdef __cplusplus
}
#endif

#endif
