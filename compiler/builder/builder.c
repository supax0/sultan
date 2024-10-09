#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sultancore.h"

// Function to get system architecture (e.g., arm64, x86_64)
const char* get_system_architecture() {
    FILE *fp;
    char buffer[128];
    static char architecture[128];

    // Use uname to detect system architecture
    fp = popen("uname -m", "r");
    if (fp == NULL) {
        printf(POINTER_FORMAT, RED, "Error: Failed to detect system architecture.\n", RESET);
        return NULL;
    }

    // Get the architecture information
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strncpy(architecture, buffer, sizeof(architecture) - 1);
        architecture[strcspn(architecture, "\n")] = '\0'; // Remove newline
    }
    pclose(fp);

    return architecture;
}

// Function to build the sultanc compiler
int Builder() {
    const char *arch = get_system_architecture();
    if (!arch) {
        return 1;
    }

    printf(POINTER_FORMAT, YELLOW, "Starting to build the sultanc compiler...\n", RESET);

    // Command to compile the sultanc compiler
    char compile_command[1024];

    // Determine flags and libraries based on system architecture
    if (strcmp(arch, "arm64") == 0) {
        // Mac ARM-specific libraries and flags
        snprintf(compile_command, sizeof(compile_command), 
                 "gcc -I/opt/homebrew/opt/openssl/include -L/opt/homebrew/opt/openssl/lib "
                 "../interface/main.c ../builder/driver.c  ../parser/sultanc.tab.c ../lexer/lex.yy.c "
                 "../svm/sultancvm.c ../utils/helpers.c ../utils/error_handling.c ../utils/parser_helpers.c "
                 "-o ../bin/sultanc -lssl -lcrypto -ll `pkg-config --cflags --libs gtk+-3.0`");
    } else if (strcmp(arch, "x86_64") == 0) {
        // x86_64-specific libraries and flags
        snprintf(compile_command, sizeof(compile_command), 
                 "gcc -I/usr/local/include -L/usr/local/lib "
                 "../interface/main.c ../builder/driver.c   ../parser/sultanc.tab.c ../lexer/lex.yy.c "
                 "../svm/sultancvm.c ../utils/helpers.c ../utils/error_handling.c ../utils/parser_helpers.c "
                 "-o ../bin/sultanc -lssl -lcrypto -ll `pkg-config --cflags --libs gtk+-3.0`");
    } else {
        printf(POINTER_FORMAT, RED, "Error: Unsupported architecture.\n", RESET);
        return 1;
    }

    // Execute the compile command
    printf(POINTER_FORMAT, YELLOW, "Compiling sultanc...\n", RESET);
    if (system(compile_command) != 0) {
        printf(POINTER_FORMAT, RED, "Error: Compilation failed.\n", RESET);
        return 1;
    }

    printf(POINTER_FORMAT, GREEN, "Compilation successful.\n", RESET);

    // Create a symbolic link in /usr/local/bin for system-wide access
    printf(POINTER_FORMAT, YELLOW, "Creating symbolic link in /usr/local/bin for system-wide access...\n", RESET);
    if (system("sudo ln -sf $(pwd)/../bin/sultanc /usr/local/bin/sultanc") != 0) {
        printf(POINTER_FORMAT, RED, "Error: Failed to create symbolic link in /usr/local/bin. Check your permissions.\n", RESET);
        return 1;
    }

    printf(POINTER_FORMAT, GREEN, "Symbolic link created successfully. You can now use 'sultanc' system-wide.\n", RESET);

    // Write the path of the compiled sultanc to core.txt (no output about the path)
    FILE *path_file = fopen("../bin/core.txt", "w");
    if (path_file == NULL) {
        printf(POINTER_FORMAT, RED, "Error: Failed to create core.txt.\n", RESET);
        return 1;
    }

    // Get the real path of the sultanc binary and write to core.txt
    char real_path[512];
    if (realpath("../bin/sultanc", real_path) == NULL) {
        printf(POINTER_FORMAT, RED, "Error: Failed to resolve the real path of sultanc.\n", RESET);
        fclose(path_file);
        return 1;
    }

    // Append the real path to core.txt
    fprintf(path_file, "sultanc path: %s\n", real_path);
    fclose(path_file);

    printf(POINTER_FORMAT, GREEN, "core.txt created successfully.\n", RESET);

    return 0;
}
