#include <stdio.h>

// NOTE: The docs block below is created for the built-in function documentation of VS Code or any other IDEs.
/**
 * @file HW102.c
 * @brief Generates a temperature conversion table and performs user-driven conversions.
 *
 * This program prints a formatted table of Celsius to Fahrenheit conversions for two ranges:
 *   - 0°C through 20°C
 *   - 21°C through 41°C
 *
 * After displaying the table, the user is prompted to choose one of the following options:
 *   1. Convert from Fahrenheit to Celsius
 *   2. Convert from Celsius to Fahrenheit
 *
 * The selected temperature is read from standard input and converted using:
 *   - Celsius = (Fahrenheit − 32) × 5/9
 *   - Fahrenheit = (Celsius × 9/5) + 32
 *
 * Results are printed with two decimal places of precision.
 *
 * @return Returns 0 on successful execution.
 */
int main()
{
  int maxTemperature = 20, choice = 0;
  float temperature = 0, convertedTemperature = 0;

  printf("Celsius | Fahrenheit | Celsius | Fahrenheit\n");
  printf("-------------------------------------------\n");
  for (int i = 0; i <= maxTemperature; i++)
  {
    float fahrenheit1 = (i * 9.0 / 5.0) + 32, fahrenheit2 = ((i + 21) * 9.0 / 5.0) + 32;
    printf("%7d | %10.2f | %7d | %10.2f\n", i, fahrenheit1, i + 21, fahrenheit2);
  }

  printf("-------------------------------------------\n");
  printf("Choose an option:\n");
  printf("1. Convert from Fahrenheit to Celsius\n");
  printf("2. Convert from Celsius to Fahrenheit\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &choice);

  switch (choice)
  {

  case 1:
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &temperature);

    convertedTemperature = (temperature - 32) * 5.0 / 9.0;

    printf("%.3f Celsius is equal to %.3f Fahrenheit", temperature, convertedTemperature);
    break;
  case 2:
    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperature);

    convertedTemperature = (temperature * 9.0 / 5.0) + 32;

    printf("%.3f Celsius is equal to %.3f Fahrenheit", temperature, convertedTemperature);
    break;

  default:
    break;
  }

  return 0;
}
