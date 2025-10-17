#include <stdio.h>
#include <math.h>

/**
 *
 * This program calculate the roots of the second order equation
 *
 */
int main()
{
  float a, b, c, x1, x2, delta = 0;

  printf("Enter the value of a, b, c: ");
  scanf("%f %f %f", &a, &b, &c);

  delta = b * b - 4 * a * c;
  if (delta < 0)
    printf("Equation has no solution");
  else if (delta == 0)
    printf("Equation has double roots: %f", -b / (2 * a));
  else
  {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    printf("The solution x1: %0.2f\n", x1);
    printf("The solution x2: %0.2f\n", x2);
  }

  return 0;
}
