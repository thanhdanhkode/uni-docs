#include <stdio.h>

// Function prototypes
void go_south_east(int latitude, int longitude);
void p_go_south_east(int *latitude, int *longitude);

int main()
{
  int latitude = 32, longitude = -12;
  int *p_latitude = &latitude, *p_longitude = &longitude;

  go_south_east(latitude, longitude);
  printf("Let's go South East! We now at: [%d,%d]\n", latitude, longitude);

  p_go_south_east(p_latitude, p_longitude);
  printf("Let's go South East! We now at: [%d,%d]\n", latitude, longitude);

  return 0;
}

void go_south_east(int latitude, int longitude)
{
  latitude -= 1;
  longitude += 1;
}

void p_go_south_east(int *latitude, int *longitude)
{
  *latitude -= 1;
  *longitude += 1;
}
