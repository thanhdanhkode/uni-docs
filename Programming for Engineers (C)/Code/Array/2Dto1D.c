#include <stdio.h>

#define ROWS 2
#define COLS 3

/**
 *
 * This program represent a 2D array by a 1D array
 *
 */
int main()
{
  int twoDArray[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
  int oneDArray[ROWS * COLS];
  int k = 0;

  printf("2D Array:\n");
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", twoDArray[i][j]);
    }
    printf("\n");
  }

  // Convert 2D array to 1D array
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      oneDArray[k] = twoDArray[i][j];
      k++;
    }
  }

  printf("\n1D Array:\n");
  for (int i = 0; i < (ROWS * COLS); i++)
  {
    printf("%d ", oneDArray[i]);
  }
  printf("\n");

  return 0;
}
