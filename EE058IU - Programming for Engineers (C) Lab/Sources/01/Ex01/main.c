#include <stdio.h>

int main() {
  int i;
  printf("Enter an integer: ");
  scanf("%d", &i);

  if (i % 2 == 0) {
    printf("%d is even integer\n", i);
  } else {
    printf("%d is odd integer\n", i);
  }
  
  return 0;
}
