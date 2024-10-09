// error_handling.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_handling.h"
#include "../builder/sultancore.h"
#include "../parser/sultanc.tab.h"  // Include Bison-generated header

extern int yylineno;
extern int yycolumn;
extern char *yytext;

void handle_parse_error(const char *s) {
    fprintf(stderr, RED "error: %s\n" RESET, s);
    fprintf(stderr, " --> line %d, column %d\n", yylineno, yycolumn);
    fprintf(stderr, "  |\n");
    fprintf(stderr, "%3d | %s\n", yylineno, yytext);
    fprintf(stderr, "  | %*s" RED "^\n" RESET, yycolumn, "");

    if (s) {
        if (strstr(s, "syntax error")) {
            fprintf(stderr, YELLOW "hint: Check for missing semicolons, parentheses, or incorrect syntax near '%s'\n" RESET, yytext);
        } else if (strstr(s, "unexpected")) {
            const char *unexpected_token = yytext;
            fprintf(stderr, YELLOW "hint: Unexpected token '%s'.\n" RESET, unexpected_token);
            if (strstr(yytext, "=")) {
                fprintf(stderr, YELLOW "hint: Did you mean to use '==' for comparison?\n" RESET);
            } else if (strstr(yytext, ";")) {
                fprintf(stderr, YELLOW "hint: Check for missing statement before the semicolon.\n" RESET);
            } else {
                fprintf(stderr, YELLOW "hint: Check the syntax near '%s'.\n" RESET, yytext);
            }
        } else {
            fprintf(stderr, YELLOW "hint: %s\n" RESET, s);
        }
    } else {
        fprintf(stderr, YELLOW "hint: Check syntax near '%s'\n" RESET, yytext);
    }
}
