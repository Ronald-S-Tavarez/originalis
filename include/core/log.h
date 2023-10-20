#ifndef ORIGINALIS_CORE_LOG_H
#define ORIGINALIS_CORE_LOG_H

/**
 * @author Ronald Tavarez
 * @file log.h
 * @brief Simple logging utilities for the Originalis codebase.
 * 
 * Provides a basic logging system, enabling message to be logged with
 * different levels of severity. Each logged message will be associated
 * with the file and line from where it's logged.
 */

/**
 * TODO: Configurable Log level -> set minimum log level to be shown.
 * TODO: File logging
 * TODO: Timestamps
 * TODO: Log rotation
 * TODO: Thread safe logger
 * TODO: Variadic argument logger and string format
 */

/**
 * @enum log_level 
 * @brief Enumeration representing the severity level of a log message.
 */
typedef enum log_level {
    LOG_LEVEL_DEBUG   = 0,  /**< Debugging purposes. */
    LOG_LEVEL_INFO    = 1,  /**< General informational. */
    LOG_LEVEL_SUCCESS = 2,  /**< Successful execution. */
    LOG_LEVEL_WARNING = 3,  /**< Indicated potential problem or caution needed. */
    LOG_LEVEL_ERROR   = 4,  /**< Represents an error, but not a program stopper. */
    LOG_LEVEL_FATAL   = 5,  /**< Critical error, often leading to program termination. */
    LOG_LEVEL_UNKNOWN = -1  /**< Unrecognized log level used for string to log level conversion */
} LOG_LEVEL;

/**
 * @brief Converts the given log level to a string representation.
 * 
 * @param level The log level to be converted.
 * @return const char * - Returns a string representation of the given the given log level.
 */
const char * log_level_to_string(LOG_LEVEL level);

/**
 * @brief Converts the given string to its corresponding log level.
 * 
 * @param string The string representation of the log level.
 * @return LOG_LEVEL - Returns the log level corresponding to the given string on success & LOG_LEVEL_UNKNOWN on failure.
 */
LOG_LEVEL string_to_log_level(const char * string);

/**
 * @brief Log a message with a particular severity level to stdout.
 * 
 * @param level The severity level of the log.
 * @param file The source file from where the log was made.
 * @param line The line number in the source file.
 * @param message The actual log message.
 */
void log_message_to_console(LOG_LEVEL level, const char * func, const char * file, int line, const char * message);

/**
 * @def LOG_CONSOLE_DEBUG(message)
 * @brief Logs a message with a DEBUG severity to stdout.
 * @param message The actual log message.
 */
#define LOG_CONSOLE_DEBUG(message) log_message_to_console(LOG_LEVEL_DEBUG, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * @def LOG_CONSOLE_INFO(message)
 * @brief Logs a message with an INFO severity to stdout.
 * @param message The actual log message.
 */
#define LOG_CONSOLE_INFO(message) log_message_to_console(LOG_LEVEL_INFO, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * @def LOG_CONSOLE_SUCCESS(message)
 * @brief Logs a message with a SUCCESS severity to stdout.
 * @param message The actual log message.
 */
#define LOG_CONSOLE_SUCCESS(message) log_message_to_console(LOG_LEVEL_SUCCESS, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * @def LOG_CONSOLE_WARNING(message)
 * @brief Logs a message with a WARNING severity to stdout.
 * @param message The actual log message.
 */
#define LOG_CONSOLE_WARNING(message) log_message_to_console(LOG_LEVEL_WARNING, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * @def LOG_CONSOLE_ERROR(message)
 * @brief Logs a message with an ERROR severity to stdout.
 * @param message The actual log message.
 */
#define LOG_CONSOLE_ERROR(message) log_message_to_console(LOG_LEVEL_ERROR, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * @def LOG_CONSOLE_FATAL(message)
 * @brief Logs a message with a FATAL severity to stdout. Typically indicates critical issues.
 * @param message The actual log message.
 */
#define LOG_CONSOLE_FATAL(message) log_message_to_console(LOG_LEVEL_FATAL, __FUNCTION__, __FILE__, __LINE__, message)

#endif  // CORE_LOG_H