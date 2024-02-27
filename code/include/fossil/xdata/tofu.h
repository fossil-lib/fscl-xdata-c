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

/**
 * @file tofu.h
 *
 * @brief Header file for the Tofu library, providing versatile data structures and algorithms for managing various data types.
 *
 * The Tofu library offers a comprehensive suite of data structures and algorithms
 * meticulously crafted to efficiently handle a broad spectrum of data types. Its
 * functionalities encompass creating, erasing, searching, sorting, filtering,
 * and iterating through data structures. Moreover, it incorporates robust error
 * handling mechanisms and utilities for copying, setting, and retrieving values.
 *
 * Tofu data structures accommodate a diverse array of data types, including integers,
 * floating-point numbers, strings, characters, arrays, maps, and customizable data
 * types. The library is highly adaptable, empowering users to define their custom
 * data types and operations to suit their specific needs.
 *
 * This header file encompasses declarations for all functions and data types provided
 * by the Tofu library. By including this header file in their projects, users can
 * leverage the extensive functionalities offered by the library.
 */

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

/**
 * @brief Forward declaration of the ctofu struct.
 *
 * This forward declaration introduces the ctofu struct before its full definition.
 * It allows the compiler to recognize the ctofu type without requiring the complete
 * definition at this point in the code. This is particularly useful when declaring
 * pointers or functions that involve the ctofu type, providing flexibility in the
 * organization of code and facilitating modular design.
 */
typedef struct ctofu ctofu;

/**
 * Enumerated error codes for tofu operations on data structures.
 */
typedef enum {
    TOFU_SUCCESS             = 0,   ///< Operation completed successfully.
    TOFU_WAS_MISMATCH        = -1,  ///< Data mismatch error.
    TOFU_WAS_BAD_RANGE       = -2,  ///< Out-of-range error.
    TOFU_WAS_NULLPTR         = -3,  ///< Null pointer error.
    TOFU_WAS_BAD_MALLOC      = -4,  ///< Memory allocation error.
    TOFU_WAS_UNKNOWN         = -5,  ///< Unknown error.
    TOFU_NOT_FOUND           = -6,  ///< Element not found error.
    TOFU_INVALID_OPERATION   = -7,  ///< Invalid operation on the data structure error.
    TOFU_DUPLICATE_ELEMENT   = -8,  ///< Attempt to insert a duplicate element error.
    TOFU_OUT_OF_MEMORY       = -9,  ///< Insufficient memory to perform the operation error.
    TOFU_EMPTY_STRUCTURE     = -10, ///< Operation not allowed on an empty structure error.
    TOFU_STRUCTURE_FULL      = -11, ///< Structure has reached its maximum capacity error.
    TOFU_STRUCTURE_OVERFLOW  = -12, ///< Overflow occurred while performing an operation error.
    TOFU_STRUCTURE_UNDERFLOW = -13, ///< Underflow occurred while performing an operation error.
    TOFU_STRUCTURE_NOT_EMPTY = -14, ///< Operation not allowed on a non-empty structure error.
    TOFU_STRUCTURE_NOT_FULL  = -15, ///< Structure is not at maximum capacity error.
    TOFU_STRUCTURE_EMPTY     = -16, ///< Operation not allowed on an empty structure error.
    TOFU_STRUCTURE_NOT_FOUND = -17, ///< Element not found in the structure error.
    TOFU_STRUCTURE_CORRUPTED = -18, ///< Data structure integrity compromised error.
    TOFU_STRUCTURE_INVALID   = -19, ///< Invalid data structure type error.
    TOFU_INVALID_ARGUMENT    = -20  ///< Invalid argument provided to the operation error.
} ctofu_error;

/**
 * Enumerated types for representing various data types in the "tofu" data structure.
 */
typedef enum {
    TOFU_INT_TYPE,           ///< Integer type.
    TOFU_INT8_TYPE,          ///< 8-bit integer type.
    TOFU_INT16_TYPE,         ///< 16-bit integer type.
    TOFU_INT32_TYPE,         ///< 32-bit integer type.
    TOFU_INT64_TYPE,         ///< 64-bit integer type.
    TOFU_UINT_TYPE,          ///< Unsigned integer type.
    TOFU_UINT8_TYPE,         ///< 8-bit unsigned integer type.
    TOFU_UINT16_TYPE,        ///< 16-bit unsigned integer type.
    TOFU_UINT32_TYPE,        ///< 32-bit unsigned integer type.
    TOFU_UINT64_TYPE,        ///< 64-bit unsigned integer type.
    TOFU_OCTAL8_TYPE,        ///< 8-bit octal type.
    TOFU_OCTAL16_TYPE,       ///< 16-bit octal type.
    TOFU_OCTAL32_TYPE,       ///< 32-bit octal type.
    TOFU_OCTAL64_TYPE,       ///< 64-bit octal type.
    TOFU_BITWISE8_TYPE,      ///< 8-bit bitwise type.
    TOFU_BITWISE16_TYPE,     ///< 16-bit bitwise type.
    TOFU_BITWISE32_TYPE,     ///< 32-bit bitwise type.
    TOFU_BITWISE64_TYPE,     ///< 64-bit bitwise type.
    TOFU_HEX8_TYPE,          ///< 8-bit hexadecimal type.
    TOFU_HEX16_TYPE,         ///< 16-bit hexadecimal type.
    TOFU_HEX32_TYPE,         ///< 32-bit hexadecimal type.
    TOFU_HEX64_TYPE,         ///< 64-bit hexadecimal type.
    TOFU_FLOAT_TYPE,         ///< Floating-point type (float).
    TOFU_DOUBLE_TYPE,        ///< Floating-point type (double).
    TOFU_STRING_TYPE,        ///< String type.
    TOFU_CHAR_TYPE,          ///< Character type.
    TOFU_BOOLEAN_TYPE,       ///< Boolean type.
    TOFU_ARRAY_TYPE,         ///< Array type.
    TOFU_MAP_TYPE,           ///< Map type.
    TOFU_QBIT_TYPE,          ///< Quantum bit type (64-bit).
    TOFU_NULLPTR_TYPE,       ///< Null pointer type.
    TOFU_INVALID_TYPE,       ///< Invalid data structure type.
    TOFU_UNKNOWN_TYPE        ///< Unknown data type.
} ctofu_type;

/**
 * Union to hold data of different types in the "tofu" data structure.
 */
typedef union {
    int int_type;              ///< Integer type.
    int8_t int8_type;          ///< 8-bit integer type.
    int16_t int16_type;        ///< 16-bit integer type.
    int32_t int32_type;        ///< 32-bit integer type.
    int64_t int64_type;        ///< 64-bit integer type.
    unsigned int uint_type;    ///< Unsigned integer type.
    uint8_t uint8_type;        ///< 8-bit unsigned integer type.
    uint16_t uint16_type;      ///< 16-bit unsigned integer type.
    uint32_t uint32_type;      ///< 32-bit unsigned integer type.
    uint64_t uint64_type;      ///< 64-bit unsigned integer type.
    uint8_t octal8_type;       ///< 8-bit octal type.
    uint16_t octal16_type;     ///< 16-bit octal type.
    uint32_t octal32_type;     ///< 32-bit octal type.
    uint64_t octal64_type;     ///< 64-bit octal type.
    uint8_t bitwise8_type;     ///< 8-bit bitwise type.
    uint16_t bitwise16_type;   ///< 16-bit bitwise type.
    uint32_t bitwise32_type;   ///< 32-bit bitwise type.
    uint64_t bitwise64_type;   ///< 64-bit bitwise type.
    uint8_t hex8_type;         ///< 8-bit hexadecimal type.
    uint16_t hex16_type;       ///< 16-bit hexadecimal type.
    uint32_t hex32_type;       ///< 32-bit hexadecimal type.
    uint64_t hex64_type;       ///< 64-bit hexadecimal type.
    double double_type;        ///< Double precision floating-point type.
    float float_type;          ///< Single precision floating-point type.
    char* string_type;         ///< String type.
    char char_type;            ///< Character type.
    void* nullptr_type;        ///< Null pointer type.
    uint64_t qbit_type;        ///< 64-bit quantum bit type.
    bool boolean_type;         ///< Boolean type.
    struct {
        struct ctofu* elements; ///< Array type.
        size_t size;            ///< Size of the array.
    } array_type;
    struct {
        struct ctofu* key;      ///< Key type for a map.
        struct ctofu* value;    ///< Value type for a map.
        size_t size;            ///< Size of the map.
    } map_type;
} ctofu_data;

/**
 * Struct to represent the data and its type in the "tofu" data structure.
 */
struct ctofu {
    ctofu_type type;  ///< The data type of the "tofu" structure.
    ctofu_data data;  ///< The data stored in the "tofu" structure.
};

/**
 * Struct to represent an iterator for traversing a "tofu" array.
 */
typedef struct {
    ctofu* current_key;    ///< The current key element pointed to by the iterator.
    ctofu* current_value;  ///< The current value element pointed to by the iterator.
    size_t index;          ///< The index of the iterator within the "tofu" array.
} ctofu_iterator;

/**
 * Struct to represent a pair of key and value elements in a searchable data type.
 */
typedef struct {
    ctofu* current_key;    ///< The current key element in the pair.
    ctofu* current_value;  ///< The current value element in the pair.
} ctofu_pair;

// =======================
// CREATE/ERASE FUNCTIONS
// =======================

/**
 * Creates a new "tofu" structure with the specified type and optional initial value.
 *
 * @param type The data type of the "tofu" structure.
 * @param value Optional initial value for the "tofu" structure.
 * @return A pointer to the newly created "tofu" structure, or NULL on failure.
 */
ctofu* fscl_tofu_create(ctofu_type type, ctofu_data* value);

/**
 * Creates a new "tofu" array with the specified type and size, initialized with variable arguments.
 *
 * @param type The data type of the "tofu" array.
 * @param size The size of the "tofu" array.
 * @param ... Variable arguments to initialize the "tofu" array.
 * @return A pointer to the newly created "tofu" array, or NULL on failure.
 */
ctofu* fscl_tofu_create_array(ctofu_type type, size_t size, ...);

/**
 * Erases a single "tofu" structure, freeing its memory.
 *
 * @param value The "tofu" structure to erase.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_erase(ctofu* value);

/**
 * Erases an array of "tofu" structures, freeing their memory.
 *
 * @param array The array of "tofu" structures to erase.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_erase_array(ctofu* array);

// =======================
// CLASSIC ALGORITHM FUNCTIONS
// =======================

/**
 * Accumulates the values in the "tofu" structure.
 *
 * @param objects The "tofu" structure to accumulate.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_accumulate(ctofu* objects);

/**
 * Transforms each element in the "tofu" structure using the provided transformation function.
 *
 * @param objects The "tofu" structure to transform.
 * @param transformFunc The transformation function applied to each element.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_transform(ctofu* objects, int (*transformFunc)(int));

/**
 * Sorts the elements in the "tofu" structure in ascending order.
 *
 * @param objects The "tofu" structure to sort.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_sort(ctofu* objects);

/**
 * Searches for a key element in the "tofu" structure.
 *
 * @param objects The "tofu" structure to search.
 * @param key The key element to search for.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_search(ctofu* objects, ctofu* key);

/**
 * Filters elements in the "tofu" structure based on the provided filter function.
 *
 * @param objects The "tofu" structure to filter.
 * @param filterFunc The filter function applied to each element.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_filter(ctofu* objects, bool (*filterFunc)(const ctofu*));

/**
 * Reverses the order of elements in the "tofu" structure.
 *
 * @param objects The "tofu" structure to reverse.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_reverse(ctofu* objects);

/**
 * Swaps the positions of two elements in the "tofu" structure.
 *
 * @param right The first element to swap.
 * @param left The second element to swap.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_swap(ctofu* right, ctofu* left);

/**
 * Compares two elements in the "tofu" structure.
 *
 * @param right The first element to compare.
 * @param left The second element to compare.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_compare(ctofu* right, ctofu* left);

/**
 * Reduces the elements in the "tofu" structure using the provided reduction function.
 *
 * @param objects The "tofu" structure to reduce.
 * @param reduceFunc The reduction function applied to pairs of elements.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_reduce(ctofu* objects, ctofu (*reduceFunc)(const ctofu*, const ctofu*));

/**
 * Shuffles the elements in the "tofu" structure randomly.
 *
 * @param objects The "tofu" structure to shuffle.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_shuffle(ctofu* objects);

/**
 * Applies a given function to each element in the "tofu" structure without modifying the structure.
 * The function signature should be: void (*forEachFunc)(ctofu* element);
 *
 * @param objects The "tofu" structure.
 */
ctofu_error fscl_tofu_for_each(ctofu* objects, void (*forEachFunc)(ctofu*));

/**
 * Divides the elements in the "tofu" structure into two groups based on a predicate.
 * The predicate signature should be: bool (*partitionFunc)(const ctofu* element);
 * The function returns a new "tofu" structure containing two arrays: elements satisfying the predicate
 * and elements not satisfying the predicate.
 *
 * @param objects The "tofu" structure.
 * @param partitionFunc The predicate function.
 * @param partitionedResults An array containing two "tofu" structures representing the two partitions.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_partition(ctofu* objects, bool (*partitionFunc)(const ctofu*), ctofu* partitionedResults[2]);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Print the value of a ctofu variable to the standard output.
 *
 * This function prints the value of the given ctofu variable to the standard output.
 * The output format depends on the type of the ctofu variable.
 *
 * @param value The ctofu variable whose value needs to be printed.
 */
void fscl_tofu_out(const ctofu value);

/**
 * @brief Duplicates a string.
 *
 * This function takes a null-terminated string `source` as input and creates
 * a duplicate, allocating memory for the new string. The duplicated string is
 * null-terminated as well. The caller is responsible for freeing the memory
 * allocated by this function using `free()`.
 *
 * @param source The null-terminated string to be duplicated.
 * @return A pointer to the duplicated string or NULL if memory allocation fails.
 */
char* fscl_tofu_strdup(const char* source);


/**
 * Retrieves a descriptive error message for the given "tofu" error code.
 *
 * @param error The "tofu" error code.
 * @return A descriptive error message.
 */
ctofu_error fscl_tofu_error(ctofu_error error);

/**
 * Copies the value of a "tofu" structure to another.
 *
 * @param source The source "tofu" structure.
 * @param dest The destination "tofu" structure.
 * @return Error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tofu_value_copy(const ctofu* source, ctofu* dest);

/**
 * Sets the value of a "tofu" structure based on another "tofu" structure.
 *
 * @param source The source "tofu" structure.
 * @param dest The destination "tofu" structure.
 */
void fscl_tofu_value_setter(const ctofu* source, ctofu* dest);

/**
 * Erases the value of a "tofu" structure, freeing any associated resources.
 *
 * @param value The "tofu" structure to erase the value of.
 */
void fscl_tofu_value_erase(ctofu* value);

/**
 * Retrieves the data stored in a "tofu" structure.
 *
 * @param current The "tofu" structure.
 * @return The data stored in the "tofu" structure.
 */
ctofu_data fscl_tofu_value_getter(ctofu* current);

/**
 * Retrieves the data type of a "tofu" structure.
 *
 * @param current The "tofu" structure.
 * @return The data type of the "tofu" structure.
 */
ctofu_type fscl_tofu_type_getter(ctofu* current);

/**
 * Checks if the given "tofu" structure is not a nullptr.
 *
 * @param value The "tofu" structure to check.
 * @return true if the "tofu" structure is not a nullptr, false otherwise.
 */
bool fscl_tofu_not_cnullptr(const ctofu* value);

/**
 * Checks if the given "tofu" structure is a nullptr.
 *
 * @param value The "tofu" structure to check.
 * @return true if the "tofu" structure is a nullptr, false otherwise.
 */
bool fscl_tofu_its_cnullptr(const ctofu* value);

// =======================
// ITERATOR FUNCTIONS
// =======================

/**
 * Creates an iterator positioned at a specific index in the "tofu" array.
 *
 * @param array The "tofu" array.
 * @param num The number of elements in the array.
 * @param at The index to position the iterator at.
 * @return An iterator positioned at the specified index.
 */
ctofu_iterator fscl_tofu_iterator_at(ctofu* array, size_t num, size_t at);

/**
 * Creates an iterator positioned at the beginning of the "tofu" array.
 *
 * @param array The "tofu" array.
 * @param num The number of elements in the array.
 * @return An iterator positioned at the beginning of the array.
 */
ctofu_iterator fscl_tofu_iterator_start(ctofu* array, size_t num);

/**
 * Creates an iterator positioned at the end of the "tofu" array.
 *
 * @param array The "tofu" array.
 * @param num The number of elements in the array.
 * @return An iterator positioned at the end of the array.
 */
ctofu_iterator fscl_tofu_iterator_end(ctofu* array, size_t num);

#ifdef __cplusplus
}
#endif

#endif
