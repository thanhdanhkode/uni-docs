#include <stdio.h>
#include <math.h>

int main()
{
  float x;

  printf("Enter the radius of circle: ");
  scanf("%f", &x);

  printf("Diameter of circle: %0.2f\n", 2 * x);
  printf("Circumference of circle: %0.2f\n", 2 * 3.14 * x);
  printf("Circumference of circle: %0.2f\n", 3.14 * pow(x, 2));

  return 0;
}
