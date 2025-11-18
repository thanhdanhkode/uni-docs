// Online C compiler to run C program online
#include <stdio.h>

    int main()
{
  // F = (°C × 9/5) + 32
  // C = (°F - 32) × 5/9

  printf("%7s | %10s | %7s | %10s", "Celcius", "Fahrenheit", "Celcius", "Fahrenheit \n");
  printf("---------------------------------\n");

  int col_1 = 0;
  int col_2 = 21;
  for (col_1 = 0; col_1 <= 20; col_1++)
  {
    float Fahrenheit = (float)(col_1 * 1.8) + 32.0;
    float Fahrenheit_2 = (float)(col_1 + col_2) * 1.8 + 32.0;
    printf("%7d | %10.2f | %7d | %10.2f \n", col_1, Fahrenheit, col_2 + col_1, Fahrenheit_2);
  }

  printf("Choose an option: \n");
  printf("1. F -> C\n");
  printf("2. C -> F\n");

  int choice;
  printf("Enter your choice (1 or 2): \n");
  scanf("%d", &choice);

  float f;
  float c;
  if (choice == 1)
  {
  Back:
    printf("Enter F: \n");
    scanf("%f", &f);

    if (f < -459.67)
    {
      printf("Invalid temperature. Try again \n");
      goto Back;
    }

    c = (f - 32.0) * 5.0 / 9.0;
    printf("%.3f Celcius is euqal to %.3f Farenheit", c, f);
  }
  else if (choice == 2)
  {
  Back_1:
    printf("Enter c: \n");
    scanf("%f", &c);

    if (c < -273.15)
    {
      printf("Invalid temperature. Try again \n");
      goto Back_1;
    }

    f = (c * 1.8) + 32.0;
    printf("%.3f Celcius is euqal to %.3f Farenheit", c, f);
  }
  else
  {
    printf("Wrong choice \n");
  }

  return 0;
}
