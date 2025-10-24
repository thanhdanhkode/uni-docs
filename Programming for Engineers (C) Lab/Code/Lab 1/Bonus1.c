#include <stdio.h>

int main()
{
  int account_number;
  float begin_balance, total_charges, total_credits, credit_limit, new_balance;

  while (1)
  {
    printf("\nEnter account number (-1 to end): ");
    scanf("%d", &account_number);
    if (account_number == -1)
      break;
    printf("Enter beginning balance: ");
    scanf("%f", &begin_balance);
    printf("Enter total charges: ");
    scanf("%f", &total_charges);
    printf("Enter total credits: ");
    scanf("%f", &total_credits);
    printf("Enter credit limit: ");
    scanf("%f", &credit_limit);

    new_balance = begin_balance + total_charges - total_credits;
    if (credit_limit < new_balance)
    {
      printf("Account: \t %d\n", account_number);
      printf("Credit limit: \t %.2f\n", credit_limit);
      printf("Balance: \t %.2f\n", new_balance);
      printf("Credit Limit Exceeded\n");
    }
  }

  return 0;
}
