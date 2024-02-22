/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef fscl_tofu_H
#define fscl_tofu_H

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
} ctofu_error;  // Error codes for tofu operations

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
} ctofu_type;  // Enumerated types for various tofu data

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
} ctofu_data;  // Union to hold data of different types

typedef struct {
    ctofu_type type;
    ctofu_data data;
} ctofu;  // Struct to represent the data and its type

typedef struct {
    ctofu* current_key;
    ctofu* current_value;
    size_t index;
} ctofu_iterator;  // Struct to represent the iterator

typedef struct {
    ctofu_type type;
    ctofu_data data;
    ctofu* key;
} ctofu_searchable;  // Struct to represent the searchable data type

typedef struct {
    ctofu_type type;
    ctofu_data data;
    size_t index;
} ctofu_sortable;  // Struct to represent the sortable data type

typedef struct {
    ctofu_type type;
    ctofu_data data;
} ctofu_comparable;  // Struct to represent the comparable data type

// create and erase
ctofu_error fscl_tofu_create(ctofu_type type, ctofu_data* value, ctofu** result);
void fscl_tofu_erase(ctofu* value);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_tofu_sort_insertion(ctofu* array, size_t num);
ctofu_error fscl_tofu_sort_selection(ctofu* array, size_t num);
ctofu_error fscl_tofu_reverse(ctofu* array, size_t num);
ctofu_error fscl_tofu_compare(const ctofu* a, const ctofu* b, int* result);
size_t fscl_tofu_search_linear(ctofu* array, size_t num, ctofu* key);
size_t fscl_tofu_search_binary(ctofu* array, size_t num, ctofu* key);

// =======================
// UTILITY FUNCTIONS
// =======================
ctofu_error fscl_tofu_value_copy(const ctofu* source, ctofu* dest);
void fscl_tofu_value_setter(const ctofu* source, ctofu* dest);
ctofu_data fscl_tofu_value_getter(const ctofu* current);
ctofu_type fscl_tofu_type_getter(const ctofu* current);
bool fscl_tofu_not_cnullptr(const ctofu* value);
bool fscl_tofu_its_cnullptr(const ctofu* value);

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator fscl_tofu_iterator_at(ctofu* array, size_t num, size_t at);
ctofu_iterator fscl_tofu_iterator_start(ctofu* array, size_t num);
ctofu_iterator fscl_tofu_iterator_end(ctofu* array, size_t num);

#ifdef __cplusplus
}
#endif

#endif
