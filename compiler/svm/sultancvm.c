#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/evp.h>  // For cryptographic operations
#include "sultancvm.h"
#include "../utils/error_handling.h"
#include "../builder/sultancore.h"

// Function to handle VM-specific errors using handle_parse_error
void handle_vm_error(const char *context, const char *details) {
    char error_message[256];
    snprintf(error_message, sizeof(error_message), "Error in %s: %s", context, details ? details : "Unknown error");
    handle_parse_error(error_message);  // Use the custom error handler
}

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Main function to run the Sultanc Virtual Machine
int SultancVirtualMachine(int file_count, char **file_names) {
    if (file_count < 1) {
        handle_vm_error("SultancVirtualMachine", "No files to process.");
        return 1;
    }

    // Step 1: Ensure the cache directory exists
    struct stat st = {0};
    if (stat("cache", &st) == -1) {
        if (mkdir("cache", 0755) != 0) {
            handle_vm_error("SultancVirtualMachine", "Failed to create cache directory.");
        }
    }

    for (int i = 0; i < file_count; i++) {
        const char *input_filename = file_names[i];

        // Step 2: Generate paths for cache files based on input filename
        char base_name[256];
        snprintf(base_name, sizeof(base_name), "%s", input_filename);
        char *dot = strrchr(base_name, '.');
        if (dot) *dot = '\0';  // Remove extension

        char exec_filename[256];
        snprintf(exec_filename, sizeof(exec_filename), "cache/%s_exec", base_name);

        // Step 3: Check if executable exists and if content has changed
        if (file_exists(exec_filename)) {
            printf(POINTER_FORMAT, GREEN, "Using cached executable for ", input_filename);
            printf("%s\n", RESET);
        } else {
            // No cached executable, invoke CompileSultanC to compile the .sn file
            printf(POINTER_FORMAT, YELLOW, "Compiling ", input_filename);
            printf("%s\n", RESET);

            char *compile_args[] = { "sultanc", (char *)input_filename, NULL };
            if (CompileSultanC(2, compile_args) != 0) {
                handle_vm_error("SultancVirtualMachine", "Failed to compile .sn file.");
            }

            // Rename the output executable to the cache directory
            char output_filename[256];
            snprintf(output_filename, sizeof(output_filename), "target/debug/%s", base_name);
            rename(output_filename, exec_filename);
        }

        // Step 4: Execute the cached or newly compiled executable
        FILE *exec_output = popen(exec_filename, "r");
        if (exec_output == NULL) {
            handle_vm_error("SultancVirtualMachine", "Failed to execute the compiled file.");
        }

        // Print output of the executed file
        char buffer_output[128];
        while (fgets(buffer_output, sizeof(buffer_output), exec_output) != NULL) {
            printf("%s", buffer_output);
        }

        pclose(exec_output);
    }

    return 0;  // Success
}
