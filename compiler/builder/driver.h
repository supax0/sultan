#ifndef DRIVER_H
#define DRIVER_H

#include <stdio.h>  // Add this line to fix FILE type error
#include <stdlib.h>
#include <string.h>

void create_directories();
void generate_file_paths(const char *input_filename, char *c_filename);
int parse_input_file(const char *input_filename);
int compile_files(int argc, char **argv);
int CompileSultanC(int argc, char **argv);
extern FILE *irFile;
#endif  // DRIVER_H
