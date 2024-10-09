#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

Variable declared_vars[MAX_VARS];
int declared_count = 0;

int is_declared(const char *var) {
    for (int i = 0; i < declared_count; i++) {
        if (strcmp(declared_vars[i].name, var) == 0) {
            return 1;
        }
    }
    return 0;
}

void declare_var(const char *var, const char *type) {
    if (declared_count < MAX_VARS) {
        declared_vars[declared_count].name = strdup(var);
        declared_vars[declared_count].type = strdup(type);
        declared_count++;
    }
}

const char* get_var_type(const char *var) {
    for (int i = 0; i < declared_count; i++) {
        if (strcmp(declared_vars[i].name, var) == 0) {
            return declared_vars[i].type;
        }
    }
    return NULL;
}
