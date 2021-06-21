#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct row
{
    int index, addr, lineno;
    char *name;
    char *type_name;
    char *element_type;
} row;

typedef struct scope
{
    int scope_level;
    int row_num;
    struct row c[50];
} scope;

#endif /* COMMON_H */