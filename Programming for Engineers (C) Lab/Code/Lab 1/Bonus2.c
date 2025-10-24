#include <stdio.h>

int main()
{
  int x, tmp;
  int reminder, reversedNum = 0;

  printf("Enter 5-digits integers: ");
  scanf("%d", &x);
  tmp = x;

  while (tmp != 0)
  {
    reminder = tmp % 10;
    reversedNum = reversedNum * 10 + reminder;
    tmp /= 10;
  }

  if (reversedNum == x)
    printf("%d is a palindrome", x);

  return 0;
}
