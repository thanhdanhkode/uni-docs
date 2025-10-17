#include <stdio.h>
/**
 *
 * This program check the input year is a leap year or not
 *
 */
int main()
{
  int year;

  printf("Input a year: "); // Prompt user to input a year
  scanf("%d", &year);       // Get year from user

  // Condition block for checking input year is a leap year
  if (year % 4 == 0)
  {
    printf("%d is a leap year", year);
  }
  else if (year % 4 == 0 && year % 100 != 0)
  {
    printf("%d is a leap year", year);
  }
  else
  {
    printf("%d is not a leap year", year);
  }

  return 0;
}
