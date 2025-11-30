#include <stdio.h>

/**
 * Print Array with data contain the digits of the student id and their birthday
 */
int main()
{
  int myINFO[] = {2, 4, 0, 1, 8, 15, 1};
  int *ptr = &myINFO[0];

  printf("Array using pointer: \n");
  printf("Index\tValue\tMemoryAddress\n");
  printf("----\t-----\t--------------\n");

  for (size_t i = 0; i < sizeof(myINFO) / sizeof(myINFO[0]); i++)
  {
    printf("[%d]\t%d\t0x%x\n", i, *(ptr + i), (void *)(ptr + i));
  }

  return 0;
}
