#include <stdio.h>

// Function prototype

/// @brief Double every element inside arr using pointer
/// @param arr arr
/// @param size size of arr
void doubleEven(int *arr, int size);

/// @brief Sort all even number in order and odd number in descending, sorted even numbers will display befor sorted odd numbers
/// @param arr arr
/// @param size size of arr
void specialSort(int *arr, int size);

/// @brief Reset all odd numbers in arr to 0
/// @param arr arr
/// @param size size of arr
void resetOdd(int *arr, int size);

/**
 *
 */
int main()
{
  int myINFO[] = {2, 4, 0, 1, 8, 15, 1};
  int *ptr = &myINFO[0], size = sizeof(myINFO) / sizeof(myINFO[0]);
  void (*function_pts[3])(int *, int) = {doubleEven, specialSort, resetOdd};

  printf("Current arr: ");
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

void doubleEven(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (*(arr + i) % 2 == 0)
      printf("%d ", *(arr + i) *= 2);
    else
      printf("%d ", *(arr + i));
  }
};

void specialSort(int *arr, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {

      // Get values using pointer arithmetic
      int current = *(arr + j);
      int next = *(arr + j + 1);

      int shouldSwap = 0; // Boolean flag (0 = false, 1 = true)

      // Check if numbers are Even or Odd
      // (Using absolute value | 1 to handle negative numbers safely if needed)
      int currentIsEven = (current % 2 == 0);
      int nextIsEven = (next % 2 == 0);

      // --- COMPLEX SWAP LOGIC ---

      // 1. PRIMARY RULE: Put Evens before Odds
      if (!currentIsEven && nextIsEven)
      {
        // Current is Odd, Next is Even -> SWAP to push Even forward
        shouldSwap = 1;
      }
      // 2. SECONDARY RULE: If groups are same, check sorting order
      else if (currentIsEven && nextIsEven)
      {
        // Both Even -> Ascending (Swap if current > next)
        if (current > next)
          shouldSwap = 1;
      }
      else if (!currentIsEven && !nextIsEven)
      {
        // Both Odd -> Descending (Swap if current < next)
        if (current < next)
          shouldSwap = 1;
      }

      // --- PERFORM SWAP IF NEEDED ---
      if (shouldSwap)
      {
        int temp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = temp;
      }
    }
  }

  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(arr + i));
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
