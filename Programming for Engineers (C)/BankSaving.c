#include <stdio.h>
#include <math.h>

int main()
{
  int numYears = 0;
  float amount = 0, interest = 0, principal = 0;

  printf("Enter the principal amount: ");
  scanf("%f", &principal);
  printf("Enter the number of years: ");
  scanf("%d", &numYears);
  printf("Enter the interest rate: ");
  scanf("%f", &interest);

  for (int i = 1; i <= numYears; ++i)
  {
    amount = principal * pow(1.0 + interest, i);
    printf("Year %d: $%.2f\n", i, amount);
  }

  return 0;
}
