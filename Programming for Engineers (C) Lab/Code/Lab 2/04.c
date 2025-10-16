#include <stdio.h>

int main()
{
  int x, factorial = 1;

  printf("Enter a positive number: ");
  scanf("%d", &x);

  for (int i = 1; i <= x; i++)
  {
    factorial *= i;
  }

  printf("Factorial: %d", factorial);

  return 0;
}
