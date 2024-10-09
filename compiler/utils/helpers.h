#ifndef HELPERS_H
#define HELPERS_H

#define MAX_VARS 100

typedef struct {
    char *name;
    char *type;
} Variable;

extern Variable declared_vars[MAX_VARS];
extern int declared_count;

int is_declared(const char *var);
void declare_var(const char *var, const char *type);
const char* get_var_type(const char *var);

#endif
