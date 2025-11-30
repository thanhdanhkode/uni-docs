#include <stdio.h>

// Function prototype
void doubleEvent(int *arr, int size);
void specialSort(int *arr, int size);
void resetOdd(int *arr, int size);
void sortAlgorithm(int *arr, int size, int order);

/**
 *
 */
int main()
{
  int myINFO[] = {2, 4, 0, 1, 8, 15, 1};
  int *ptr = &myINFO[0], size = sizeof(myINFO) / sizeof(myINFO[0]);
  void (*function_pts[3])(int *, int) = {doubleEvent, specialSort, resetOdd};

  printf("Current array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(ptr + i));
  }
  puts("");

  printf("\n=============== MENU ==================\n1. Double even numbers (doubleEven)\n2. Special sort (specialSort)\n3. Reset odd numbers to 0 (resetOdd)\n4. Exit program\n=======================================\n");
  puts("");
  puts("");

  while (1)
  {
    int choice;
    printf("Select function (1-4): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Double even numbers: ");
      function_pts[0](ptr, size);
      puts("\n");
      break;
    case 2:
      printf("Special Sort: ");
      function_pts[1](ptr, size);
      puts("\n");
      break;
    case 3:
      printf("Reset odd numbers: ");
      function_pts[2](ptr, size);
      puts("\n");
      break;
    case 4:
      printf("Exiting program. Goodbye!\n");
      return 0;
    default:
      printf("Invalid options! Try again\n");
      puts("\n");
      break;
    }
  }

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
