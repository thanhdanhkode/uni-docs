#include <stdio.h>
#include <math.h>

#define PI 3.14

float func1(float x, float y, float z)
{
  float min = x;
  if (min > y)
  {
    min = y;
  }
  if (min > z)
  {
    min = z;
  }

  float max = x;
  if (max < y)
  {
    max = y;
  }
  if (max < z)
  {
    max = z;
  }

  printf("Max = %f, Min = %f\n", max, min);
  float result = (x + y + z) - min - max; // tổng trừ số đầu trừ cho số cuối ra số ở giữa

  return result;
}

void func2(int x, double y)
{
  double y_rad = (y * PI) / 180.0;
  double result = 5 * pow((double)sin(y_rad), x) - 2 * pow((double)cos(2 * y_rad), 3 * x);
  printf("f(%d,%f) = %.2lf\n", x, y, result);
}

double func3(int x)
{
  double result = 0;
  for (int i = 1; i <= x; i++)
  {
    result += pow((i * 2), (2 * i + 1));
  }
  return result;
}

void func4(int value)
{
  printf("Enter an octal value: ");
  scanf("%o", &value);
  printf("Octal   Decimal   Hexadecimal\n");
  printf("-------------------------------\n");
  printf("%#4o%7d%#12x\n", value, value, value);
}

int main()
{
back:
  int option = 0;
  do
  {
    printf("Enter an option: ");
    scanf("%d", &option);

    if (option < 0)
    {
      printf("Positive value only. Enter again\n");
    }
  } while (option < 0);

  switch (option)
  {
  case 1:
    float x, y, z;
    printf("Enter three floating values: ");
    scanf("%f %f %f", &x, &y, &z);
    printf("The middle value: %.2f\n", func1(x, y, z));
    goto back;
    break;
  case 2:
    int a;
    double b;
    printf("Enter an integer and a double: ");
    scanf("%d %lf", &a, &b);

    func2(a, b);
    goto back;
    break;
  case 3:
    int integer;
    printf("Enter an integer: ");
    scanf("%d", &integer);

    printf("f(%d) = %.lf \n", integer, func3(integer));
    goto back;
    break;
  case 4:
    int octal;
    func4(octal);
    goto back;
    break;

  default:
    break;
  }
  return 0;
}
