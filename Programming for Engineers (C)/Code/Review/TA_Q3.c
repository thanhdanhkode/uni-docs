#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Generate_Array_1D(int a[100])
{
  int value;
  for (int i = 0; i < 100; i++)
  {
    do
    {
      value = 100 + rand() % (900);
    } while (value % 4 != 0);
    a[i] = value;
  }
}

void Sort_Array_1D(int a[100])
{
  for (int i = 0; i < 100; i++)
  {
    for (int j = i + 1; j < 100; j++)
    {
      if (a[i] > a[j])
      {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }
}

void Print_Array_1D(int a[100])
{
  for (int i = 0; i < 100; i++)
  {
    printf("%4d ", a[i]);
    if ((i + 1) % 10 == 0)
    {
      printf("\n");
    }
  }
}

int main()
{
  srand(time(NULL));

  int a[100];

  Generate_Array_1D(a);

  printf("Original Array: \n");
  Print_Array_1D(a);

  Sort_Array_1D(a);

  printf("\nSorted Array: \n");
  Print_Array_1D(a);

  return 0;
}
