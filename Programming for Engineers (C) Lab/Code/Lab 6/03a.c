#include <stdio.h>

struct Item
{
  int type;
  char title[50];
  int pages;
  char author[50];
  char size[10];
  char color[20];
  float price;
};

int main()
{
  struct Item book, tshirt;

  printf("Input the information of Book\n");
  printf("Enter the book title: ");
  scanf(" %[^\n]s", book.title);
  printf("Enter # page: ");
  scanf("%d", &book.pages);
  printf("Enter author: ");
  scanf(" %[^\n]s", book.author);
  printf("Enter price(USD): ");
  scanf("%f", &book.price);

  printf("\nInput the information of T-shirt\n");
  printf("Enter the size: ");
  scanf("%s", tshirt.size);
  printf("Enter the color: ");
  scanf("%s", tshirt.color);
  printf("Enter price(USD): ");
  scanf("%f", &tshirt.price);

  printf("\nSize of Struct version: %zu bytes\n", sizeof(struct Item));

  return 0;
}
