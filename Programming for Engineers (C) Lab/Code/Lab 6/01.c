#include <stdio.h>

typedef struct
{
  char first_name[50];
  char last_name[50];
  char nationality[50];
  int age;
  float height;
  float weight;
  char job_title[100];
} Person;

int main()
{
  Person person_info;

  printf("Enter first name: ");
  scanf("%s", &person_info.first_name);
  printf("Enter last name: ");
  scanf("%s", &person_info.last_name);
  printf("Enter nationality: ");
  scanf("%s", &person_info.nationality);
  printf("Enter age: ");
  scanf("%d", &person_info.age);
  printf("Enter height: ");
  scanf("%f", &person_info.height);
  printf("Enter weight: ");
  scanf("%f", &person_info.weight);
  printf("Enter job title: ");
  scanf("%s", &person_info.job_title);

  printf("Here is the infomation:\n");
  printf("Full name: %s %s", person_info.first_name, person_info.last_name);
  printf("\nAge: %d", person_info.age);
  printf("\nNationality: %s", person_info.nationality);
  printf("\nHeight: %.1f (m)", person_info.height);
  printf("\nWeight: %.1f (kg)", person_info.weight);
  printf("\nJob Title: %s", person_info.job_title);
  return 0;
}
