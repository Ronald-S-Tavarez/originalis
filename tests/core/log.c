#include "core/log.h"
#include "core/string.h"

void test_log_message_to_console(void);
void test_log_macros(void);
void test_string_to_log_level(void);
void test_log_level_to_string(void);

int main(int argc, char ** argv) {
    test_log_message_to_console();
    test_log_macros();
    test_string_to_log_level();
    test_log_level_to_string();
    return 0;
}

void test_log_message_to_console(void) {
    log_message_to_console(LOG_LEVEL_DEBUG, __FUNCTION__, __FILE__, __LINE__, "This is a direct DEBUG message.");
    log_message_to_console(LOG_LEVEL_INFO, __FUNCTION__, __FILE__, __LINE__, "This is a direct INFO message.");
    log_message_to_console(LOG_LEVEL_SUCCESS, __FUNCTION__, __FILE__, __LINE__, "This is a direct SUCCESS message.");
    log_message_to_console(LOG_LEVEL_WARNING, __FUNCTION__, __FILE__, __LINE__, "This is a direct WARNING message.");
    log_message_to_console(LOG_LEVEL_ERROR, __FUNCTION__, __FILE__, __LINE__, "This is a direct ERROR message.");
    log_message_to_console(LOG_LEVEL_FATAL, __FUNCTION__, __FILE__, __LINE__, "This is a direct FATAL message.");
}

void test_log_macros(void) {
    LOG_CONSOLE_DEBUG("This is a DEBUG message using the macro.");
    LOG_CONSOLE_INFO("This is an INFO message using the macro.");
    LOG_CONSOLE_SUCCESS("This is a SUCCESS message using the macro.");
    LOG_CONSOLE_WARNING("This is a WARNING message using the macro.");
    LOG_CONSOLE_ERROR("This is a ERROR message using the macro.");
    LOG_CONSOLE_FATAL("This is a FATAL message using the macro.");
}

void test_string_to_log_level(void) {
    LOG_LEVEL converted_level = string_to_log_level("INFO");
    if (converted_level == LOG_LEVEL_INFO)
        LOG_CONSOLE_SUCCESS("Conversion from string 'INFO' to LOG_LEVEL_INFO was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion form string 'INFO' to LOG_LEVEL_INFO has failed.");

    converted_level = string_to_log_level("DEBUG");
    if (converted_level == LOG_LEVEL_DEBUG)
        LOG_CONSOLE_SUCCESS("Conversion from string 'DEBUG' to LOG_LEVEL_DEBUG was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from string 'DEBUG' to LOG_LEVEL_DEBUG has failed.");

    converted_level = string_to_log_level("SUCCESS");
    if (converted_level == LOG_LEVEL_SUCCESS)
        LOG_CONSOLE_SUCCESS("Conversion from string 'SUCCESS' to LOG_LEVEL_SUCCESS was successful."); 
    else
        LOG_CONSOLE_ERROR("Conversion from string 'SUCCESS' to LOG_LEVEL_SUCCESS has failed.");

    converted_level = string_to_log_level("WARNING");
    if (converted_level = LOG_LEVEL_WARNING)
        LOG_CONSOLE_SUCCESS("Conversion from string 'WARNING' to LOG_LEVEL_WARNING was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from string 'WARNING' to LOG_LEVEL_WARNING has failed.");
    
    converted_level = string_to_log_level("ERROR");
    if (converted_level = LOG_LEVEL_ERROR)
        LOG_CONSOLE_SUCCESS("Conversion from string 'ERROR' to LOG_LEVEL_ERROR was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from string 'ERROR' to LOG_LEVEL_ERROR has failed.");
    
    converted_level = string_to_log_level("FATAL");
    if (converted_level = LOG_LEVEL_FATAL)
        LOG_CONSOLE_SUCCESS("Conversion from string 'FATAL' to LOG_LEVEL_FATAL was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion form string 'FATAL' to LOG_LEVEL_FATAL has failed.");
}

void test_log_level_to_string(void) {
    const char * level_string = log_level_to_string(LOG_LEVEL_DEBUG);
    if (string_compare(level_string, "DEBUG") == 0)
        LOG_CONSOLE_SUCCESS("Conversion from LOG_LEVEL_DEBUG to string 'DEBUG' was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from LOG_LEVEL_DEBUG to string 'DEBUG' has failed.");

    level_string = log_level_to_string(LOG_LEVEL_INFO);
    if (string_compare(level_string, "INFO") == 0)
        LOG_CONSOLE_SUCCESS("Conversion from LOG_LEVEL_INFO to string 'INFO' was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from LOG_LEVEL_INFO to string 'INFO' has failed.");
    
    level_string = log_level_to_string(LOG_LEVEL_SUCCESS);
    if (string_compare(level_string, "SUCCESS") == 0)
        LOG_CONSOLE_SUCCESS("Conversion from LOG_LEVEL_SUCCESS to string 'SUCCESS' was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from LOG_LEVEL_SUCCESS to string 'SUCCESS' has failed.");
    
    level_string = log_level_to_string(LOG_LEVEL_WARNING);
    if (string_compare(level_string, "WARNING") == 0)
        LOG_CONSOLE_SUCCESS("Conversion from LOG_LEVEL_WARNING to string 'WARNING' was successful.");
    else 
        LOG_CONSOLE_ERROR("Conversion from LOG_LEVEL_WARNING to string 'WARNING' has failed.");
    
    level_string = log_level_to_string(LOG_LEVEL_ERROR);
    if (string_compare(level_string, "ERROR") == 0)
        LOG_CONSOLE_SUCCESS("Conversion from LOG_LEVEL_ERROR to string 'ERROR' was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from LOG_LEVEL_ERROR to string 'ERROR' has failed.");
    
    level_string = log_level_to_string(LOG_LEVEL_FATAL);
    if (string_compare(level_string, "FATAL") == 0)
        LOG_CONSOLE_SUCCESS("Converison from LOG_LEVEL_FATAL to string 'FATAL' was successful.");
    else
        LOG_CONSOLE_ERROR("Conversion from LOG_LEVEL_FATAL to string 'FATAL' has failed.");
}