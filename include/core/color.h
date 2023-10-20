#ifndef ORIGINALIS_CORE_COLOR_H
#define ORIGINALIS_CORE_COLOR_H

/**
 * @author Ronald Tavarez 
 * @file color.h
 * @date 2023-10-18
 * @brief Terminal color definitions for the Originalis codebase.
 * 
 * This header provides macros for using ANSI escape codes to
 * colorize and format terminal output.
 */

/* Foreground Colors */
#define TERMINAL_COLOR_FG_BLACK   "\x1b[30m"    /** Black foreground color ANSI escape code. */
#define TERMINAL_COLOR_FG_RED     "\x1b[31m"    /** Red foreground color ANSI escape code. */
#define TERMINAL_COLOR_FG_GREEN   "\x1b[32m"    /** Green foreground color ANSI escape code. */
#define TERMINAL_COLOR_FG_YELLOW  "\x1b[33m"    /** Yellow foreground color ANSI escape code. */
#define TERMINAL_COLOR_FG_BLUE    "\x1b[34m"    /** Blue foreground color ANSI escape code. */
#define TERMINAL_COLOR_FG_MAGENTA "\x1b[35m"    /** Magenta foreground color ANSI escape code. */
#define TERMINAL_COLOR_FG_CYAN    "\x1b[36m"    /** Cyan foreground color ANSI escape code. */
#define TERMINAL_COLOR_FG_WHITE   "\x1b[37m"    /** White foreground color ANSI escape code. */

/* Background Colors */
#define TERMINAL_COLOR_BG_BLACK   "\x1b[40m"    /** Black background color ANSI escape code. */
#define TERMINAL_COLOR_BG_RED     "\x1b[41m"    /** Red background color ANSI escape code. */
#define TERMINAL_COLOR_BG_GREEN   "\x1b[42m"    /** Green background color ANSI escape code. */
#define TERMINAL_COLOR_BG_YELLOW  "\x1b[43m"    /** Yellow background color ANSI escape code. */
#define TERMINAL_COLOR_BG_BLUE    "\x1b[44m"    /** Blue background color ANSI escape code. */
#define TERMINAL_COLOR_BG_MAGENTA "\x1b[45m"    /** Magenta background color ANSI escape code. */
#define TERMINAL_COLOR_BG_CYAN    "\x1b[46m"    /** Cyan background color ANSI escape code. */
#define TERMINAL_COLOR_BG_WHITE   "\x1b[47m"    /** White background color ANSI escape code. */

/* Modifiers */
#define TERMINAL_MODIFIER_RESET      "\x1b[0m"     /** ANSI escape code to reset all terminal modifications */
#define TERMINAL_MODIFIER_BOLD       "\x1b[1m"     /** ANSI escape code to bold text. */
#define TERMINAL_MODIFIER_UNDERLINE  "\x1b[4m"     /** ANSI escape code to underline text. */
#define TERMINAL_MODIFIER_REVERSED   "\x1b[7m"     /** ANSI escape code to reverse foreground and background colors.*/


#endif  // CORE_COLOR_H