#include <stdio.h>

/**
 *
 * This program check input is the triangle or not, and print what type of that triangle
 *
 */
int main()
{
  int x, y, z;

  printf("Input three sides of triangle: "); // Prompt user to input three sides of a triangle
  scanf("%d %d %d", &x, &y, &z);

  if (x + y > z && x + z > y && y + z > x)
  {
    if (x == y && x == z)
    {
      printf("This is an equilateral triangle");
    }
    else if (x == y || x == z || y == z)
    {
      printf("This is an isosceles triangle");
    }
    else
    {
      printf("This is a scalene triangle");
    }
  }
  else
  {
    printf("This is not a triangle");
  }

  return 0;
}
