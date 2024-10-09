#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../builder/sultancore.h"
#include "../svm/sultancvm.h"

// External declarations for yyparse and CompileSultanC
extern int yyparse(void);
extern int CompileSultanC(int argc, char **argv);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, POINTER_FORMAT, RED, "Error: No input files provided.\n", RESET);
        return EXIT_FAILURE;
    }

    if (argc == 3 && strcmp(argv[1], "-o") == 0) {
        // Compile the .sn file as a C file and executable
        if (CompileSultanC(argc - 1, &argv[1]) != 0) {
            return EXIT_FAILURE;
        }
    } else {
        // Use the virtual machine mode
        if (SultancVirtualMachine(argc - 1, &argv[1]) != 0) {
            return EXIT_FAILURE;
        }
    }

    printf(POINTER_FORMAT, GREEN, "SultanC compilation and execution completed successfully.\n", RESET);

    return EXIT_SUCCESS;
}
