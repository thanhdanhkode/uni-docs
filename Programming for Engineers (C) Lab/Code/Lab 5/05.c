#include <stdio.h>

// Function prototype
int min(int *arr, int *size);
int max(int *arr, int *size);

int main()
{
  int size;
  int (*function[2])(int *, int *) = {min, max};

  printf("Enter size of array: ");
  scanf("%d", &size);

  int array[size];
  int *arr = array;
  for (int i = 0; i < size; i++)
  {
    printf("Element [%d]: ", i);
    scanf("%d", (arr + i));
  }

  printf("The input array:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%3d", *(arr + i));
    if ((i + 1) % 10 == 0)
      printf("\n");
  }

  int minVal = function[0](arr, &size);
  int maxVal = function[1](arr, &size);

  printf("\nMinimum value in array: %d", minVal);
  printf("\nMaximum value in array: %d", maxVal);

  return 0;
}

int min(int *arr, int *size)
{
  int result = arr[0];
  for (int i = 1; i < *size; i++)
  {
    if (arr[i] < result)
    {
      result = arr[i];
    }
  }
  return result;
}

int max(int *arr, int *size)
{
  int result = arr[0];
  for (int i = 1; i < *size; i++)
  {
    if (arr[i] > result)
    {
      result = arr[i];
    }
  }
  return result;
}
