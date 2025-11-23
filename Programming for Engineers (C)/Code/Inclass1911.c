#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (*opfunc)(double, double);

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divide(double a, double b) { return (b == 0.0) ? (printf("Error: division by zero\n"), NAN) : a / b; }

double invalid_op(double a, double b)
{
  (void)a;
  (void)b;
  printf("Error: invalid operator\n");
  return NAN;
}

int main(void)
{
  double a, b;
  char op;

  printf("Simple calculator using function-pointer table\n");
  printf("Enter expression: <number> <operator> <number> (e.g. 1.5 + 2.3)\n");
  int r = scanf("%lf %c %lf", &a, &op, &b);
  r == 3 ? (void)0 : (printf("Invalid input format. Expected: number operator number\n"), exit(1));

  opfunc table[256];
  for (int i = 0; i < 256; ++i)
    table[i] = invalid_op;

  table[(unsigned char)'+'] = add;
  table[(unsigned char)'-'] = sub;
  table[(unsigned char)'*'] = mul;
  table[(unsigned char)'/'] = divide;

  opfunc f = table[(unsigned char)op];
  double result = f(a, b);
  !isnan(result) && printf("Result: %g\n", result);

  return 0;
}
