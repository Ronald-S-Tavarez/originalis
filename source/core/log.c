#include "core/log.h"
#include "core/string.h"
#include "core/array.h"
#include "core/color.h"

#include <stdio.h>


static const char * LOG_LEVEL_STRING_LIST[] = {
    "DEBUG",
    "INFO",
    "SUCCESS",
    "WARNING",
    "ERROR",
    "FATAL"
};

static const char * log_level_to_color(LOG_LEVEL level) {
    switch (level) {
        case LOG_LEVEL_DEBUG:   return TERMINAL_COLOR_FG_BLUE;
        case LOG_LEVEL_INFO:    return TERMINAL_COLOR_FG_WHITE;
        case LOG_LEVEL_SUCCESS: return TERMINAL_COLOR_FG_GREEN;
        case LOG_LEVEL_WARNING: return TERMINAL_COLOR_FG_YELLOW;
        case LOG_LEVEL_ERROR:   return TERMINAL_COLOR_FG_RED;
        case LOG_LEVEL_FATAL:   return TERMINAL_COLOR_FG_MAGENTA;
        default:                return TERMINAL_MODIFIER_RESET;
    }
}

const char * log_level_to_string(LOG_LEVEL level) {
    if (level >= 0 && level < ARRAY_COUNT(LOG_LEVEL_STRING_LIST))
        return LOG_LEVEL_STRING_LIST[level];
    else
        return "UNKNOWN";
}

LOG_LEVEL string_to_log_level(const char * string) {
    if (!string) 
        return LOG_LEVEL_UNKNOWN;

    if (string_compare(string, LOG_LEVEL_STRING_LIST[LOG_LEVEL_DEBUG]) == 0)
        return LOG_LEVEL_DEBUG;
    
    if (string_compare(string, LOG_LEVEL_STRING_LIST[LOG_LEVEL_INFO]) == 0)
        return LOG_LEVEL_INFO;

    if (string_compare(string, LOG_LEVEL_STRING_LIST[LOG_LEVEL_SUCCESS]) == 0)
        return LOG_LEVEL_SUCCESS;

    if (string_compare(string, LOG_LEVEL_STRING_LIST[LOG_LEVEL_WARNING]) == 0)
        return LOG_LEVEL_WARNING;

    if (string_compare(string, LOG_LEVEL_STRING_LIST[LOG_LEVEL_ERROR]) == 0)
        return LOG_LEVEL_ERROR;
    
    if (string_compare(string, LOG_LEVEL_STRING_LIST[LOG_LEVEL_FATAL]) == 0)
        return LOG_LEVEL_FATAL;

    return LOG_LEVEL_UNKNOWN;
}

void log_message_to_console(LOG_LEVEL level, const char * func, const char * file, int line, const char * message) {
    const char * log_level_string = log_level_to_string(level);
    const char * foreground_color = log_level_to_color(level);
    const char * background_color = TERMINAL_COLOR_BG_BLACK;

    printf("%s%s[%s]%s (%s: %s:%d) %s\n", 
        background_color, 
        foreground_color, 
        log_level_string, 
        TERMINAL_MODIFIER_RESET, 
        func, file, line, message);
}