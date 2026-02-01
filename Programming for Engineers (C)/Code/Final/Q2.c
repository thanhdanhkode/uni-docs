#define SHIPMENT_ARR_SIZE 3

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int hour;
  int minute;
} Time;

typedef struct
{
  int id;
  char desc[50];
  Time scheduleTime;
  Time arrivalTime;
} Shipment;

Shipment inputData();
int toMinutes(Time t);
void checkStatus(Shipment s, int tolerance);

int main()
{
  Shipment shipment[SHIPMENT_ARR_SIZE] = {0};

  for (size_t i = 0; i < SHIPMENT_ARR_SIZE; i++)
  {
    printf("Shipment #%d: \n", i + 1);
    shipment[i] = inputData();
  }

  int tolerance = 0;

  puts("\n");

  printf("Enter the allowed tolerance (minutes): ");
  scanf("%d", &tolerance);
  printf("--- Final Delivery Report ---\n");

  for (size_t i = 0; i < SHIPMENT_ARR_SIZE; i++)
  {
    printf("ID: %d \t STATUS: ", i + 1);
    checkStatus(shipment[i], tolerance);
  }

  return 0;
}

Shipment inputData()
{
  Shipment s;

  printf("Enter Shipment ID: ");
  scanf("%d", &s.id);

  printf("Enter Description: ");
  scanf("%s", s.desc);

  printf("Enter Schedule Time (HH MM): ");
  scanf("%d %d", &s.scheduleTime.hour, &s.scheduleTime.minute);

  printf("Enter Arrival Time (HH MM): ");
  scanf("%d %d", &s.arrivalTime.hour, &s.arrivalTime.minute);

  return s;
}

int toMinutes(Time t)
{
  return t.hour * 60 + t.minute;
}

void checkStatus(Shipment s, int tolerance)
{
  int delay = toMinutes(s.arrivalTime) - toMinutes(s.scheduleTime);
  if (delay > tolerance)
  {
    printf("LATE (%d mins delay)\n", delay);
  }
  else
    printf("ON TIME\n");
}
