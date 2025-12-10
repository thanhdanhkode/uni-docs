#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int main()
{
  int arr[SIZE];
  int *ptr = arr;
  int val, i, count = 0;
  int current_size = SIZE;

  srand(time(0));

  for (i = 0; i < SIZE; i++)
  {
    *(ptr + i) = rand() % 50 + 1;
  }

  printf("The original array\n");
  for (i = 0; i < SIZE; i++)
  {
    printf("%3d", *(ptr + i));
    if ((i + 1) % 10 == 0)
    {
      printf("\n");
    }
  }
  printf("\n");

  printf("Enter a value (from 1 to 50) to be deleted = ");
  scanf("%d", &val);

  int *write_ptr = arr;
  int *read_ptr = arr;

  for (i = 0; i < SIZE; i++)
  {
    if (*read_ptr == val)
    {
      count++;
    }
    else
    {
      *write_ptr = *read_ptr;
      write_ptr++;
    }
    read_ptr++;
  }

  current_size = SIZE - count;

  printf("The new array\n");
  if (current_size == 0)
  {
    printf("(Array is empty)\n");
  }
  else
  {
    for (i = 0; i < current_size; i++)
    {
      printf("%3d ", *(ptr + i));
      if ((i + 1) % 10 == 0)
      {
        printf("\n");
      }
    }
  }

  puts("");

  printf("There are %d values of %d being deleted from the original array\n", count, val);

  return 0;
}
