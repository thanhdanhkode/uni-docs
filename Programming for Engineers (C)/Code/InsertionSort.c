#include <stdio.h>

#define SIZE 5 // Define size of array

void insertSort(int a[]); // FUnction Prototype

/**
 *
 * This program demonstrate the insertion sort in the simple way
 */
int main()
{
  int array[SIZE] = {5, 3, 6, 12, 21};

  insertSort(array);

  for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
  {
    printf("%d ", array[i]);
  }

  return 0;
}

void insertSort(int a[])
{
  for (size_t i = 1; i < SIZE; ++i)
  {
    int k = a[i], j = i - 1;

    while (j >= 0 && a[j] > k)
    {
      a[j + 1] = a[j];
      j -= 1;
    }

    a[j + 1] = k;
  }
}
