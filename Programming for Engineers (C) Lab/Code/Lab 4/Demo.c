#include <stdio.h>

int main()
{
  int seats[10] = {0};
  int seatNum, classType;
  char cont;
  int bookedCount = 0;

  do
  {
    if (bookedCount == 10)
    {
      printf("\nSorry! There is no seat available.\n");
      break;
    }

    printf("\nHELLO!! WELCOME TO C LAB AIRLINES!\n");

    printf("\nThe current seating chart:\n");
    for (int i = 0; i < 10; i++)
      printf("%d ", seats[i]);
    printf("\n------------------------------------------------------------\n");

    printf("Please choose your class.\n");
    printf("Type 1 for first class or 2 for economy class: ");
    scanf("%d", &classType);

    if (classType == 1)
    {
      do
      {
        printf("Please choose your seat (from 1 to 5): ");
        scanf("%d", &seatNum);

        if (seatNum < 1 || seatNum > 5)
        {
          printf("Invalid seat. Try again.\n");
          continue;
        }

        if (seats[seatNum - 1] == 1)
          printf("The seat is no longer available. Please choose another seat: ");
        else
          break;

      } while (1);

      seats[seatNum - 1] = 1;
      bookedCount++;

      printf("\nHere is your boarding pass:\tFirst class\tSeat number is: %d\n", seatNum);
    }

    else if (classType == 2)
    {
      do
      {
        printf("Please choose your seat (from 6 to 10): ");
        scanf("%d", &seatNum);

        if (seatNum < 6 || seatNum > 10)
        {
          printf("Invalid seat. Try again.\n");
          continue;
        }

        if (seats[seatNum - 1] == 1)
          printf("The seat is no longer available. Please choose another seat: ");
        else
          break;

      } while (1);

      seats[seatNum - 1] = 1;
      bookedCount++;

      printf("\nHere is your boarding pass:\tEconomy class\tSeat number is: %d\n", seatNum);
    }

    else
    {
      printf("Invalid class option!\n");
      continue;
    }

    printf("\nNext passenger (y or n)? ");
    scanf(" %c", &cont);

  } while (cont == 'y' || cont == 'Y');

  if (bookedCount < 10)
    printf("\nThank you for choosing C LAB AIRLINES. Next flight leaves in 3 hours\n");

  return 0;
}
