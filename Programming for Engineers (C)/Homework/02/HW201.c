#include <stdio.h>

/**
 * Print Array with data contain the digits of the student id and their birthday
 */
int main()
{
  // Declare variable
  int myINFO[] = {2, 4, 0, 1, 8, 15, 1};
  int *ptr = &myINFO[0]; // Asign address of the first element in array myINFO into pointer
  int size = sizeof(myINFO) / sizeof(myINFO[0]); // size of the array

  printf("Array using pointer: \n");
  printf("Index\tValue\tMemory Address\n");
  printf("----\t-----\t--------------\n");

  for (int i = 0; i < size; i++)
  {
    // *(ptr + i) is the value of index (i) in the myINFO array
    // (void *)(ptr +i) is the memory address of the value, similar to (void *)&myINFO[i]
    printf("[%d]\t%d\t%p\n", i, *(ptr + i), (void *)(ptr + i));
  }

  return 0;
}
