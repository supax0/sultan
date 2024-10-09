#include <stdio.h>
#include <stdlib.h>  // Include this for the system() function
#include "sultancore.h"

int Run() {
    printf(POINTER_FORMAT, YELLOW, "Running sultanc compiler\n", RESET);
    system("../bin/sultanc");  // This calls the sultanc executable
    return 0;
}
