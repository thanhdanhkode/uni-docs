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

  delta = pow(b, 2) - 4 * a * c;
  if (a == 0 && b == 0 && c == 0)
    printf("This is not a quadratic equation");
  else if (delta > 0)
  {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    printf("The root of equation are x1 = %0.2f, x2 = %0.2f\b", x1, x2);
  }
  else if (delta == 0)
    printf("Equation has double roots: %f", -b / (2 * a));
  else
  {
    printf("Equation has no real root");
  }

  return 0;
}
