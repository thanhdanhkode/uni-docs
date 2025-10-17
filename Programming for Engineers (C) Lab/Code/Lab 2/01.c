#include <stdio.h>

/**
 *
 * This program read 10 integer and count number of positive and negative values among 10 inputs
 *
 */
int main()
{
  // Set x is a array with 10 elements, number of positive and negative number is set to 0 by default
  int x[10], number_positive = 0, number_negative = 0;

  for (int i = 0; i < 10; i++)
  {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &x[i]);
  }

  for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
  {
    if (x[i] > 0)
      number_positive += 1;
    else
      number_negative += 1;
  }

  printf("Number of positive: %d\n", number_positive);
  printf("Number of negative: %d\n", number_negative);

  return 0;
}
