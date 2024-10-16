#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../builder/driver.h"
#include "../builder/outputmsg.h"
#include "../cli/command.h"  // Include the new command functionality

// External declarations for yyparse and CompileSultanC
extern int yyparse(void);
extern int CompileSultanC(int argc, char **argv);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, POINTER_FORMAT, RED, "Error: No input files provided.\n", RESET);
        return EXIT_FAILURE;
    }

    if (argc == 3 && strcmp(argv[1], "-c") == 0) {
        if (CompileSultanC(argc - 1, &argv[1]) != 0) {
            return EXIT_FAILURE;
        }
    } else {
        if (handle_commands(argv[1]) != 0) {
            printf("Use '-c' to compile sn files.\n");
            printf("Use 'alive' to start the server.\n");
            printf("Use 'stop' to stop the server.\n");



            //this part is planed to add sultan Virtual Machine, the plan to work as JVM with no java in place. therefor its called SVM
            // the author plan to make jit compiler and run time meaning the compiler will have 2 modes
            //normal mode to compile into c or any file that clang/gcc can compile to.
            // the SVM mode this meant to do all and run auto with no files or folders are created
        //     int status = SultancVirtualMachine(argc - 1, &argv[1]);
        // if (status != 0) {
        //     fprintf(stderr, "Virtual machine execution failed with error: %s\n", strerror(errno));
        //     return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
