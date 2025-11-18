#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 *
 * This function generate random integer number base on srand()
 *
 * @return 1-digit integer
 */
int randomInteger();
void questionGenerator();
bool isCorrectAnswer(float userAnswer, float numberA, float numberB);

int main()
{
  srand(time(NULL));

  questionGenerator();

  return 0;
}

int randomInteger()
{
  int result = rand() % 10;

  return result;
}

bool isCorrectAnswer(float userAnswer, float numberA, float numberB)
{
  return userAnswer == (numberA * numberB);
}

void questionGenerator()
{
  int totalQuestions = 0, correctAnswers = 0;

  printf("Hello. Let's try some multiplication!\nEnter -1 to exit.\n");

  while (true)
  {
    int numberA = randomInteger(), numberB = randomInteger();
    float userAnswer;

    printf("How much is %d x %d? ", numberA, numberB);
    scanf("%f", &userAnswer);

    if (userAnswer == -1)
    {
      printf("Program ends. Total Questions: %d, Correct Answers: %d\n", totalQuestions, correctAnswers);
      break;
    }

    if (isCorrectAnswer(userAnswer, numberA, numberB))
    {
      printf("Correct!\n");
      correctAnswers++;
    }

    totalQuestions++;
  }
}
