/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
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

//
// Generic and secure flavorless data type.
//
enum DataType {
    INTEGER_TYPE,
    DOUBLE_TYPE,
    STRING_TYPE,
    CHAR_TYPE,
    BOOLEAN_TYPE
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

// Function to create a new TriloTofu instance from an integer
TriloTofu trilo_xdata_tofu_create_from_integer(int value);

// Function to create a new TriloTofu instance from a double
TriloTofu trilo_xdata_tofu_create_from_double(double value);

// Function to create a new TriloTofu instance from a string
TriloTofu trilo_xdata_tofu_create_from_string(const char* value);

// Function to create a new TriloTofu instance from a char
TriloTofu trilo_xdata_tofu_create_from_char(char value);

// Function to create a new TriloTofu instance from a bool
TriloTofu trilo_xdata_tofu_create_from_boolean(bool value);

// Function to print the data in a TriloTofu instance
void trilo_xdata_tofu_print(TriloTofu tofu);

// Function to get the integer data from a TriloTofu instance
int trilo_xdata_tofu_get_integer(TriloTofu tofu);

// Function to get the double data from a TriloTofu instance
double trilo_xdata_tofu_get_double(TriloTofu tofu);

// Function to get the string data from a TriloTofu instance
const char* trilo_xdata_tofu_get_string(TriloTofu tofu);

// Function to get the char data from a TriloTofu instance
char trilo_xdata_tofu_get_char(TriloTofu tofu);

// Function to get the boolean data from a TriloTofu instance
bool trilo_xdata_tofu_get_boolean(TriloTofu tofu);

// Function to convert TriloTofu to an integer
int trilo_xdata_tofu_to_integer(TriloTofu tofu);

// Function to convert TriloTofu to a double
double trilo_xdata_tofu_to_double(TriloTofu tofu);

// Function to convert TriloTofu to a string
const char* trilo_xdata_tofu_to_string(TriloTofu tofu);

// Function to convert TriloTofu to a char
char trilo_xdata_tofu_to_char(TriloTofu tofu);

// Function to convert TriloTofu to a bool
bool trilo_xdata_tofu_to_boolean(TriloTofu tofu);

#ifdef __cplusplus
}
#endif

#endif
