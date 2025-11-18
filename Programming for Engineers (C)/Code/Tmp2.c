#include <stdio.h>

int main()
{
  int x = 15, y = 4;
  char t;
  float z = 5.32544654;
  int arr[x + 5];

  for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    // printf("%d ", i);
  }
// printf("%3.6f", z);
  scanf("%[aeiou]", &t);
  printf("%s", t);

  return 0;
}
