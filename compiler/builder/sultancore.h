#ifndef SULTANCORE_H
#define SULTANCORE_H

// Color codes for output
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

// Format for the pointer output
#define POINTER_FORMAT "%s=> %s%s"

// Declare functions
const char* get_system_architecture();
int CompileSultanC(int argc, char **argv);  // Correct name for the compile function
int Run();  // Function for running other commands
int Builder();
// Declare external global variable irFile
extern FILE *irFile;


#endif // SULTANCORE_H
