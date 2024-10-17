// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../builder/driver.h"
#include "../builder/outputmsg.h"
#include "../cli/command.h"

// External declarations
extern int yyparse(void);
extern int CompileSultanC(int argc, char **argv);

// Define the filename globally
char *filename = NULL;  // Define filename variable

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, POINTER_FORMAT, RED, "Error: No input files provided.\n", RESET);
        return EXIT_FAILURE;
    }

    filename = argv[argc - 1];  // Initialize filename with the input file

    if (argc == 3 && strcmp(argv[1], "-c") == 0) {
        if (CompileSultanC(argc - 1, &argv[1]) != 0) {
            return EXIT_FAILURE;
        }
    } else {
        if (handle_commands(argv[1]) != 0) {
            printf("Use '-c' to compile sn files.\n");
            printf("Use 'alive' to start the server.\n");
            printf("Use 'stop' to stop the server.\n");

            // Future plan: Sultanc Virtual Machine (SVM) implementation
            // Planned to behave like a JVM but without Java. Supports JIT compilation and execution.
        }
    }

    return EXIT_SUCCESS;
}
