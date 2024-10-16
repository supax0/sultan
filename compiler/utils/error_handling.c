#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_handling.h"
#include "../builder/outputmsg.h"
#include "../parser/sultanc.tab.h"  // Include Bison-generated header

extern int yylineno;
extern int yycolumn;
extern char *yytext;

void handle_parse_error(const char *s) {
    // Print the basic error message
    fprintf(stderr, RED "error: %s\n" RESET, s);
    fprintf(stderr, " --> line %d, column %d\n", yylineno, yycolumn);
    fprintf(stderr, "  |\n");
    fprintf(stderr, "%3d | %s\n", yylineno, yytext);
    fprintf(stderr, "  | %*s" RED "^\n" RESET, yycolumn, "");

    // Start providing specific hints for different error types
    if (s) {
        if (strstr(s, "syntax error")) {
            fprintf(stderr, YELLOW "hint: This is a generic syntax error.\n" RESET);
            fprintf(stderr, YELLOW "hint: Check for missing semicolons, parentheses, or incorrect use of keywords.\n" RESET);
        } else if (strstr(s, "unexpected")) {
            const char *unexpected_token = yytext;
            fprintf(stderr, YELLOW "hint: Unexpected token '%s'.\n" RESET, unexpected_token);

            // Provide detailed suggestions based on specific tokens
            if (strstr(yytext, "=")) {
                // Assignment vs. comparison confusion
                fprintf(stderr, YELLOW "hint: Did you mean to use '==' for comparison?\n" RESET);
            } else if (strstr(yytext, ";")) {
                // Semicolon-related issues
                fprintf(stderr, YELLOW "hint: Ensure there is a complete statement before the semicolon.\n" RESET);
            } else if (strstr(yytext, ")") || strstr(yytext, "(")) {
                // Mismatched parentheses
                fprintf(stderr, YELLOW "hint: Check if you have matching opening and closing parentheses.\n" RESET);
            } else if (strstr(yytext, "{") || strstr(yytext, "}")) {
                // Brace mismatches
                fprintf(stderr, YELLOW "hint: Ensure all '{' have corresponding '}' to close blocks.\n" RESET);
            } else {
                // Generic unexpected token hint
                fprintf(stderr, YELLOW "hint: Check the syntax near '%s'.\n" RESET, yytext);
            }
        } else if (strstr(s, "expected")) {
            // Handling of expected tokens
            fprintf(stderr, YELLOW "hint: Expected a different token or expression. Check for missing components.\n" RESET);
        } else {
            // Generic hint for other error messages
            fprintf(stderr, YELLOW "hint: %s\n" RESET, s);
        }
    } else {
        // Fallback hint if no specific message is provided
        fprintf(stderr, YELLOW "hint: Check the syntax near '%s'.\n" RESET, yytext);
    }
}
