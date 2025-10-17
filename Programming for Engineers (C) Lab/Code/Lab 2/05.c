#include <stdio.h>
/**
 *
 * This program covert a Binary number to Decimal number using iterations
 *
 */
int main()
{
  int x, base = 1, decimal = 0;

  printf("Enter binary value: ");
  scanf("%d", &x);

  while (x)
  {
    int ld = x % 10;
    x /= 10;
    decimal += ld * base;
    base *= 2;
  }

  printf("Decimal: %d", binToDec(x));

  return 0;
}
