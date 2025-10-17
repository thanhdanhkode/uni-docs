#include <stdio.h>
#include <math.h>

int factorial(int x)
{
  int r = 1;
  for (int i = 1; i <= x; i++)
  {
    r *= i;
  }

  return r;
}

/**
 *
 * This program calculate the sin(𝑥) which is described in the series in the question file
 *
 */
int main()
{
  float x, sin;
  int n, y = 1;
  printf("Enter the value of x: ");
  scanf("%f", &x);
  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
  {
    sin += -pow(-1, i) * (pow(x, y) / factorial(y));
    y += 2;
  }

  printf("The value of sin(%0.2f) = %0.4f", x, sin);

  return 0;
}
