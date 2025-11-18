#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary);

int main()
{
  int n;

  printf("Enter number of disks: ");
  if (scanf("%d", &n) != 1 || n <= 0)
    return 0;

  towerOfHanoi(n, 'A', 'C', 'B');

  return 0;
}

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
  if (n == 1)
  {
    printf("move disk from %c to %c\n", source, destination);
    return;
  }

  towerOfHanoi(n - 1, source, auxiliary, destination);

  printf("move disk from %c to %c\n", source, destination);

  towerOfHanoi(n - 1, auxiliary, destination, source);
}
