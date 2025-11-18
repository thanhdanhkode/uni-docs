#include <stdio.h>
#include <math.h>

void Read_Array(int size, float a[])
{
  for (int i = 0; i < size; i++)
  {
    printf("Element[%d]: ", i);
    scanf("%f", &a[i]);
  }
}

void Print_Array(int size, float a[])
{
  printf("Original Array: \n");
  for (int i = 0; i < size; i++)
  {
    printf(" %.1f ", a[i]);
  }
}

int Find_Nearest(float value, float d[], float a[], int n)
{
  for (int i = 0; i <= n; i++)
  {
    d[i] = (float)fabs(a[i] - (value * 1.0));
  }

  float min = d[0];
  int vitri = 0;
  for (int i = 1; i < n; i++)
  {
    if (min > d[i])
    {
      min = d[i];
      vitri = i;
    }
  }
  return vitri;
}

int main()
{
  int n = 0;
  float a[1000];
  printf("Enter array size: ");
  scanf("%d", &n);

  Read_Array(n, a);
  Print_Array(n, a);

  float value = 0;
  float d[1000];
  printf("\nEnter a value: ");
  scanf("%f", &value);

  int Vitri = Find_Nearest(value, d, a, n);

  // printf("\nThe value of arrayy d is : ");
  // Print_Array(n ,d);
  printf("The nearest value of x(%.2f) is: %.2f ", value, a[Vitri]);

  return 0;
}
