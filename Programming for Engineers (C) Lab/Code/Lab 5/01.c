#include <stdio.h>

int main()
{
  float num_a, num_b;
  float *p_num_a = &num_a, *p_num_b = &num_b;

  printf("Enter two real numbers: ");
  scanf("%f %f", p_num_a, p_num_b);

  printf("Sum = %0.1f\n", *p_num_a + *p_num_b);
  printf("Difference = %0.1f\n", *p_num_a - *p_num_b);
  printf("Product = %0.1f\n", *p_num_a * *p_num_b);
  printf("Quotient = %0.1f\n", *p_num_a / *p_num_b);

  return 0;
}
