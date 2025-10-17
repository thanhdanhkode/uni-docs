#include <stdio.h>

/**
 *
 * This program calculate the diameter, circumference, area of a circle with custom unit
 *
 */
int main()
{
  float radius;
  char unit[5];

  printf("Enter the unit: ");
  scanf("%s", unit);
  printf("Enter the radius of circle: ");
  scanf("%f", &radius);

  printf("Diameter of circle: %0.2f %s\n", 2 * radius, unit);
  printf("Circumference of circle: %0.2f %s\n", 2 * 3.14 * radius, unit);
  printf("Area of circle: %0.2f sq. %s\n", 3.14 * radius * radius, unit);

  return 0;
}
