#include <stdio.h>
#include <math.h>

/**
 *
 * This program calculate the sum of series
 *
 */
int main()
{
  int x, y = 1, term, sum = 0;

  printf("Input the value of x: ");
  scanf("%d", &x);
  printf("Input number of terms: ");
  scanf("%d", &term);

  for (int i = 1; i <= term; i++)
  {
    sum += -pow(-1, i) * pow(x, y);
    y += 2;
  }

  printf("The sum of series: %d", sum);

  return 0;
}
