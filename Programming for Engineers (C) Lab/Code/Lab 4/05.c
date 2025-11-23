#include <stdio.h>

int main()
{
  int firstClassSeats[5] = {0, 0, 0, 0, 0};
  int economySeats[5] = {0, 0, 0, 0, 0};

  printf("HELLO! WELCOME TO C LAB AIRLINE!\n");

  while (1)
  {
    int seatClassType, seatNumber;
    char nextPassenger;
    printf("---------------------------------\n");
    printf("There current seating chart:\n");
    for (size_t i = 0; i < sizeof(firstClassSeats) / sizeof(firstClassSeats[0]); i++)
    {
      printf("%d ", firstClassSeats[i]);
    }
    for (size_t i = 0; i < sizeof(economySeats) / sizeof(economySeats[0]); i++)
    {
      printf("%d ", economySeats[i]);
    }
    printf("\n---------------------------------\n");
    printf("Please choose your class\nType 1 for first class or 2 for economy class: ");
    scanf("%d", &seatClassType);
    printf("\nPlease choose your seat (from 1 to 5): ");
  choose_seat:
    scanf("%d", &seatNumber);
    switch (seatClassType)
    {
    case 1:
      if (firstClassSeats[seatNumber - 1] == 1)
      {
        printf("The seat is no longer available. Please choose another seat: ");
        goto choose_seat;
      }
      else
      {
        firstClassSeats[seatNumber - 1] = 1;
        printf("Here is your boarding pass: First class Seat number is: %d\n", seatNumber);
      }
      break;
    case 2:
      if (economySeats[seatNumber - 1] == 1)
        printf("The seat is no longer available. Please choose another seat: ");
      break;
    default:
      break;
    }
    printf("Next passenger (y or n)? ");
    scanf(" %c", &nextPassenger);
    if (nextPassenger == 'n' || nextPassenger == 'N')
      break;
  }

  return 0;
}
