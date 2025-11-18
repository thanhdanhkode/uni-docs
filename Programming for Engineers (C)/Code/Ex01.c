#include <stdio.h>

int main()
{
  int x, y;
  printf("Enter two integers: ");
  scanf("%d %d", &x, &y);

  if (x > y)
    printf("Integer 1 is larger than integer 2");
  else if (x < y)
    printf("Integer 1 is smaller than integer 2");
  else
    printf("Integer 1 is equal to integer 2");

  return 0;
}
