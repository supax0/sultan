#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "../parser/sultanc.tab.h"
#include "driver.h"
#include "outputmsg.h"

// External declaration of the Flex input function
extern int yyparse();
extern FILE *yyin;
FILE *irFile = NULL;  // Global declaration of irFile

// Helper function to create directories for output
void create_directories() {
    mkdir("target", 0755);
    mkdir("target/IR", 0755);
}

// Helper function to generate file paths for output `.c` files based on input filename
void generate_file_paths(const char *input_filename, char *c_filename) {
    char *base_name = strdup(input_filename);
    char *dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';  // Remove the extension if present

    sprintf(c_filename, "target/IR/%s.c", base_name);  // Construct the path for the IR file
    free(base_name);
}

// Function to find a compatible compiler
const char* find_compiler() {
    if (system("gcc --version > /dev/null 2>&1") == 0) {
        return "gcc";
    } else if (system("clang --version > /dev/null 2>&1") == 0) {
        return "clang";
    } else {
        return NULL;  // No compatible compiler found
    }
}

// Main function for compiling `.sn` files into C files and building the executable
int CompileSultanC(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, POINTER_FORMAT, RED, "Error: No input files provided. Please specify at least one .sn file.\n", RESET);
        return 1;
    }

    create_directories();  // Create necessary directories for output

    for (int i = 1; i < argc; i++) {
        char *input_filename = argv[i];
        char c_filename[256];

        generate_file_paths(input_filename, c_filename);

        FILE *inputFile = fopen(input_filename, "r");
        if (!inputFile) {
            fprintf(stderr, POINTER_FORMAT, RED, "Error: Unable to open the file: ", input_filename);
            fprintf(stderr, "%s\n", RESET);
            return 1;
        }

        yyin = inputFile;

        irFile = fopen(c_filename, "w");
        if (!irFile) {
            fprintf(stderr, POINTER_FORMAT, RED, "Error: Unable to create C file: ", c_filename);
            fprintf(stderr, "%s\n", RESET);
            fclose(inputFile);
            return 1;
        }

        printf(POINTER_FORMAT, YELLOW, "Parsing started for: ", input_filename);
        printf("%s\n", RESET);

        int parseResult = yyparse();

        if (parseResult != 0) {
            fprintf(stderr, POINTER_FORMAT, RED, "Parsing failed. Check the syntax in the file: ", input_filename);
            fprintf(stderr, "%s\n", RESET);
            fclose(inputFile);
            fclose(irFile);
            remove(c_filename);
            return 1;
        }

        fclose(inputFile);
        fclose(irFile);
    }

    const char *compiler = find_compiler();
    if (!compiler) {
        fprintf(stderr, POINTER_FORMAT, RED, "Error: No compatible compiler found. Ensure that gcc or clang is installed.\n", RESET);
        return 1;
    }

    char compile_command[1024] = {0};
    sprintf(compile_command, "%s", compiler);

    for (int i = 1; i < argc; i++) {
        char c_filename[256];
        generate_file_paths(argv[i], c_filename);
        strcat(compile_command, " ");
        strcat(compile_command, c_filename);
    }

    char *base_name = strdup(argv[1]);
    char *dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';

    char executable_path[512];
    sprintf(executable_path, "target/%s", base_name);
    
    strcat(compile_command, " -o ");
    strcat(compile_command, executable_path);

    free(base_name);

    int compile_result = system(compile_command);
    if (compile_result != 0) {
        fprintf(stderr, POINTER_FORMAT, RED, "Compilation failed.\n", RESET);
        return 1;
    }

    printf(POINTER_FORMAT, GREEN, "Compilation successful. Executable created at: ", executable_path);
    printf("%s\n", RESET);

    return 0;
}
