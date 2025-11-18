#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Create and print the array with user input size
 * @param printOut boolean
 */
float *createArray(bool printOut);
float findClosest(float a[], float target);

/**
 *
 * Write a C program that reads a floating array with M elements (M is read from user)
 * The program will:
 *   - print the original array
 *   - read a value then find the nearest element to the given given value
 *
 */
int main()
{
  float target;
  int array_size = 0;
  float *array = createArray(true);

  if (array != NULL)
  {
    printf("Enter target value: ");
    scanf("%f", target);
    printf("The nearest value to target (%f): %f", target, findClosest(array, target));
    free(array); // Important: Free the allocated memory
  }
  else
  {
    printf("Memory allocation failed.\n");
  }

  return 0;
}

float *createArray(bool printOut)
{
  int array_size;

  printf("Enter array size: ");
  scanf("%d", &array_size);

  float *array = malloc(sizeof(float) * array_size);

  if (array == NULL)
    return NULL;

  for (size_t i = 0; i < array_size; i++)
  {
    printf("Enther Element [%d]: ", i);
    scanf("%f", &array[i]);
  }

  if (printOut)
  {
    printf("Original Array: \n");
    for (size_t i = 0; i < array_size; i++)
    {
      printf("%.2f ", array[i]);
      if (i == array_size - 1)
        printf("\n");
    }
  }

  return array;
}

float findClosest(float a[], float target)
{
  int array_size = sizeof(a) / sizeof(a[0]);
  int result = a[0];

  for (size_t i = 0; i < array_size; i++)
  {
    if (abs(a[i] - target) <= abs(result - target))
      result = a[i];
  }

  return result;
}
