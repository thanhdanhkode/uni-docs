#include <stdio.h>

// Function prototype
void doubleEvent(int *arr, int size);
void specialSort(int *arr, int size);
void resetOdd(int *arr, int size);
void sortAlgorithm(int *arr, int size, int order);

/**
 * Print Array with data contain the digits of the student id and their birthday
 */
int main()
{
  int myINFO[] = {2, 4, 0, 1, 8, 15, 1};
  int *ptr = &myINFO[0], size = sizeof(myINFO) / sizeof(myINFO[0]);

  printf("Original Array: \n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(ptr + i));
  }

  printf("\nAfter running doubleEvent() function\nResult: ");
  doubleEvent(ptr, size);

  printf("\nAfter running specialSort() function\nResult: ");
  specialSort(ptr, size);

  printf("\nAfter running resetOdd() function\nResult:");
  resetOdd(ptr, size);

  return 0;
}

void doubleEvent(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(arr + i) * 2);
  }
};

void specialSort(int *arr, int size)
{
  int evens[size], odds[size];
  int eCount = 0, oCount = 0;

  for (int i = 0; i < size; i++)
  {
    if (*(arr + i) % 2 == 0)
    {
      evens[eCount++] = *(arr + i);
    }
    else
    {
      odds[oCount++] = *(arr + i);
    }
  }

  sortAlgorithm(evens, eCount, 0);
  sortAlgorithm(odds, oCount, 1);

  for (int i = 0; i < eCount; i++)
  {
    printf("%d ", evens[i]);
  }

  for (int i = 0; i < oCount; i++)
  {
    printf("%d ", odds[i]);
  }
};

void resetOdd(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    if ((*(arr + i)) % 2 != 0)
    {
      *(arr + i) = 0;
    }
  }

  for (int i = 0; i < size; i++)
  {
    printf("%d ", (*(arr + i)));
  }
};

void sortAlgorithm(int *arr, int size, int order)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - 1; j++)
    {
      if (order == 0 && arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
      else if (order == 1 && arr[j] < arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
};
