#include <stdio.h>
#include <stdbool.h>

#include "include\core\context.h"

static const char * bool_as_alpha(bool value);

int main(int argc, char ** argv) {
    printf("Current Context: {\n");

    // Compilers
    printf("\t\"compiler\": {\n");
    printf("\t\t\"clang\": %s,\n",  bool_as_alpha(COMPILER_CLANG));
    printf("\t\t\"cl\": %s,\n",     bool_as_alpha(COMPILER_CL));
    printf("\t\t\"gcc\": %s\n",     bool_as_alpha(COMPILER_GCC));
    printf("\t},\n");

    // Operating Systems
    printf("\t\"os\": {\n");
    printf("\t\t\"windows\": %s,\n",bool_as_alpha(OS_WINDOWS));
    printf("\t\t\"linux\": %s,\n",  bool_as_alpha(OS_LINUX));
    printf("\t\t\"android\": %s,\n",bool_as_alpha(OS_ANDROID));
    printf("\t\t\"ios\": %s,\n",    bool_as_alpha(OS_IOS));
    printf("\t\t\"mac\": %s\n",     bool_as_alpha(OS_MAC));
    printf("\t},\n");

    // CPU Architecture
    printf("\t\"architecture\": {\n");
    printf("\t\t\"x64\": %s,\n",    bool_as_alpha(ARCH_X64));
    printf("\t\t\"x86\": %s,\n",    bool_as_alpha(ARCH_X86));
    printf("\t\t\"ARM\": %s,\n",    bool_as_alpha(ARCH_ARM));
    printf("\t\t\"ARM64\": %s\n",   bool_as_alpha(ARCH_ARM64));
    printf("\t}\n");

    printf("}\n");

    return 0;
}

static const char * bool_as_alpha(bool value) {
    return value ? "true" : "false";
}