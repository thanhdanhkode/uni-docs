#include <stdio.h>

/**
 *
 * This program calculate the factorial of a positive number
 *
 */
int main()
{
  int num, factorial = 1;

  printf("Enter a positive number: ");
  scanf("%d", &num);

  if (num < 0)
  {
    printf("Input number must be a positive number!");
    return 0;
  }

  for (int i = 1; i <= num; i++)
  {
    factorial *= i;
  }

  printf("Factorial: %d", factorial);

  return 0;
}
