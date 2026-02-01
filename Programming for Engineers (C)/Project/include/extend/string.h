#ifndef EXTENDED_STRING_H
#define EXTENDED_STRING_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int streq(const char *a, const char *b);
int strsplit(const char *str, const char *delim, char ***tokens, int *token_size);
char *trim(char *s);

#endif // !VALKORIA_STRING_H
