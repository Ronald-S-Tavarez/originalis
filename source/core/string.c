#include "core/string.h"

int string_compare(const char * string_one, const char * string_two) {
    while (*string_one && (*string_one == *string_two)) {
        string_one++;
        string_two++;
    }
    return *(unsigned char *)string_one - *(unsigned char *)string_two;
}

int string_length(const char * string) {
    int length = 0;
    while (*string++)
        length++;
    return length;
}

