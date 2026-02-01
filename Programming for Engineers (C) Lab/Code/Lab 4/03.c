#include <stdio.h>

int main()
{
  int size, i, j, k;

  printf("Enter N (0 < N < 11): ");
  scanf("%d", &size);

  if (size <= 0 || size >= 11)
  {
    printf("Size must be greater than 0 and less than 11.\n");
    return 1;
  }

  for (i = 1; i <= size; i++)
  {
    for (j = 1; j <= size - i; j++)
    {
      printf(" ");
    }
    for (k = 1; k <= 2 * i - 1; k++)
    {
      printf("*");
    }
    printf("\n");
  }

  for (i = size - 1; i >= 1; i--)
  {
    for (j = 1; j <= size - i; j++)
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
