#include <stdio.h>

/**
 *
 * This program calculate the total payment of Taxi service
 *
 */
int main()
{
  float distance;
  float base_price = 10000;

  printf("Enter total distance in km: ");
  scanf("%f", &distance);

  if (distance <= 1)
    printf("The total cost that a passenger has to pay: %0.0f VND", base_price);
  else if (1 < distance <= 30)
    printf("The total cost that a passenger has to pay: %0.0f VND", base_price + (distance - 1) * 5000);
  else
    printf("The total cost that a passenger has to pay: %0.0f VND", base_price + 30.00 * 5000 + (distance - 31) * 30000);

  return 0;
}
