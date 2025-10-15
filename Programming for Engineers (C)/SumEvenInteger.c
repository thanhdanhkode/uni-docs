#include <stdio.h>

int main()
{
  int sum = 0;

  for (int i = 2; i <= 50; i++)
  {
    if (i % 2 == 0)
    {
      sum += i;
    }
  }

  printf("Sum of even integers from 2 to 50 is: %d\n", sum);

  return 0;
}
