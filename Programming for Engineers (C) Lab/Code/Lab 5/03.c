#include <stdio.h>

/**
 * Write a C program that reads through an array using pointer. Then, scan through this array
 * to find a particular value (using the pointer).
 */
int main()
{
  int size;
  int *p_size = &size;

  printf("Enter a size of array: ");
  scanf("%d", p_size);

  int array[*p_size], *arr = array;

  for (int i = 0; i < *p_size; ++i)
  {
    printf("Enter element a[%i]: ", i);
    scanf("%d", (arr + i));
  }

  for (int i = 0; i < *p_size; ++i)
  {
    printf("%i ", *(arr + i));
  }

  puts("");

  while (1)
  {
    int key, found = 0, index = 0;
    int *p_key = &key;
    printf("Enter a search key: ");
    scanf("%d", p_key);

    int *p = arr;
    for (int i = 0; i < *p_size; ++i, ++p)
    {
      if (*p == *p_key)
      {
        index = i + 1;
      }
      *p == *p_key ? index = i + 1 : index;
      *p == *p_key ? 1 : 0;
    }

    if (found != 0)
    {
      printf("The search key is in the position: %d", index);
      return 0;
    }
    else
      printf("No position was found !!!\n");
  }

  return 0;
}
