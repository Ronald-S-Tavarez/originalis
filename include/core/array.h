#ifndef ORIGINALIS_CORE_ARRAY_H 
#define ORIGINALIS_CORE_ARRAY_H

/**
 * @def ARRAY_COUNT(array)
 * @brief A macro that finds the size of a static array.
 * @param array The static array. 
 */
#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#endif  // ORIGINALIS_CORE_ARRAY_H