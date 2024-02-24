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
#include <stdint.h>
#include <stddef.h>

/**
In the realm of quantum physics, our understanding of space, time, reality, and the observable universe takes
on a fascinating and intricate character. Quantum physics delves into the fundamental nature of matter and
energy at the smallest scales, challenging classical notions and ushering in a paradigm where the concepts of
space and time undergo profound transformations.

**Space in Quantum Physics:**
At the quantum level, space is not a static, absolute backdrop but a dynamic, probabilistic arena where particles
exist in multiple states simultaneously. Quantum superposition allows particles to occupy multiple positions at
once until observed, at which point the wavefunction collapses, and a definite state is realized. Entanglement
further blurs the boundaries of space, linking particles in ways that defy classical spatial separations, creating
a non-local interconnectedness.

**Time in Quantum Physics:**
Quantum physics introduces a nuanced perspective on time, challenging the classical notion of a continuous and
absolute flow. The concept of time is intricately interwoven with quantum entanglement, where correlated particles
instantaneously influence each other regardless of distance. Additionally, time dilation effects, as predicted by
the theory of relativity, become significant at quantum scales, revealing a profound connection between time,
gravity, and the fabric of spacetime.

**Reality and Observation:**
Quantum mechanics introduces the enigmatic role of observation in shaping reality. The act of measurement collapses
the wavefunction, determining the outcome of a quantum system. This observer-dependent reality challenges our classical
understanding of an objective, independent world. The famous thought experiment known as the Schrödinger's cat illustrates
the peculiar nature of reality in the quantum realm, where a system can exist in multiple states until observed.

**The Observable Universe:**
Quantum physics extends its influence to the observable universe, impacting our understanding of cosmic phenomena.
Quantum fluctuations during the early moments of the universe gave rise to cosmic structures, influencing the distribution
of galaxies and the large-scale structure we observe today. The cosmic microwave background radiation, a remnant from the
early universe, reflects quantum fluctuations that seeded the formation of galaxies and clusters.

In summary, quantum physics redefines our concepts of space, time, reality, and the observable universe. It invites us
to explore a realm where particles exhibit wave-particle duality, space is a realm of probabilities, time is intertwined
with gravity, and observation plays a crucial role in defining the nature of reality. The mysteries of quantum physics
continue to challenge and reshape our perceptions of the fundamental fabric of the cosmos.
*/

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
    TOFU_INT_TYPE,
    TOFU_INT8_TYPE,
    TOFU_INT16_TYPE,
    TOFU_INT32_TYPE,
    TOFU_INT64_TYPE,
    TOFU_UINT_TYPE,
    TOFU_UINT8_TYPE,
    TOFU_UINT16_TYPE,
    TOFU_UINT32_TYPE,
    TOFU_UINT64_TYPE,
    TOFU_OCTAL8_TYPE,
    TOFU_OCTAL16_TYPE,
    TOFU_OCTAL32_TYPE,
    TOFU_OCTAL64_TYPE,
    TOFU_BITWISE8_TYPE,
    TOFU_BITWISE16_TYPE,
    TOFU_BITWISE32_TYPE,
    TOFU_BITWISE64_TYPE,
    TOFU_HEX8_TYPE,
    TOFU_HEX16_TYPE,
    TOFU_HEX32_TYPE,
    TOFU_HEX64_TYPE,
    TOFU_FLOAT_TYPE,
    TOFU_DOUBLE_TYPE,
    TOFU_STRING_TYPE,
    TOFU_CHAR_TYPE,
    TOFU_BOOLEAN_TYPE,
    TOFU_ARRAY_TYPE,
    TOFU_QBIT_TYPE,
    TOFU_NULLPTR_TYPE,
    TOFU_INVALID_TYPE,
    TOFU_UNKNOWN_TYPE
} ctofu_type;  // Enumerated types for various tofu data

typedef union {
    int int_type;
    int8_t int8_type;
    int16_t int16_type;
    int32_t int32_type;
    int64_t int64_type;
    unsigned int uint_type;
    uint8_t uint8_type;
    uint16_t uint16_type;
    uint32_t uint32_type;
    uint64_t uint64_type;
    uint8_t octal8_type;
    uint16_t octal16_type;
    uint32_t octal32_type;
    uint64_t octal64_type;
    uint8_t bitwise8_type;
    uint16_t bitwise16_type;
    uint32_t bitwise32_type;
    uint64_t bitwise64_type;
    uint8_t hex8_type;
    uint16_t hex16_type;
    uint32_t hex32_type;
    uint64_t hex64_type;
    double double_type;
    float float_type;
    char* string_type;
    char char_type;
    void *nullptr_type;
    uint64_t qbit_type;
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

// =======================
// CREATE/ERASE FUNCTIONS
// =======================
ctofu_error fscl_tofu_create(ctofu_type type, ctofu_data* value, ctofu** result);
void fscl_tofu_erase(ctofu* value);

// =======================
// SORT ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_tofu_sort_insertion(ctofu* array, size_t num);
ctofu_error fscl_tofu_sort_selection(ctofu* array, size_t num);

// =======================
// SEARCH ALGORITHM FUNCTIONS
// =======================
size_t fscl_tofu_search_linear(ctofu* array, size_t num, ctofu* key);
size_t fscl_tofu_search_binary(ctofu* array, size_t num, ctofu* key);

// =======================
// OTHER ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_tofu_reverse(ctofu* array, size_t num);
ctofu_error fscl_tofu_compare(const ctofu* a, const ctofu* b, int* result);

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
