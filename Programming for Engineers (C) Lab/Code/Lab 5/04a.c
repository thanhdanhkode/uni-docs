#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int a[50], n = 50, x, count = 0;
  int *p = a;

  srand(time(NULL));

  printf("The original array\n");
  for (int i = 0; i < n; i++)
  {
    *(p + i) = rand() % 50 + 1;
    printf("%3d ", *(p + i));
    if ((i + 1) % 10 == 0)
      printf("\n");
  }

  printf("\nEnter a value (from 1 to 50) to be deleted = ");
  scanf("%d", &x);

  for (int i = 0; i < n; i++)
  {
    if (*(p + i) == x)
      count++;
    else
      *(p + i - count) = *(p + i);
  }

  n -= count;

  printf("\nThe new array\n");
  for (int i = 0; i < n; i++)
  {
    printf("%3d ", *(p + i));
    if ((i + 1) % 10 == 0)
      printf("\n");
  }

  printf("\n\nThere are %d values of %d being deleted from the original array.\n", count, x);

  return 0;
}
