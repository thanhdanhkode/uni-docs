#include <stdio.h>

void binarySearch(int a[], int key, size_t low, size_t high);
int insertSorted(int a[], int n, int key, int capacity);
/**
 *
 * This program insert an element into a sorted array
 *
 */
int main()
{
  return 0;
}

void binarySearch(int a[], int key, size_t low, size_t high) {
  while (low < high) {
    size_t middle = (low + high) /2;

    if (key == a[middle]) return middle;
    else if (key < a[middle]) high = middle - 1;
    else low = middle;

    return -1;
  }
}
