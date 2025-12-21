#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct
{
  int day;
  int month;
  long int year;
} Date;

typedef struct
{
  char first_name[50];
  char last_name[50];
  char nationality[50];
} Author;

typedef struct
{
  char title[50];
  Author author;
  float price;
  Date public_date;
} BOOK;

void findMostExpensiveBook(BOOK *books, int books_size);
void findBookPublicDateAfterYear2010(BOOK *books, int books_size);

int main()
{
  int size;
  printf("Enter the numbers of books: ");
  if (scanf("%d", &size) != 1 || size <= 0)
  {
    printf("Invalid number of books.\n");
    return 1;
  }

  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;

  BOOK books[size];

  for (int i = 0; i < size; i++)
  {
    printf("--- Enter details for Book %d ---\n", i + 1);
    printf("Title: ");
    fgets(books[i].title, sizeof(books[i].title), stdin);
    books[i].title[strcspn(books[i].title, "\r\n")] = '\0';

    printf("Author First Name: ");
    fgets(books[i].author.first_name, sizeof(books[i].author.first_name), stdin);
    books[i].author.first_name[strcspn(books[i].author.first_name, "\r\n")] = '\0';

    printf("Auth Last Name: ");
    fgets(books[i].author.last_name, sizeof(books[i].author.last_name), stdin);
    books[i].author.last_name[strcspn(books[i].author.last_name, "\r\n")] = '\0';

    printf("Author Nationality: ");
    fgets(books[i].author.nationality, sizeof(books[i].author.nationality), stdin);
    books[i].author.nationality[strcspn(books[i].author.nationality, "\r\n")] = '\0';

    printf("Price: ");
    while (scanf("%f", &books[i].price) != 1)
    {
      printf("Invalid price. Try again: ");
      while ((ch = getchar()) != '\n' && ch != EOF)
        ;
    }
    while ((ch = getchar()) != '\n' && ch != EOF)
      ;
    printf("Publication Date (DD MM YYYY): ");
    while (scanf("%d %d %ld", &books[i].public_date.day, &books[i].public_date.month, &books[i].public_date.year) != 3)
    {
      printf("Invalid date. Enter DD MM YYYY: ");
      while ((ch = getchar()) != '\n' && ch != EOF)
        ;
    }
    while ((ch = getchar()) != '\n' && ch != EOF)
      ;
  }

  findMostExpensiveBook(books, size);
  findBookPublicDateAfterYear2010(books, size);

  return 0;
}

void findMostExpensiveBook(BOOK *books, int books_size)
{
  if (books_size <= 0)
  {
    printf("No books to evaluate for price.\n");
    return;
  }
  int idx = 0;
  float max = books[0].price;
  for (int i = 1; i < books_size; i++)
  {
    if (books[i].price > max)
    {
      max = books[i].price;
      idx = i;
    }
  }
  printf("\n===================================\n MOST EXPENSIVE BOOK DETAILS\n===================================\nTitle: %s\nAuthor: %s %s\nPrice: %.2f\nDate: %d/%d/%ld\n",
         books[idx].title,
         books[idx].author.first_name,
         books[idx].author.last_name,
         books[idx].price,
         books[idx].public_date.day,
         books[idx].public_date.month,
         books[idx].public_date.year);
}

void findBookPublicDateAfterYear2010(BOOK *books, int books_size)
{
  printf("\n===================================\n BOOKS PUBLISHED AFTER 2010\n===================================\n");
  for (int i = 0; i < books_size; i++)
  {
    if (books[i].public_date.year <= 2010)
      continue;
    printf("- Title: %s (Year: %ld)\n",
           books[i].title,
           books[i].public_date.year);
  }
}
