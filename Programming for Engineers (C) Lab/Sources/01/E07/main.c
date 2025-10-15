#include <stdio.h>

int main()
{
  int id;
  float average_mark, literature_mark, mathematic_mark, english_mark;
  char name[100];

  printf("Input the Name of the student: ");
  scanf("%s", &name);
  printf("Input the No of the student: ");
  scanf("%d", &id);
  printf("Input the marks of Literature, Math and English: ");
  scanf("%f %f %f", &literature_mark, &mathematic_mark, &english_mark);

  average_mark = (literature_mark + mathematic_mark + english_mark) / 3;

  printf("Name of student: %c\n", name);
  printf("ID: %d\n", id);
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
