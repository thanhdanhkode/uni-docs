#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
  int id;
  int point;
} Student;

int main()
{
  int n = 10;
  Student *students = malloc(sizeof(Student) * (size_t)n);

  if (!students)
  {
    perror("malloc");
    return 1;
  }

  srand((unsigned)time(NULL));
  for (int i = 0; i < n; ++i)
  {
    /* ID range 1000..9999 (arbitrary choice) */
    students[i].id = rand() % 9000 + 1000;
    /* points range 0..100 */
    students[i].point = rand() % 101;
  }

  int max_idx = 0;
  for (int i = 1; i < n; ++i)
  {
    if (students[i].point > students[max_idx].point)
    {
      max_idx = i;
    }
  }

  printf("\nGenerated students:\n");
  for (int i = 0; i < n; ++i)
  {
    printf("%d:\tID: %d\tPoints: %d\n", i + 1, students[i].id, students[i].point);
  }

  printf("\nTop student: ID: %d, Points: %d\n",
         students[max_idx].id, students[max_idx].point);

  free(students);
  return 0;
}
