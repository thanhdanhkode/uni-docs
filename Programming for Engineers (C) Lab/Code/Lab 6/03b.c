#include <stdio.h>

struct Book
{
  char title[50];
  int pages;
  char author[50];
};

struct Tshirt
{
  char size[10];
  char color[20];
};

struct Item
{
  float price;
  int type;

  union
  {
    struct Book b;
    struct Tshirt t;
  } details;
};

int main()
{
  struct Item item;

  printf("Input the information of Book\n");
  item.type = 1;
  printf("Enter the book title: ");
  scanf(" %[^\n]s", item.details.b.title);
  printf("Enter # page: ");
  scanf("%d", &item.details.b.pages);
  printf("Enter author: ");
  scanf(" %[^\n]s", item.details.b.author);
  printf("Enter price(USD): ");
  scanf("%f", &item.price);

  printf("\nInput the information of T-shirt\n");
  item.type = 2;
  printf("Enter the size: ");
  scanf("%s", item.details.t.size);
  printf("Enter the color: ");
  scanf("%s", item.details.t.color);
  printf("Enter price(USD): ");
  scanf("%f", &item.price);

  printf("Price of the item: %.2f USD\n", item.price);

  printf("\nSize of Union version: %zu bytes\n", sizeof(struct Item));

  return 0;
}
