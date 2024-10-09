// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../utils/helpers.h"
// #include "../utils/error_handling.h"
// #include "../utils/parser_helpers.h"
// #include "../builder/SultanCore.h"

// int CompileSultanC(int argc, char **argv) {
//     create_directories();

//     // Array to store the paths of all generated C files
//     char c_filenames[argc - 1][256];

//     // Loop through each input file
//     for (int i = 1; i < argc; i++) {
//         char *input_filename = argv[i];
//         char c_filename[256];
//         generate_file_paths(input_filename, c_filename);
//         strcpy(c_filenames[i - 1], c_filename);  // Store the path of the generated C file

//         printf("Starting to parse %s...\n", input_filename);
//         if (parse_sn_file(input_filename, c_filename) != 0) {
//             fprintf(stderr, RED "Parsing failed for file: %s\n" RESET, input_filename);
//             return EXIT_FAILURE;
//         }
//     }

//     return EXIT_SUCCESS;
// }
