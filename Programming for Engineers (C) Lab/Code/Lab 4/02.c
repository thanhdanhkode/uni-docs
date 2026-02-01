#include <stdio.h>

void bubbleSort(int arr[], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap elements if they are in the wrong order
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int n1, n2, n3, i;
  // Define a maximum size for the arrays
  int max_size = 100;
  int arr1[max_size], arr2[max_size], merged[max_size * 2];

  // --- Input First Array ---
  do
  {
    printf("Enter the number of elements for the first array\n: ");
    scanf("%d", &n1);
    if (n1 <= 0)
    {
      printf("Error: Array length cannot be zero or negative. Please try again.\n");
    }
    else if (n1 > max_size)
    {
      printf("Error: Max size is %d.\n", max_size);
      n1 = 0; // force loop to continue
    }
  } while (n1 <= 0);

  printf("Input first array elements (%d numbers):\n", n1);
  for (i = 0; i < n1; i++)
  {
    scanf("%d", &arr1[i]);
  }

  // --- Input Second Array ---
  do
  {
    printf("Enter the number of elements for the second array: ");
    scanf("%d", &n2);
    if (n2 <= 0)
    {
      printf("Error: Array length cannot be zero or negative. Please try again.\n");
    }
    else if (n2 > max_size)
    {
      printf("Error: Max size is %d.\n", max_size);
      n2 = 0; // force loop to continue
    }
  } while (n2 <= 0);

  printf("Input second array elements (%d numbers): ", n2);
  for (i = 0; i < n2; i++)
  {
    scanf("%d", &arr2[i]);
  }

  // --- Merge Arrays ---
  n3 = n1 + n2;

  // Copy first array to merged array
  for (i = 0; i < n1; i++)
  {
    merged[i] = arr1[i];
  }

  // Append second array to merged array
  for (i = 0; i < n2; i++)
  {
    merged[n1 + i] = arr2[i];
  }

  // --- Sort Merged Array ---
  bubbleSort(merged, n3);

  // --- Output Result ---
  printf("\nMerged array in ascending order = ");
  for (i = 0; i < n3; i++)
  {
    printf("%d", merged[i]);
    if (i < n3 - 1)
    {
      printf(", ");
    }
  }
  printf("\n");

  return 0;
}
