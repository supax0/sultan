#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "sultanc.tab.h"

// External declaration of the Flex input function
extern int yyparse();
extern FILE *yyin;

FILE *irFile = NULL;  // Define irFile globally

// Helper function to create directories if they do not exist
void create_directories() {
    mkdir("target", 0755);
    mkdir("target/debug", 0755);
    mkdir("target/debug/IR", 0755);
}

// Helper function to generate file paths
void generate_file_paths(const char *input_filename, char *c_filename) {
    char *base_name = strdup(input_filename);
    char *dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';

    sprintf(c_filename, "target/debug/IR/%s.c", base_name);

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

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file1.sn> <input_file2.sn> ... <input_fileN.sn>\n", argv[0]);
        return 1;
    }

    create_directories();

    // Array to store the paths of all generated C files
    char c_filenames[argc - 1][256];

    // Loop through each input file
    for (int i = 1; i < argc; i++) {
        char *input_filename = argv[i];
        char c_filename[256];
        generate_file_paths(input_filename, c_filename);
        strcpy(c_filenames[i - 1], c_filename);  // Store the path of the generated C file

        // Open the input .sn file
        FILE *inputFile = fopen(input_filename, "r");
        if (!inputFile) {
            fprintf(stderr, "Error: Could not open file %s\n", input_filename);
            return 1;
        }

        yyin = inputFile;

        // Open the output C file
        irFile = fopen(c_filename, "w");
        if (!irFile) {
            fprintf(stderr, "Error: Could not create C file %s\n", c_filename);
            fclose(inputFile);
            return 1;
        }

        printf("Starting to parse %s...\n", input_filename);
        int parseResult = yyparse();

        // Handle parsing failure
        if (parseResult != 0) {
            fprintf(stderr, "Parsing failed. Check the syntax in %s.\n", input_filename);
            fclose(inputFile);
            fclose(irFile);
            remove(c_filename);  // Clean up the partially created file
            return 1;
        }

        fclose(inputFile);
        fclose(irFile);
    }

    // Find a compatible compiler
    const char *compiler = find_compiler();
    if (!compiler) {
        fprintf(stderr, "No compatible compiler found (gcc or clang).\n");
        return 1;
    }

    // Build the compile command with all the C files
    char compile_command[1024] = {0};
    sprintf(compile_command, "%s", compiler);
    for (int i = 0; i < argc - 1; i++) {
        strcat(compile_command, " ");
        strcat(compile_command, c_filenames[i]);
    }
    strcat(compile_command, " -o target/debug/main");

    // Execute the compilation command
    int compile_result = system(compile_command);
    if (compile_result != 0) {
        fprintf(stderr, "Compilation failed.\n");
        return 1;
    }

    printf("Compilation successful. Executable created: target/debug/main\n");
    return 0;
}
