#include "core/color.h"
#include <stdio.h>

void test_colors(void);
void test_modifiers(void);

int main(int argc, char **argv) {
    test_colors();
    test_modifiers();
    return 0;
}

void test_colors(void) {
    printf("Testing Colors:\n");

    printf(TERMINAL_COLOR_FG_BLACK "This should be black text.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_FG_RED "This should be red text.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_FG_GREEN "This should be green text.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_FG_YELLOW "This should be yellow text.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_FG_BLUE "This should be blue text.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_FG_MAGENTA "This should be magenta text.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_FG_CYAN "This should be cyan text.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_FG_WHITE "This should be white text.\n" TERMINAL_MODIFIER_RESET);

    printf(TERMINAL_COLOR_BG_BLACK "This should have a black background.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_BG_RED "This should have a red background.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_BG_GREEN "This should have a green background.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_BG_YELLOW "This should have a yellow background.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_BG_BLUE "This should have a blue background.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_BG_MAGENTA "This should have a magenta background.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_BG_CYAN "This should have a cyan background.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_COLOR_BG_WHITE "This should have a white background.\n" TERMINAL_MODIFIER_RESET);
}

void test_modifiers(void) {
    printf("\nTesting Modifiers:\n");

    printf(TERMINAL_MODIFIER_BOLD "This text should be bold.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_MODIFIER_UNDERLINE "This text should be underlined.\n" TERMINAL_MODIFIER_RESET);
    printf(TERMINAL_MODIFIER_REVERSED "This text should have reversed colors.\n" TERMINAL_MODIFIER_RESET);
}
