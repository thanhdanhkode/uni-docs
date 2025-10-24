#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 * This program generate a "mystery" number random from 1 to 100, the user will guess this nnumber by prompt a value
 *
 */
int main()
{
  int x, y;
  char z;

start:
  srand(time(0));
  y = rand() % 100 + 1;

  printf("I have a number between 1 and 100.\n");
  printf("Can you guess my number?\n");
  printf("Please type your first guess...\n");
  scanf("%d", &x);

  while (1)
  {
    if (x == y)
    {
      printf("Excellent! You guessed the number!\n");
      printf("Would you like to continue (y or n)?\n");
      scanf(" %c", &z);
      if (z == 'y')
        goto start;
      else
        goto end;
    }
    else if (x > y)
    {
      printf("Too high. Try again...\n");
      scanf("%d", &x);
    }
    else
    {
      printf("Too low. Try again...\n");
      scanf("%d", &x);
    }
  };

end:
  printf("Game ends here...\n");

  return 0;
}
