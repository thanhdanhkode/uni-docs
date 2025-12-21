#include <stdio.h>
#include <string.h>

typedef struct
{
  char brand[50];
  char type[50];
} Origin;

typedef struct
{
  char name[50];
  Origin origin;
  float price;
} Mbike;

void findHondaScooters(Mbike *bike_list, int size);
void findMostExpensiveYamahaMotorbike(Mbike *bike_list, int size);

int main()
{
  int size;

  printf("Enter the number of motorbikes (N): ");
  scanf("%d", &size);

  Mbike bike_list[size];

  for (int i = 0; i < size; i++)
  {
    printf("--- Enter details for Motorbike %d ---\n", i + 1);
    printf("Name: ");
    scanf("%s", &bike_list[i].name);
    printf("Brand (e.g., Honda, Yamaha): ");
    scanf("%s", &bike_list[i].origin.brand);
    printf("Type (e.g., scooter): ");
    scanf("%s", &bike_list[i].origin.type);
    printf("Price: ");
    scanf("%f", &bike_list[i].price);
  }

  findHondaScooters(bike_list, size);
  findMostExpensiveYamahaMotorbike(bike_list, size);

  return 0;
}

void findHondaScooters(Mbike *bike_list, int size)
{
  printf("\n----------------------------------------------\n");
  printf(">>> LIST OF HONDA SCOOTERS: \n");

  for (int i = 0; i < size; i++)
  {
    if (strcmp(bike_list[i].origin.brand, "Honda") == 0)
    {
      if (strcmp(bike_list[i].origin.type, "scooter") == 0)
      {
        printf("Name: %s | Price: $%.2f\n", bike_list[i].name, bike_list[i].price);
      }
    }
    else
    {
      continue;
    }
  }
  puts("");
}

void findMostExpensiveYamahaMotorbike(Mbike *bike_list, int size)
{
  printf("\n---------------------------------------------\n");
  printf(">>> MOST EXPENSIVE YAMAHA MOTORBIKE: \n");

  float max = 0;
  int idx = 0;

  for (int i = 0; i < size; i++)
  {
    if (strcmp(bike_list[i].origin.brand, "Yamaha") == 0)
    {
      if (bike_list[i].price > max)
      {
        max = bike_list[i].price;
        idx = i;
      }
    }
    else
    {
      continue;
    }
  }

  printf("Name: %s\n", bike_list[idx].name);
  printf("Type: %s\n", bike_list[idx].origin.type);
  printf("Price: $%.2f\n", bike_list[idx].price);
}
