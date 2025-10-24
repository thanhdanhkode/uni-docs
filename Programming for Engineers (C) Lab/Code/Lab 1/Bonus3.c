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

  while (x != 0)
  {
    int reminder = x % 10;
    x /= 10;
    decimal += reminder * base;
    base *= 2;
  }

  printf("Decimal: %d", decimal);

  return 0;
}
