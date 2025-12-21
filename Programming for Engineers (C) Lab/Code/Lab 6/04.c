#include <stdio.h>

// 1. Define the Structure
struct Time
{
  int hours;
  int minutes;
  int seconds;
};

// Function Prototypes
// We use pointers (struct Time *t) to pass the structure by reference
long convertToSeconds(struct Time *t);
void convertToTime(long total_seconds, struct Time *t);
void addTimes(struct Time *t1, struct Time *t2, struct Time *result);

int main()
{
  int option;
  char cont = 'y';
  struct Time t1, t2, result;
  long totalSec;

  while (cont == 'y' || cont == 'Y')
  {
    // Menu Display
    printf("\nOption 1: convert a hour format from hh:mm:ss to second\n");
    printf("Option 2: convert second to a hour format hh:mm:ss\n");
    printf("Option 3: add two times (hh:mm:ss)\n\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Please enter an hour formatted as hh:mm:ss : ");
      // Using pointers implicitly here as scanf requires addresses
      scanf("%d:%d:%d", &t1.hours, &t1.minutes, &t1.seconds);

      // Pass the address of t1 to the function
      totalSec = convertToSeconds(&t1);
      printf("The converted number of seconds is: %ld\n", totalSec);
      break;

    case 2:
      printf("Please enter a number of seconds: ");
      scanf("%ld", &totalSec);

      // Pass the address of 'result' to be filled by the function
      convertToTime(totalSec, &result);

      // %02d ensures it prints "05" instead of just "5"
      printf("The converted hour is: %02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);
      break;

    case 3:
      printf("Enter 1st time----\n");
      printf("Please enter an hour formatted as hh:mm:ss : ");
      scanf("%d:%d:%d", &t1.hours, &t1.minutes, &t1.seconds);

      printf("Enter 2nd time----\n");
      printf("Please enter an hour formatted as hh:mm:ss : ");
      scanf("%d:%d:%d", &t2.hours, &t2.minutes, &t2.seconds);

      // Pass pointers for inputs and output
      addTimes(&t1, &t2, &result);

      printf("\nThe total time = %d:%d:%d\n", result.hours, result.minutes, result.seconds);
      break;

    default:
      printf("Invalid option selected.\n");
    }

    printf("Do you want to continue? ");
    // Note: The space before %c is crucial to consume the newline character from the previous input
    scanf(" %c", &cont);
  }

  return 0;
}

// Option 1 Logic: Uses pointer to access struct members
long convertToSeconds(struct Time *t)
{
  long total;
  // Arrow operator (->) is used to access members of a struct via pointer
  total = (t->hours * 3600) + (t->minutes * 60) + t->seconds;
  return total;
}

// Option 2 Logic: Writes directly to the struct using the pointer
void convertToTime(long total_seconds, struct Time *t)
{
  t->hours = total_seconds / 3600;
  long remainder = total_seconds % 3600;
  t->minutes = remainder / 60;
  t->seconds = remainder % 60;
}

// Option 3 Logic: Read from t1/t2 pointers, write to result pointer
void addTimes(struct Time *t1, struct Time *t2, struct Time *result)
{
  result->seconds = t1->seconds + t2->seconds;
  result->minutes = t1->minutes + t2->minutes;
  result->hours = t1->hours + t2->hours;

  // Handle carry over for seconds
  if (result->seconds >= 60)
  {
    result->seconds -= 60;
    result->minutes++;
  }

  // Handle carry over for minutes
  if (result->minutes >= 60)
  {
    result->minutes -= 60;
    result->hours++;
  }
}
