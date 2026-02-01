#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENTS 30

int main()
{
  int scores[NUM_STUDENTS];
  int *p_array = scores;
  int max_score = 0;
  int pass_count = 0;
  int fail_count = 0;

  // 1. Generate random scores (40-95) and print them
  srand(time(NULL)); // Seed the random number generator
  for (int i = 0; i < NUM_STUDENTS; i++)
  {
    scores[i] = rand() % (95 - 40 + 1) + 40;
    printf("Score %d: %d\n", i + 1, scores[i]);
  }

  // 2. Find the maximum score using a pointer
  for (int i = 0; i < NUM_STUDENTS; i++)
  {
    if (scores[i] > max_score)
    {
      max_score = scores[i];
    }
  }

  printf("\nMaximum score: %d\n", max_score);

  // 3. Apply the grading curve
  for (int i = 0; i < NUM_STUDENTS; i++)
  {
    double scaled_score = (double)scores[i] / max_score * 100;
    scores[i] = (int)scaled_score; // Convert back to integer, truncating
  }

  printf("\nUpdated scores:\n");
  for (int i = 0; i < NUM_STUDENTS; i++)
  {
    printf("Score %d: %d\n", i + 1, scores[i]);
  }

  // 4. Get statistics and print the result
  for (int i = 0; i < NUM_STUDENTS; i++)
  {
    if (scores[i] >= 50)
    {
      pass_count++;
    }
    else
    {
      fail_count++;
    }
  }

  printf("\nPass count (>= 50): %d\n", pass_count);
  printf("Fail count (< 50): %d\n", fail_count);

  return 0;
}
