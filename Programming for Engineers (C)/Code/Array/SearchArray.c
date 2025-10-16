#include <stdio.h>

#define SIZE 10

void searchArray(int y[],int num);

int main(void)
{
  int x[10] = {5, 12, 23, 34, 45, 56, 67, 78, 89, 100}, num;

  printf("Enter your number: ");
  scanf("%d", &num);

  searchArray(x, num);

  printf("Result: \n");
  for (size_t i = 0; i < SIZE; ++i)
  {
    printf("%d ", x[i]);
  }
}

void searchArray(int y[], int num)
{
  for (size_t i = 0; i < SIZE; ++i)
  {
    y[i] = (y[i] == num) ? 1 : 0;
  }
}
