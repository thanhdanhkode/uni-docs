#include <stdio.h>

int main()
{
  int x, y, z;

  printf("Input three sides of triangle: ");
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
