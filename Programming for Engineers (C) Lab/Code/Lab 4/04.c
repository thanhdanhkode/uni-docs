#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

int randomNumber(void)
{
  return rand() % 30 + 1;
}

int main(void)
{
  srand((unsigned)time(NULL));

  int array[SIZE];
  int opt1[SIZE] = {0}, opt2[SIZE] = {0}, opt3[SIZE] = {0};
  int num1, num2;
  int count1 = 0, count2 = 0, count3 = 0;

  for (int i = 0; i < SIZE; ++i)
    array[i] = randomNumber();

  printf("Original array:\n");
  for (int i = 0; i < SIZE; ++i)
    printf("%d ", array[i]);
  putchar('\n');

  printf("Enter 1st number: ");
  if (scanf("%d", &num1) != 1)
    return 1;
  printf("Enter 2nd number: ");
  if (scanf("%d", &num2) != 1)
    return 1;

  for (int i = 0; i < SIZE; ++i)
  {
    if (array[i] < num1 && (array[i] % 2) == 0)
    {
      opt1[count1++] = i; /* store index */
    }
    else if (array[i] > num2 && (array[i] % 2) != 0)
    {
      opt2[count2++] = i;
    }
    else if (array[i] > num1 && array[i] < num2)
    {
      opt3[count3++] = i;
    }
  }

  while (1)
  {
    char choice;
    int option;

    printf("Option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Found %d numbers < %d and are even number\n", count1, num1);
      printf("Their position: ");

      for (int k = 0; k < count1; ++k)
        printf("%d ", opt1[k]);
      break;
    case 2:
      printf("Found %d numbers > %d and are odd number\n", count2, num2);
      printf("Their position: ");

      for (int k = 0; k < count2; ++k)
        printf("%d ", opt2[k]);
      break;
    case 3:
      printf("Found %d numbers N with %d < N < %d\n", count3, num1, num2);

      printf("Their positions are: ");

      for (int k = 0; k < count3; ++k)
        printf("%d ", opt3[k]);
      break;
    default:
      printf("Invalid option. Choose 1, 2 or 3.\n");
      break;
    }
    printf("\nDo you want to continue? (y/n): ");
    scanf(" %c", &choice);
    if (choice != 'y' && choice != 'Y')
      break;
  }

  printf("Exit program!\n");
  return 0;
}
