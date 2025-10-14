#include <stdio.h>

int main()
{
  int distance;

  printf("Enter total distance: ");
  scanf("%d", &distance);

  if (distance == 1)
    printf("The total cost that a passenger has to pay: $%0.2f", 5.00);
  else if (1 < distance <= 30)
    printf("The total cost that a passenger has to pay: $%0.2f", 5.00 + (distance - 1) * 3.00);
  else
    printf("The total cost that a passenger has to pay: $%0.2f", 5.00 + 30 * 3 + (distance - 31) * 2);

  return 0;
}
