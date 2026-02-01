#include <stdio.h>

typedef struct
{
  float real;
  float imagine;
} Complex;

int main()
{
  int size;
  float realSum = 0, imagineSum = 0;

  printf("Enter number of complex numbers: ");
  scanf("%d", &size);

  if (size < 2)
  {
    printf("Error: At least two complex numbers are required.\n");
    return 1;
  }

  Complex complex[size];

  for (int i = 0; i < size; i++)
  {
    printf("Enter the complex %d: ", i + 1);
    scanf("%f %f", &complex[i].real, &complex[i].imagine);
  }

  for (int i = 0; i < size; i++)
  {
    realSum += complex[i].real;
    imagineSum += complex[i].imagine;
  }

  printf("Sum: %.1f %.1fi", realSum, imagineSum);

  return 0;
}
