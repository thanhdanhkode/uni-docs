/*
Write a C program to perform a grading curve task for a class of 30 students

1. In main(), generate random scores(40 - 95) for students. Print the original scores using standard array indexing
2. Create a pointer p_array linked to your array. Pas it to a function findMax() to find and return the highest score. Print this max score in main()
3. Pass p_arr and the max score to a function applyCurve. Scale everyone's grade so the highest scores becomes 100. Print the updated scores in main() using pointer notation only.
4. Pass p_array to function getStats(). Return both the pass count (>= 50) and fail count(< 50) to main(). Print the result in main().

*/

#define STUDENT_SIZE 30

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNumber();
int findMax(int *arr);
int applyCurve(int *arr, int maxScore);
void getStats(int *arr, int *pass_count, int *fail_count);

int main()
{
  srand(time(NULL));
  int arr[STUDENT_SIZE] = {0};
  int *p_arr = arr;

  printf("Original student's scores: ");
  for (size_t i = 0; i < STUDENT_SIZE; i++)
  {
    arr[i] = generateNumber();
    printf("%d ", arr[i]);
  }
  puts("");

  int maxScore = findMax(p_arr);
  printf("Max score: %d\n", maxScore);

  applyCurve(p_arr, maxScore);

  printf("Updated student's score: ");
  for (size_t i = 0; i < STUDENT_SIZE; i++)
  {
    printf("%d ", *(arr + i));
  }
  puts("");

  int pass_count = 0;
  int fail_count = 0;

  getStats(p_arr, &pass_count, &fail_count);
  printf("No. of passed students: %d\n", pass_count);
  printf("No. of failed students: %d\n", fail_count);

  return 0;
}

int generateNumber()
{
  int number = rand() % (95 - 40 + 1) + 40;
  return number;
}

int findMax(int *arr)
{
  int max = *arr;

  for (size_t i = 0; i < STUDENT_SIZE; i++)
  {
    if (*(arr + i) > max)
    {
      max = *(arr + i);
    }
  }

  return max;
}

int applyCurve(int *arr, int maxScore)
{
  for (size_t i = 0; i < STUDENT_SIZE; i++)
  {
    double scaled_score = (double)(*arr + i) / maxScore * 100;
    if (scaled_score > 100)
    {
      *(arr + i) = 100;
    }
    else
    {
      *(arr + i) = (int)scaled_score;
    }
  }
}

void getStats(int *arr, int *pass_count, int *fail_count)
{
  for (size_t i = 0; i < STUDENT_SIZE; i++)
  {
    if (*(arr + i) >= 50)
      *pass_count += 1;
    else
      *fail_count += 1;
  }
}
