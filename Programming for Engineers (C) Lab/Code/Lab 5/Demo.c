#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortAsc(int *a, int n)
{
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (*(a + i) > *(a + j))
      {
        int t = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = t;
      }
}

void sortDesc(int *a, int n)
{
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (*(a + i) < *(a + j))
      {
        int t = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = t;
      }
}

int main()
{
  int a[50], n = 50, x, count = 0, choice;
  int *p = a;
  void (*sortFunc)(int *, int);

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

  printf("\n1. Ascending\n2. Descending\nChoose sorting order: ");
  scanf("%d", &choice);

  if (choice == 1)
    sortFunc = sortAsc;
  else
    sortFunc = sortDesc;

  sortFunc(p, n);

  printf("\nThe sorted array\n");
  for (int i = 0; i < n; i++)
  {
    printf("%3d ", *(p + i));
    if ((i + 1) % 10 == 0)
      printf("\n");
  }

  printf("\n\nThere are %d values of %d being deleted from the original array.\n", count, x);

  return 0;
}
