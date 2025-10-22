#include <stdio.h>

#define SIZE 5

/**
 *
 * This program reverse an array
 *
 */
int main()
{
  int array[SIZE] = {2, 5, 6, 8, 12};
  int tmp, start = 0, end = SIZE - 1;

  for (size_t i = 0; i < SIZE; i++)
  {
    tmp = array[start];
    array[start] = array[end];
    array[end] = tmp;

    if (start < end) break;

    start++;
    end--;
  }

  for (size_t i = 0; i < SIZE; i++)
  {
    printf("%d ", array[i]);
  }


  return 0;
}
