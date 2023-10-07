
#include "trilobite/xdata/tofu.h"
#include <stdio.h>

int main() {
    // Create Tofu instances with different data types
    TriloTofu tofuInteger = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofuDouble = trilo_xdata_tofu_create_from_double(3.14159);
    TriloTofu tofuString = trilo_xdata_tofu_create_from_string("Hello, World!");
    TriloTofu tofuChar = trilo_xdata_tofu_create_from_char('A');
    TriloTofu tofuBoolean = trilo_xdata_tofu_create_from_boolean(true);

    // Print the values of Tofu instances
    printf("Tofu Integer: %d\n", trilo_xdata_tofu_get_integer(tofuInteger));
    printf("Tofu Double: %lf\n", trilo_xdata_tofu_get_double(tofuDouble));
    printf("Tofu String: %s\n", trilo_xdata_tofu_get_string(tofuString));
    printf("Tofu Char: %c\n", trilo_xdata_tofu_get_char(tofuChar));
    printf("Tofu Boolean: %s\n", trilo_xdata_tofu_get_boolean(tofuBoolean) ? "true" : "false");

    // Convert Tofu instances to different data types
    int convertedInt = trilo_xdata_tofu_to_integer(tofuInteger);
    double convertedDouble = trilo_xdata_tofu_to_double(tofuDouble);
    const char* convertedString = trilo_xdata_tofu_to_string(tofuString);
    char convertedChar = trilo_xdata_tofu_to_char(tofuChar);
    bool convertedBoolean = trilo_xdata_tofu_to_boolean(tofuBoolean);

    // Print the converted values
    printf("Converted Integer: %d\n", convertedInt);
    printf("Converted Double: %lf\n", convertedDouble);
    printf("Converted String: %s\n", convertedString);
    printf("Converted Char: %c\n", convertedChar);
    printf("Converted Boolean: %s\n", convertedBoolean ? "true" : "false");

    return 0;
} // end of func
