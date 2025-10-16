#include <stdio.h>

#define SIZE 5

int main(void)
{
  int n[SIZE] = {19, 3, 15, 7, 11};

  printf("%s%13s%17s\n", "Element", "Value", "Bar Chart");

  for (size_t i = 0; i < SIZE; ++i)
  {
    printf("%7zu%13d%8s", i, n[i], "");

    for (int j = 1; j <= n[i]; ++j)
    {
      printf("%c", '*');
    }

    puts("");
  }
}
