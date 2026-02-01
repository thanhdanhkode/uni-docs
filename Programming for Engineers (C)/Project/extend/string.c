#pragma warning(disable : 4996)

#include <extend/string.h>

int streq(const char *a, const char *b)
{
	return strcmp(a, b) == 0;
}

char *trim(char *s)
{
	if (!s)
		return s;
	while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n')
		s++;
	char *end = s + strlen(s) - 1;
	while (end > s && (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n'))
		*end-- = '\0';
	return s;
}
