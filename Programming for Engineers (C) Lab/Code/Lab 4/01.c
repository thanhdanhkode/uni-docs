#include <stdio.h>

#define MAX_SIZE 1000

int create_array(float array[], int max_size)
{
  int n;
  printf("Enter array size (1-%d): ", max_size);
  if (scanf("%d", &n) != 1)
    return 0;
  if (n <= 0)
    n = 0;
  if (n > max_size)
    n = max_size;
  printf("Enter the elements:\n");
  for (int i = 0; i < n; ++i)
  {
    if (scanf("%f", &array[i]) != 1)
    {
      for (int j = i; j < n; ++j)
        array[j] = 0.0f;
      break;
    }
  }
  return n;
}

void sort_array(float array[], int array_size)
{
  for (int i = 0; i < array_size; ++i)
  {
    for (int j = 0; j < array_size - 1; ++j)
    {
      if (array[j] > array[j + 1])
      {
        float t = array[j];
        array[j] = array[j + 1];
        array[j + 1] = t;
      }
    }
  }
}

int insert_element(float array[], int array_size, float element, int max_size)
{
  if (array_size >= max_size)
  {
    printf("Array full, cannot insert element.\n");
    return array_size;
  }
  array[array_size] = element;
  return array_size + 1;
}

void print_array(float array[], int array_size)
{
  for (int i = 0; i < array_size; ++i)
  {
    printf(" %.0f", array[i]);
  }
  printf("\n");
}

int main(void)
{
  float array[MAX_SIZE] = {0.0f};
  int size = create_array(array, MAX_SIZE);
  if (size <= 0)
  {
    printf("No elements to process.\n");
    return 0;
  }

  printf("Input elements array are: ");
  print_array(array, size);

  sort_array(array, size);
  printf("Sorted list is: ");
  print_array(array, size);

  float element;
  printf("Enter element to be inserted: ");
  scanf("%f", &element);
  size = insert_element(array, size, element, MAX_SIZE);
  sort_array(array, size);
  printf("Final list is: ");
  print_array(array, size);
  return 0;
}
