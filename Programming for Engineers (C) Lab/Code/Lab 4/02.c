#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int array1[100];
  int array2[100];
  int mergedArraySize = 0;
  int mergedArray[200];
  int userInput;

  printf("Input first array elements (end with -1):\n");
  for (size_t i = 0; i < 100; i++)
  {
    int value;
    if (scanf("%d", &value) != 1 || value == -1)
      break;
    array1[i] = value;
    mergedArraySize++;
  }

  printf("Input second array elements (end with -1):\n");
  for (size_t i = 0; i < 100; i++)
  {
    int value;
    if (scanf("%d", &value) != 1 || value == -1)
      break;
    array2[i] = value;
    mergedArraySize++;
  }

  for (size_t i = 0; i < 100; i++)
  {
    mergedArray[i] = array1[i];
  }

  for (size_t i = 0; i < 100; i++)
  {
    mergedArray[i + 100] = array2[i];
  }

  // for (size_t i = 0; i < 200; i++)
  // {
  //   printf("%d ", mergedArray[i]);
  // }

  printf("Enter array 3 size: ");
  scanf("%d", &userInput);
  int array3[userInput];

  for (size_t i = 0; i < userInput; i++)
  {
    scanf("%d", &array3[i]);
  }

  return 0;
}
