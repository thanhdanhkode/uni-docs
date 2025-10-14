#include <stdio.h>

int binToDec(int y)
{
  int base = 1, decimal = 0;

  while (y)
  {
    int ld = y % 10;
    y /= 10;
    decimal += ld * base;
    base *= 2;
  }

  return decimal;
}

int main()
{
  int x;

  printf("Enter binary value: ");
  scanf("%d", &x);

  printf("Decimal: %d", binToDec(x));

  return 0;
}
