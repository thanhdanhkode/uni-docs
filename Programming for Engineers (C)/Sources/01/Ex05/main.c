#include <stdio.h>
#include <math.h>

int main()
{
  float a, b, c, x1, x2, delta;

  printf("Enter the value of a: ");
  scanf("%f", &a);
  printf("Enter the value of b: ");
  scanf("%f", &b);
  printf("Enter the value of c: ");
  scanf("%f", &c);

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
