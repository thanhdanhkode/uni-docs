#include <stdio.h>

// NOTE: The docs block below is created for the built-in function documentation of VS Code or any other IDEs.
/**
 * main - Prompt for a number and print a row of asterisks
 *
 * Repeatedly asks the user to enter an integer between 1 and 20.
 * If the input is within the valid range, prints that many '*' characters.
 * If the input is outside the range, prints "Invalid" and exits the loop.
 *
 * @return 0 on successful completion.
 */
int main()
{
  // Declare variables
  int num;

  while (1)
  {
    // Ask for a number from the user
    printf("\nEnter an integer from 1 to 20: ");
    scanf("%d", &num);

    // Check input is between 1 and 20
    if (num < 1 || num > 20)
    {
      printf("Invalid");
      break;
    }

    for (int i = 0; i < num; i++)
    {
      printf("*");
    }
  }

  return 0;
}
