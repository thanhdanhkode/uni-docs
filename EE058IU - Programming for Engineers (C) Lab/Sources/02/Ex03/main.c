#include <stdio.h>
#include <math.h>

int main()
{
  int x, y = 1, t, sum = 0;

  printf("Input the value of x: ");
  scanf("%d", &x);
  printf("Input number of terms: ");
  scanf("%d", &t);

  for (int i = 1; i <= t; i++)
  {
    sum += -pow(-1, i) * pow(x, y);
    y += 2;
  }

  printf("The sum of series: %d", sum);

  return 0;
}
