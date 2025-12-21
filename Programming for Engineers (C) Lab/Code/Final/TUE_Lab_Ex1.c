#include <stdio.h>

#define SIZE 10
#define STUDENT_NAME "John"

int main()
{
  int i, j, k, z = 1;

  for (i = 1; i <= SIZE; i++)
  {
    for (j = 1; j <= SIZE - i; j++)
    {
      printf(" ");
    }
    for (k = 1; k <= 2 * i - 1; k++)
    {
      if (i == 10 && k > 6 && k < 13)
      {
        if (z)
          printf(" %s ", STUDENT_NAME);
        z = 0;
      }
      else
      {
        printf("*");
      }
    }
    printf("\n");
  }

  for (i = SIZE - 1; i >= 1; i--)
  {
    for (j = 1; j <= SIZE - i; j++)
    {
      printf(" ");
    }
    for (k = 1; k <= 2 * i - 1; k++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
