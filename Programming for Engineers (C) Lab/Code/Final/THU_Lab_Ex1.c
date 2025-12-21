#include <stdio.h>
#include <string.h>

int main()
{
  int size;
  char name[25];

  printf("Enter the size: ");
  scanf("%d", &size);

  printf("Enter your first name: ");
  scanf("%s", &name);

  int isPrinted = 0;
  int name_size = strlen(name);
  for (int i = 1; i <= size; i++)
  {
    if (i > (size * 2 - 1) / 2 - (int)(name_size / 2) && isPrinted == 0)
    {
      printf("%s", name);
      isPrinted = 1;
    }
    else if (i == size)
    {
      printf("\n");
    }
    else
    {
      printf(" ");
    }
  }

  for (int i = 1; i <= size; i++)
  {
    for (int j = 1; j <= size - i; j++)
    {
      printf(" ");
    }
    for (int k = 1; k <= 2 * i - 1; k++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
