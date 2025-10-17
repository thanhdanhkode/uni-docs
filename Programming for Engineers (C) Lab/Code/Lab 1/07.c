#include <stdio.h>

/**
 *
 * This program get student name, id, mark of literature, math, english and print out their name, student id, their mark, total mark and average mark of 3 subjects above
 *
 */
int main()
{
  int id;
  float average_mark, literature_mark, mathematic_mark, english_mark;
  char name[100], student_id[20];

  printf("Input the Name of the student: ");
  scanf("%s", name);
  printf("Input the No of the student: ");
  scanf("%s", student_id);
  printf("Input the marks of Literature, Math and English: ");
  scanf("%f %f %f", &literature_mark, &mathematic_mark, &english_mark);

  average_mark = (literature_mark + mathematic_mark + english_mark) / 3;

  printf("Name of student: %s\n", name);
  printf("ID: %s\n", student_id);
  printf("Mark of Literature: %0.0f\n", literature_mark);
  printf("Mark of Math: %0.0f\n", mathematic_mark);
  printf("Mark of English: %0.0f\n", english_mark);
  printf("Total Marks: %0.0f\n", literature_mark + mathematic_mark + english_mark);
  printf("Average Marks: %0.2f\n", average_mark);

  if (average_mark >= 60)
    printf("Division: A");
  else if (48 <= average_mark < 60)
    printf("Division: B");
  else if (36 <= average_mark < 48)
    printf("Division: Pass");
  else if (average_mark < 36)
    printf("Division: Fail");
  else
    printf("error");

  return 0;
}
