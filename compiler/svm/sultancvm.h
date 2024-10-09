#ifndef SULTANCVM_H
#define SULTANCVM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/evp.h>  // For cryptographic operations

// Function to handle VM-specific errors
void handle_vm_error(const char *context, const char *details);

// Function to generate a hash for a file's content using EVP
void generate_file_hash(const char *filename, char *hash_output);

// Function to check if the content of the file has changed
int has_content_changed(const char *input_filename, const char *hash_filename);

// The main function for the virtual machine, responsible for compiling and caching files
int SultancVirtualMachine(int file_count, char **file_names);


#endif // SULTANCVM_H
