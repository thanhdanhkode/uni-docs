#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int x, y;
  char z;

  printf("I have a number between 1 and 100.\n");
  printf("Can you guess my number?\n");
  printf("Please type your first guess...\n");
  scanf("%d", &x);

  srand(time(0));
  y = rand() % 100 + 1;

  while (1)
  {
    if (x == y)
    {
      printf("Excellent! You guessed the number!\n");
      printf("Would you like to continue (y or n)?\n");
      scanf(" %c", &z);
      if (z == 'y')
      {
        srand(time(0));
        y = rand() % 100 + 1;
        printf("Please type your first guess...\n");
        scanf("%d", &x);
        continue;
      }
      else
      {
        printf("Game ends here...\n");
        x = -1;
        break;
      }
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

  return 0;
}
