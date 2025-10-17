#include <stdio.h>

/**
 *
 * This program print the input number is a even or odd integer
 *
 */
int main()
{
  int num;
  printf("Enter an integer: "); // Prompt user to input a number
  scanf("%d", &num);

  num % 2 == 0 ? printf("%d is even integer\n", num) : printf("%d is odd integer\n", num);

  return 0;
}
