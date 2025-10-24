#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 * This function generate random integer number base on srand()
 *
 * @return 1-digit integer
 */
int randomInteger();

int main()
{
  int x = 0;

  srand(time(0));
  while (x < 10)
  {
    printf("%d ", randomInteger());
    x++;
  }


  return 0;
}

int randomInteger(){
  int result = rand() % 10;

  return result;
}
