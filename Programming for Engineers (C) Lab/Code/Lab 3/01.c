#include <stdio.h>
#include <math.h>

/**
 *
 * This program read several numbers and rounds  each  of  these  numbers  to  the
nearest integer, print the original number and rounded one
 * - **rounded**(double number)**: rounded number to the nearest integer
 * - **floor(double number)**: rounded number DOWN to the nearest integer
 *
 */
int main()
{
  float num, rounded_num;

  printf("Enter a number: ");
  scanf("%f", &num);

  rounded_num = round(num);
  printf("Original number: %.3f and rounded number: %.3f", num, rounded_num);

  return 0;
}
