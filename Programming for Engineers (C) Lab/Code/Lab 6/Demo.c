#include <stdio.h>

int main()
{
  int n, key, found;
  int a[100];
  int *pPtr = a;

  printf("Enter a size of array: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter element a[%d]: ", i);
    scanf("%d", (pPtr + i));
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d ", *(pPtr + i));
  }
  printf("\n\n");

  printf("Enter a search key: ");
  scanf("%d", &key);

  found = -1;
  for (int i = 0; i < n; i++)
  {
    if (*(pPtr + i) == key)
    {
      found = i + 1;
      break;
    }
  }

  if (found == -1)
    printf("No position was found !!!\n");
  else
    printf("The search key is in the position : %d\n", found);

  return 0;
}
