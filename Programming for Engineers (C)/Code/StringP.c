#include <stdio.h>
#include <string.h>

int main()
{
  char string[50] = "Hello world";
  char *token = strtok(string, " ");

  while (token != NULL)
  {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }
  return 0;
}
