#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../builder/sultancore.h"

// Function declarations

int build();

void display_help();
void display_version();

int main(int argc, char **argv) {
    if (argc < 2) {
        display_help();
        return 1;
    }

    // Determine the command
    if (strcmp(argv[1], "build") == 0) {
       // Ensure directories are created before building
        return Builder(); // Use Builder function from sultancore.h
    } else if (strcmp(argv[1], "run") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: No input file specified.\n");
            display_help();
            return 1;
        }
        int compile_mode = (argc > 3 && strcmp(argv[2], "-c") == 0) ? 1 : 0;
        return Run(); // Use Run function from sultancore.h
    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        display_version();
        return 0;
    } else {
        fprintf(stderr, "Error: Unknown command '%s'.\n", argv[1]);
        display_help();
        return 1;
    }
}
// Function to display help information
void display_help() {
    printf("Usage: sultan [command]\n");
    printf("Commands:\n");
    printf("  build      Build the project\n");
    printf("  run        Run the project\n");
    printf("  clean      Clean build files\n");
    printf("  -v, --version Display the version\n");
}

// Function to display version information
void display_version() {
    printf("Sultan Compiler v1.0.0\n");
}
