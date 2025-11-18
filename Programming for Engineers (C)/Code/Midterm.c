#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Function Prototype
/**
 * This function will print the output to console following the question format, with custom title
 * @param array array
 * @param title char
 */
void printArray(int array[], char *title);
/**
 * This function will sort the input array, method: Bubble sort
 * @param array - array
 */
void sortArrayDescending(int array[]);
/**
 * This function will random integer number
 * @return number
 */
int randomNumber();

/**
 * Write a program to work with a 50-element integer array initialized with random numbers between 0 and 100.
 * Your program must:
 * Print the initial array (10 values per line, 3 spaces between values).
 * Sort the array in descending order and print the result using the same format.
 * Program requirements (for full credit):
 * Create a dedicated function for printing the array (10 points).
 * Create a dedicated function for sorting the array (20 points).
 * Use the proper library function(s) for random number generation (10 points)
 */
int main()
{
  srand(time(NULL));

  int array[SIZE];

  for (size_t i = 0; i < SIZE; i++)
  {
    array[i] = randomNumber();
  }

  printArray(array, "Original Array (50 elements)");

  puts("");

  sortArrayDescending(array);

  printArray(array, "Sorted Array (Descending Order)");

  return 0;
}

void printArray(int array[], char *title)
{
  printf("--- %s ---\n", title);
  printf("-----------------------------------------------\n");

  for (size_t i = 0; i < SIZE; i++)
  {
    printf("%3d", array[i]);
    if ((i + 1) % 10 == 0)
    {
      printf("\n");
    }
  }

  printf("-----------------------------------------------\n");
}

void sortArrayDescending(int array[])
{
  // Bubble sort (Descending)
  for (size_t i = 0; i < SIZE; ++i)
  {
    for (size_t j = 0; j < SIZE - 1; j++)
    {
      if (array[j] < array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int randomNumber()
{
  int result = rand() % 101;
  return result;
}
