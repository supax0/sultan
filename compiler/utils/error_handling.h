// error_handling.h
#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <stdio.h>    // For printf, fprintf
#include <stdlib.h>   // For memory functions
#include <string.h>   // For string functions

int levenshtein(const char *s1, const char *s2);  // Add missing semicolon

void handle_parse_error(const char *error_msg);   // Error handling function

#endif
