#include <stdio.h>

#define SIZE 5

/**
 *
 * This program find the second minium in a array
 *
 */
int main()
{
  int array[SIZE] = {3, 5, 7, 8, 9}, min = array[0], sec_min = __INT_MAX__;

  for (size_t i = 0; i < SIZE; i++)
  {
    min = min > array[i] ? array[i] : min;
  }

  for (size_t i = 0; i < SIZE; i++)
  {
    sec_min = array[i] != min && array[i] < sec_min ? array[i] : sec_min;
  }

  printf("Min: %d, Second Min: %d", min, sec_min);

  return 0;
}
