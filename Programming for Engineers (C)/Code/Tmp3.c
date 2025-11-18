#include <stdio.h>

void printArray(int const b[])
{
  b[0] += 2;
  b[1] += 2;
  b[2] += 2;
}

int main()
{
  int a[3] = {1, 2, 3};
  printArray(a);
  printf("%d %d %d", a[0], a[1], a[2]);

  return 0;
}
