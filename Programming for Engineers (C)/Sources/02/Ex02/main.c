#include <stdio.h>

/**
 * !IMPORTANT NOTE: Add white-space befor the format specifier '%c' because input buffer may contain white-space or a newline character which may break the program in while-loop
 */

int main()
{
  char x, y;

  while (1)
  {
    printf("Enter a grade: ");
    scanf(" %c", &x);

    switch (x)
    {
    case 'A':
      printf("Excellent!\n");
      break;
    case 'B':
      printf("Good!\n");
      break;
    case 'C':
      printf("Fair!\n");
      break;
    case 'D':
      printf("Average!\n");
      break;
    case 'F':
      printf("Weak!\n");
      break;
    default:
      printf("Invalid\n");
      break;
    }

    printf("Do you want to continue? ");
    scanf(" %c", &y);
    if (y == 'y')
      continue;
    else
    {
      printf("Exit program...");
      break;
    }
  }

  return 0;
}
