#include <stdio.h>

int GCD(int x, int y);

int main()
{
  int a, b;

  printf("Enter two integers: ");
  scanf("%d %d", &a, &b);

  printf("GCD of %d and %d is %d\n", a, b, GCD(a, b));

  return 0;
}

int GCD(int x, int y)
{
  if (y == 0)
    return x;
  return GCD(y, x % y);
}
