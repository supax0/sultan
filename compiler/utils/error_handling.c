#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // For fmin
#include "../builder/outputmsg.h"
#include "../parser/sultanc.tab.h"  // Bison-generated header
// extern int current_language;  // 0 = English, 1 = Arabic
void provide_token_hint(const char *token, const char *error_msg);
int levenshtein(const char *s1, const char *s2);
int is_arabic(const char *text);

extern int yylineno;
extern int yycolumn;
extern char *yytext;
extern char *filename;  // Use the filename from main.c

// Calculate the visual length of UTF-8 strings
int utf8_strlen(const char *s) {
    int length = 0;
    while (*s) {
        if ((*s & 0xC0) != 0x80) {  // Count only the first byte of each UTF-8 character
            length++;
        }
        s++;
    }
    return length;
}

// Print the error line with aligned caret
void print_error_line_with_caret(const char *line, int column) {
    int visual_length = utf8_strlen(line);  // Get visual length of the line
    int caret_pos = fmin(column - 1, visual_length);  // Adjust caret position to fit within the line

    printf("  |\n");  // Print the separator
    printf("%3d | %s", yylineno, line);  // Print the error line

    printf("  | ");
    for (int i = 0; i < caret_pos; i++) {
        if (line[i] == '\t')
            printf("\t");  // Handle tabs
        else
            printf(" ");
    }
    printf(RED "^\n" RESET);  // Print the caret at the appropriate position
}

// Handle parse errors and align caret properly
void handle_parse_error(const char *error_msg) {
    fprintf(stderr, RED "error: %s\n" RESET, error_msg);
    fprintf(stderr, " --> line %d, column %d\n", yylineno, yycolumn);

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return;
    }

    char line[1024];
    int current_line = 1;

    // Read the file line-by-line until the error line is reached
    while (fgets(line, sizeof(line), file)) {
        if (current_line == yylineno) {
            print_error_line_with_caret(line, yycolumn);  // Print the error line with caret
            break;
        }
        current_line++;
    }
    fclose(file);

    provide_token_hint(yytext, error_msg);  // Provide hints based on the error
}

int is_arabic(const char *text) {
    const unsigned char *ptr = (const unsigned char *)text;  // Use unsigned char for proper comparison

    while (*ptr) {
        if ((*ptr >= 0xD8 && *ptr <= 0xD9) && (*(ptr + 1) >= 0x80 && *(ptr + 1) <= 0xBF)) {
            return 1;  // Arabic character found
        }
        ptr++;  // Move to the next byte
    }
    return 0;
}


void provide_token_hint(const char *token, const char *error_msg) {
    if (strstr(error_msg, "unexpected CLPAREN") && strstr(error_msg, "expecting RPAREN")) {
        fprintf(stderr, YELLOW "Hint: You might be missing a closing parenthesis ')'.\n" RESET);
    } else if (strstr(error_msg, "unexpected RPAREN") && strstr(error_msg, "expecting CLPAREN")) {
        fprintf(stderr, YELLOW "Hint: You might be missing an opening parenthesis '('.\n" RESET);
    } else if (strstr(error_msg, "expecting SEMICOLON")) {
        fprintf(stderr, YELLOW "Hint: A semicolon ';' might be missing at the end of this statement.\n" RESET);
    } else if (strstr(error_msg, "expecting IDENTIFIER")) {
        fprintf(stderr, YELLOW "Hint: An identifier (e.g., variable or function name) is expected here.\n" RESET);
    } else if (strstr(error_msg, "expecting STRING_LITERAL")) {
        fprintf(stderr, YELLOW "Hint: A string literal (e.g., \"text\") is expected here.\n" RESET);
    } else if (strstr(error_msg, "expecting NUMBER")) {
        fprintf(stderr, YELLOW "Hint: A number is expected in this expression.\n" RESET);
    } else if (strstr(error_msg, "unexpected EQUALS") && strstr(error_msg, "expecting IDENTIFIER")) {
        fprintf(stderr, YELLOW "Hint: An identifier might be missing before the '=' sign.\n" RESET);
    } else if (strstr(token, "{") && !strstr(token, "}")) {
        fprintf(stderr, YELLOW "Hint: A closing brace '}' might be needed to complete this block.\n" RESET);
    } else if (strstr(token, "(") && !strstr(token, ")")) {
        fprintf(stderr, YELLOW "Hint: A closing parenthesis ')' might be needed to complete this expression.\n" RESET);
    } else if (strstr(error_msg, "expecting LET")) {
        fprintf(stderr, YELLOW "Hint: You might need to declare a variable with 'let'.\n" RESET);
    } else if (strstr(error_msg, "expecting DEF")) {
        fprintf(stderr, YELLOW "Hint: A function definition starting with 'def' is expected.\n" RESET);
    } else if (strstr(error_msg, "expecting IF")) {
        fprintf(stderr, YELLOW "Hint: You might need an 'if' statement to start a conditional block.\n" RESET);
    } else if (strstr(error_msg, "expecting ELSE")) {
        fprintf(stderr, YELLOW "Hint: An 'else' block might be missing to complete the conditional.\n" RESET);
    } else if (strstr(error_msg, "expecting RETURN")) {
        fprintf(stderr, YELLOW "Hint: A 'return' statement might be needed in this function.\n" RESET);
    } else if (strstr(error_msg, "expecting IMPORT")) {
        fprintf(stderr, YELLOW "Hint: Use 'import' to include external libraries or modules.\n" RESET);
    } else if (strstr(error_msg, "expecting MAIN")) {
        fprintf(stderr, YELLOW "Hint: The 'main' function must be defined to start execution.\n" RESET);
    } else if (strstr(error_msg, "expecting INPUT")) {
        fprintf(stderr, YELLOW "Hint: An 'input' statement might be expected to read user input.\n" RESET);
    } else if (strstr(error_msg, "unexpected PLUS")) {
        fprintf(stderr, YELLOW "Hint: Ensure '+' is placed correctly between operands.\n" RESET);
    } else if (strstr(error_msg, "unexpected MINUS")) {
        fprintf(stderr, YELLOW "Hint: Ensure '-' is placed correctly between operands.\n" RESET);
    } else if (strstr(error_msg, "unexpected MULT")) {
        fprintf(stderr, YELLOW "Hint: Ensure '*' is used correctly between operands.\n" RESET);
    } else if (strstr(error_msg, "unexpected DIV")) {
        fprintf(stderr, YELLOW "Hint: Ensure '/' is used correctly between operands.\n" RESET);
    } else if (strstr(error_msg, "unexpected COMMA")) {
        fprintf(stderr, YELLOW "Hint: Check if a comma ',' is misplaced or extra.\n" RESET);
    } else if (strstr(error_msg, "unexpected DOT")) {
        fprintf(stderr, YELLOW "Hint: Ensure '.' is used correctly, such as for accessing attributes.\n" RESET);
    } else if (strstr(error_msg, "unexpected EQUALS") && strstr(error_msg, "expecting NUMBER")) {
        fprintf(stderr, YELLOW "Hint: You might need a number after the '=' sign.\n" RESET);
    } else if (strstr(error_msg, "unexpected GT") || strstr(error_msg, "unexpected LT")) {
        fprintf(stderr, YELLOW "Hint: Ensure '<' or '>' are used correctly for comparisons.\n" RESET);
    } else if (strstr(error_msg, "unexpected EQ") || strstr(error_msg, "unexpected NE")) {
        fprintf(stderr, YELLOW "Hint: Ensure '==' or '!=' are used correctly for comparisons.\n" RESET);
    } else {
        // Use Levenshtein distance to suggest similar tokens if applicable
        if (levenshtein(token, "RPAREN") <= 2) {
            fprintf(stderr, YELLOW "Hint: Did you mean ')'?\n" RESET);
        } else if (levenshtein(token, "SEMICOLON") <= 2) {
            fprintf(stderr, YELLOW "Hint: Did you mean ';'?\n" RESET);
        } else {
            fprintf(stderr, YELLOW "Hint: Review the syntax near this location for potential issues.\n" RESET);
        }
    }
}

int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len2 + 1][len1 + 1];

    for (int i = 0; i <= len2; i++) matrix[i][0] = i;
    for (int j = 0; j <= len1; j++) matrix[0][j] = j;

    for (int i = 1; i <= len2; i++) {
        for (int j = 1; j <= len1; j++) {
            int cost = (s1[j - 1] == s2[i - 1]) ? 0 : 1;
            matrix[i][j] = fmin(
                fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1),
                matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix[len2][len1];
}
