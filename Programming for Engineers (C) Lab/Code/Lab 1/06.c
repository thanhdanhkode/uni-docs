#include <stdio.h>

/**
 *
 * This program calculate the total payment of Taxi service
 *
 */
int main()
{
  float distance;

  printf("Enter total distance in km: ");
  scanf("%f", &distance);

  if (distance == 1)
    printf("The total cost that a passenger has to pay: $%0.2f", 10000);
  else if (1 < distance <= 30)
    printf("The total cost that a passenger has to pay: $%0.2f", 10000 + (distance - 1) * 5000);
  else
    printf("The total cost that a passenger has to pay: $%0.2f", 10000 + 30 * 5000 + (distance - 31) * 3000);

  return 0;
}
