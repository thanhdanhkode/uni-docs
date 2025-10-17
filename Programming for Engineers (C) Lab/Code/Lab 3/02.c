#include <stdio.h>

int reverseNumber(int num);

int main()
{
  int num;

  printf("Enter a integer: ");
  scanf("%d", &num);

  printf("Reversed digits: %d", reverseNumber(num));
  return 0;
}
/**
 *
 * This function return the reverse integer number of the input integer number
 *
 * @example
 * // return 4321
 * reverseNumber(1234)
 * 
 * @return Reversed Number
 *
 */
int reverseNumber(int num)
{
  int reversedNum = 0, reminder;

  while (num != 0)
  {
    reminder = num % 10;
    reversedNum = reversedNum * 10 + reminder;
    num /= 10;
  }

  return reversedNum;
}
