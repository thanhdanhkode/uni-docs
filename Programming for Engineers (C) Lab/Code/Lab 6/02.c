#include <stdio.h>

typedef struct
{
  float real;
  float imagine;
} ComplexType;

int main()
{
  ComplexType complex1;
  ComplexType complex2;

  printf("Enter the first complex: ");
  scanf("%f %f", &complex1.real, &complex1.imagine);
  printf("Enter the second complex: ");
  scanf("%f %f", &complex2.real, &complex2.imagine);

  printf("Sum: %.1f %.1fi", complex1.real + complex2.real, complex1.imagine + complex2.imagine);

  return 0;
}
