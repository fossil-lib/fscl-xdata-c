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
#ifndef TSCL_TOFU_H
#define TSCL_TOFU_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

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

#include <stddef.h>

// Define error constants for tofu operations
typedef enum {
    TOFU_SUCCESS        = 0,
    TOFU_WAS_MISMATCH   = -1,
    TOFU_WAS_BAD_RANGE  = -2,
    TOFU_WAS_NULLPTR    = -3,
    TOFU_WAS_BAD_MALLOC = -4,
    TOFU_WAS_UNKNOWN    = -5,
    TOFU_NOT_FOUND      = -6
} ctofu_error;

// Generic and secure flavorless data type.
typedef enum {
    INTEGER_TYPE,
    DOUBLE_TYPE,
    STRING_TYPE,
    CHAR_TYPE,
    BOOLEAN_TYPE,
    ARRAY_TYPE,
    NULLPTR_TYPE,
    INVALID_TYPE,
    UNKNOWN_TYPE
} ctofu_type;

// Define a union to hold data of different types
typedef union {
    int integer_type;
    double double_type;
    char* string_type;
    char char_type;
    bool boolean_type;
    struct {
        struct ctofu* elements;
        size_t size;
    } array_type;
} ctofu_data;

// Define a struct to represent the data and its type
typedef struct {
    ctofu_type type;
    ctofu_data data;
} ctofu;

// Define a struct to represent the iterator
typedef struct {
    ctofu* current_key;
    ctofu* current_value;
    size_t index;
    ctofu_iterator *next
} ctofu_iterator;

// create and erase
ctofu_error tofu_create(ctofu_type type, ctofu_data* value, ctofu** result);
void tofu_erase(ctofu* value);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error tofu_sort_insertion(ctofu* array, size_t num);
ctofu_error tofu_sort_selection(ctofu* array, size_t num);
ctofu_error tofu_reverse(ctofu* array, size_t num);
ctofu_error tofu_compare(const ctofu* a, const ctofu* b, int* result);
size_t tofu_search_linear(ctofu* array, size_t num, ctofu* key);
size_t tofu_search_binary(ctofu* array, size_t num, ctofu* key);

// =======================
// UTILITY FUNCTIONS
// =======================
ctofu_error tofu_value_copy(const ctofu* source, ctofu* dest);
void tofu_value_setter(const ctofu* source, ctofu* dest);
ctofu_data tofu_value_getter(const ctofu* current);
ctofu_type tofu_type_getter(const ctofu* current);
bool tofu_not_cnullptr(const ctofu* value);
bool tofu_its_cnullptr(const ctofu* value);

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator tofu_iterator_at(ctofu* array, size_t num, size_t at);
ctofu_iterator tofu_iterator_start(ctofu* array, size_t num);
ctofu_iterator tofu_iterator_end(ctofu* array, size_t num);

#ifdef __cplusplus
}
#endif

#endif
