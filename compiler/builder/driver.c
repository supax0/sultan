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
#include "../builder/sultancore.h"

// External declaration of the Flex input function
extern int yyparse();
extern FILE *yyin;
FILE *irFile = NULL;  // Global declaration of irFile

// Helper function to create directories for output
void create_directories() {
    mkdir("target", 0755);
    mkdir("target/debug", 0755);
    mkdir("target/debug/IR", 0755);
}

// Helper function to generate file paths for output `.c` files based on input filename
void generate_file_paths(const char *input_filename, char *c_filename) {
    // Derive output file name from input filename
    char *base_name = strdup(input_filename);
    char *dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';  // Remove the extension if present

    sprintf(c_filename, "target/debug/IR/%s.c", base_name);  // Add .c extension for the IR file
    free(base_name);
}

// Function to find a compatible compiler
const char* find_compiler() {
    if (system("gcc --version > /dev/null 2>&1") == 0) {
        return "gcc";
    } else if (system("clang --version > /dev/null 2>&1") == 0) {
        return "clang";
    } else {
        return NULL;
    }
}

// Main function for compiling `.sn` files into C files and building the executable
int CompileSultanC(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, POINTER_FORMAT, RED, "Error: No input files provided.\n", RESET);
        return 1;
    }

    create_directories();  // Create necessary directories for output

    // Loop through each input file
    for (int i = 1; i < argc; i++) {
        char *input_filename = argv[i];
        char c_filename[256];

        // Generate output C file path based on input filename
        generate_file_paths(input_filename, c_filename);

        // Open the input .sn file
        FILE *inputFile = fopen(input_filename, "r");
        if (!inputFile) {
            fprintf(stderr, POINTER_FORMAT, RED, "Error: Could not open file ", input_filename);
            fprintf(stderr, "%s\n", RESET);
            return 1;
        }

        yyin = inputFile;

        // Open the output C file
        irFile = fopen(c_filename, "w");
        if (!irFile) {
            fprintf(stderr, POINTER_FORMAT, RED, "Error: Could not create C file ", c_filename);
            fprintf(stderr, "%s\n", RESET);
            fclose(inputFile);
            return 1;
        }

        printf(POINTER_FORMAT, YELLOW, "Starting to parse ", input_filename);
        printf("%s\n", RESET);

        int parseResult = yyparse();

        // Handle parsing failure
        if (parseResult != 0) {
            fprintf(stderr, POINTER_FORMAT, RED, "Parsing failed. Check the syntax in ", input_filename);
            fprintf(stderr, "%s\n", RESET);
            fclose(inputFile);
            fclose(irFile);
            remove(c_filename);  // Clean up the partially created file
            return 1;
        }

        fclose(inputFile);
        fclose(irFile);
    }

    // Find a compatible compiler and build the executable
    const char *compiler = find_compiler();
    if (!compiler) {
        fprintf(stderr, POINTER_FORMAT, RED, "No compatible compiler found (gcc or clang).\n", RESET);
        return 1;
    }

    // Build the compile command using the derived file paths
    char compile_command[1024] = {0};
    sprintf(compile_command, "%s", compiler);
    for (int i = 1; i < argc; i++) {
        char c_filename[256];
        generate_file_paths(argv[i], c_filename);
        strcat(compile_command, " ");
        strcat(compile_command, c_filename);  // Add each C file to the command
    }

    // Use the input file name as the base for the executable name
    char *base_name = strdup(argv[1]);
    char *dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';  // Remove the extension

    strcat(compile_command, " -o target/debug/");
    strcat(compile_command, base_name);  // Output executable will be named after the input file

    free(base_name);

    // Execute the compilation command
    int compile_result = system(compile_command);
    if (compile_result != 0) {
        fprintf(stderr, POINTER_FORMAT, RED, "Compilation failed.\n", RESET);
        return 1;
    }

    printf(POINTER_FORMAT, GREEN, "Compilation successful. Executable created: ", base_name);
    printf("%s\n", RESET);

    return 0;
}
