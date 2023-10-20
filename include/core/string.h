#ifndef ORIGINALIS_CORE_STRING_H
#define ORIGINALIS_CORE_STRING_H

/**
 * @brief Compare two string for equality.
 * 
 * @param string_one The first string.
 * @param string_two The second string.
 * @return int - Returns 0 if the strings are equal, non-zero otherwise.
 */
int string_compare(const char * string_one, const char * string_two);

/**
 * @brief Get the length of a string.
 * 
 * @param string The string.
 * @return int - Returns the length of the string.
 */
int string_length(const char * string);



#endif  // CORE_STRING_H