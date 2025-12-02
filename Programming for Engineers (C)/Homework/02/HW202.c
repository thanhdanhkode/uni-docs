#include <stdio.h>

// Function prototype

/// @brief Double every element inside arr using pointer
/// @param arr array
/// @param size size of array
void doubleEven(int *arr, int size);

/// @brief Sort all even number in order and odd number in descending,
/// sorted even numbers will display befor sorted odd numbers
/// @param arr array
/// @param size size of array
void specialSort(int *arr, int size);

/// @brief Reset all odd numbers in arr to 0
/// @param arr array
/// @param size size of array
void resetOdd(int *arr, int size);

/**
 * Print Arr with data contain the digits of the student id and their birthday
 */
int main()
{
  // Declare variable
  int myINFO[] = {2, 4, 0, 1, 8, 15, 1};
  int *ptr = &myINFO[0], size = sizeof(myINFO) / sizeof(myINFO[0]);

  printf("Original Array: \n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(ptr + i));
  }

  printf("\nAfter running doubleEven() function\nResult: ");
  doubleEven(ptr, size);

  printf("\nAfter running specialSort() function\nResult: ");
  specialSort(ptr, size);

  printf("\nAfter running resetOdd() function\nResult: ");
  resetOdd(ptr, size);

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
