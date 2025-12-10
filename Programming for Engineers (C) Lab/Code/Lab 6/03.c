#include <stdio.h>

typedef struct
{
  char title[50];
  char author[50];
  int pages;
} BookData;

typedef struct
{
  char size[50];
  char color[50];
} TShirtData;

typedef union
{
  BookData book;
  TShirtData shirt;
} ItemData;

typedef struct
{
  ItemData item;
  float price;
} Store;

int main()
{
  Store my_book, my_shirt;

  printf("Input the information of Book:");
  printf("\nEnter the book title: ");
  scanf("%s", &my_book.item.book.title);
  printf("\nEnter # page: ");
  scanf("%s", &my_book.item.book.pages);
  printf("\nEnter author: ");
  scanf("%s", &my_book.item.book.author);
  printf("\nEnter price(USD): ");
  scanf("%s", &my_book.price);

  printf("\nInput the information of T-Shirt: ");
  printf("\nEnter the size: ");
  scanf("%s", &my_shirt.item.shirt.size);
  printf("\nEnter the color: ");
  scanf("%s", &my_shirt.item.shirt.color);
  printf("Enter price(USD): ");
  scanf("%s", &my_shirt.price);
  return 0;
}
