/*
Create a structure named BOOK to store the book details like title, author, and price. Write a C program to input details for five books, find the most expensive and the lowest priced book, and display their information.
*/

#include <stdio.h>

#define BOOKS_MAX 5

typedef struct
{
  char title[100];
  char author[100];
  float price;
} BOOK;

void findMostExpensiveBook(BOOK *books);
void findCheapestBook(BOOK *books);

int main()
{
  BOOK books[BOOKS_MAX];

  printf("Input %d Book details\n", BOOKS_MAX);
  for (int i = 0; i < BOOKS_MAX; i++)
  {
    printf("--- Book %d ---\n", i + 1);
    printf("Title: ");
    scanf("%s", &books[i].title);
    printf("Author: ");
    scanf("%s", &books[i].author);
    printf("Price: ");
    scanf("%f", &books[i].price);
  }

  // for (int i = 0; i < BOOKS_MAX; i++)
  // {
  //   printf("---Book Details---\n");
  //   printf("Title: %s\n", books[i].title);
  //   printf("Author: %s\n", books[i].author);
  //   printf("Price: %f\n", books[i].price);
  // }

  putchar("");

  findMostExpensiveBook(books);
  findCheapestBook(books);

  return 0;
}

void findMostExpensiveBook(BOOK *books)
{
  int idx = 0;
  float max = books[0].price;
  for (int i = 0; i < BOOKS_MAX; i++)
  {
    if (books[i].price > max)
    {
      max = books[i].price;
      idx = i;
    }
  }
  printf("--- The Most Expensive Book ---\n");
  printf("Title: %s\n", books[idx].title);
  printf("Author: %s\n", books[idx].author);
  printf("Price: %f\n", books[idx].price);
}

void findCheapestBook(BOOK *books)
{
  int idx = 0;
  float lowest = books[0].price;
  for (int i = 0; i < BOOKS_MAX; i++)
  {
    if (books[i].price < lowest)
    {
      lowest = books[i].price;
      idx = i;
    }
  }
  printf("--- The Cheapest Book ---\n");
  printf("Title: %s\n", books[idx].title);
  printf("Author: %s\n", books[idx].author);
  printf("Price: %f\n", books[idx].price);
}
