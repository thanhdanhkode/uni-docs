#include <stdio.h>

int main()
{
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
