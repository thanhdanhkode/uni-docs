#define SIZE 50

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int *size, int order);

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

  printf("\n====== MENU =======\n1. Sort ascending\n2. Sort descending\n3. Exit\n===================\n");
  while (1)
  {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      bubbleSort(ptr, &current_size, 0);

      printf("Sorted Ascending Array:\n");
      for (int i = 0; i < current_size; i++)
      {
        printf("%3d ", *(ptr + i));
        if ((i + 1) % 10 == 0)
        {
          printf("\n");
        }
      }

      break;

    case 2:
      bubbleSort(ptr, &current_size, 1);

      printf("Sorted Descending Array:\n");
      for (int i = 0; i < current_size; i++)
      {
        printf("%3d ", *(ptr + i));
        if ((i + 1) % 10 == 0)
        {
          printf("\n");
        }
      }

      break;

    case 3:
      printf("Exit program...");
      return 0;

    default:
      break;
    }
  }

  return 0;
}

void bubbleSort(int *arr, int *size, int order)
{
  int i, j, temp;
  for (i = 0; i < *size - 1; i++)
  {
    for (j = 0; j < *size - i - 1; j++)
    {
      if (order == 0 && arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
      else if (order == 1 && arr[j] < arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
