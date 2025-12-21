/*
Write a C program that calculates parking receipts for three customers using a function called calculateCharges(). Ask the user to enter the hours parked for each customer.
Pricing Structure:
- First 3 hours: $2.00
- Over 3 hours: $0.50 per extra hour (rounds up)
- Max limit: $10.00 per 24 hours period.
Assume no car parks longer than 24 hours.
*/

#include <stdio.h>
#include <math.h>

#define MAX_CAR 3

typedef struct
{
  int id;
  float hours;
  float fee;
} CarFee;

float calculateCharges(float hours);

int main()
{
  CarFee carFee[MAX_CAR];
  float totalHours = 0, totalFee = 0;

  printf("=== CAR PARK FEE INPUT ===\n");
  for (size_t i = 0; i < MAX_CAR; i++)
  {
    printf("The hours car %d parked: ", i + 1);
    scanf("%f", &carFee[i].hours);
  }

  printf("Car\tHours\tCharge\n");
  for (int i = 0; i < MAX_CAR; i++)
  {
    float fee = calculateCharges(carFee[i].hours);
    printf("%d\t%.1f\t%.1f\n", i + 1, carFee[i].hours, fee);
    totalHours = totalHours + carFee[i].hours;
    totalFee = totalFee + fee;
  }
  printf("TOTAL\t%.1f\t%.2f\n", totalHours, totalFee);

  return 0;
}

float calculateCharges(float hours)
{
  float fee;

  if (hours <= 3)
  {
    fee = 2;
  }
  else
  {
    fee = 2 + 0.5 * ceil(hours - 3);
  }

  if (fee > 10)
    return 10;

  return fee;
}
