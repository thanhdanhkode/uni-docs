// Include lib
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Required for initializing the random number generator

// Define constant
#define SUITS 4  // Number of suits: Hearts, Diamonds, Clubs, Spades
#define FACES 13 // Number of card faces: Ace → King
#define CARDS 52 // Total cards in a standard deck (4 × 13)

// Define function prototype

/**
 * Randomly places card numbers 1–52 into the deck array.
 *
 * Each number appears exactly once because we only place
 * a card in a position that is still 0.
 * @param deck
 */
void shuffle(int deck[][FACES]);
/**
 * Prints the cards in the order they were shuffled.
 *
 * For card number 1 → 52, the function finds where that
 * card is located in the 2D array and prints its face and suit.
 * @param deck
 * @param face
 * @param suit
 */
void deal(int deck[][FACES], const char *face[], const char *suit[]);

/*
 * Senior Dev Note:
 *
 * This program simulates a standard deck of cards.
 * We use a 2D array to represent the deck:
 * - Rows (0-3) represent the Suits (Hearts, Diamonds, etc.)
 * - Columns (0-12) represent the Faces (Ace, Deuce, etc.)
 *
 * The value stored inside deck[row][col] is the CARD NUMBER (1-52),
 * indicating the order in which the card is dealt.
 *
 */
int main(void)
{
  // Initialize the deck array with zeros.
  // 0 indicates a "slot" in the deck that hasn't been assigned a card number yet.
  int deck[SUITS][FACES] = {0};

  // Seed the random number generator using the current time.
  // Without this, the program would generate the exact same shuffle every time you run it.
  srand(time(NULL));

  // Step 1: Shuffle the deck (assign random positions)
  shuffle(deck);

  // Arrays of strings to convert integer indices (0-3, 0-12) into human-readable text.
  // 'const' is used because these names should never change.
  const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five",
                             "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

  // Step 2: Deal the cards (print them in order 1-52)
  deal(deck, face, suit);
}

void shuffle(int deck[][FACES])
{
  // Loop through card numbers 1 to 52
  for (size_t card = 1; card <= CARDS; ++card)
  {
    size_t row = 0;    // To store random suit index
    size_t column = 0; // To store random face index

    /*
     * Keep generating random positions until we find
     * an empty one (value 0). This prevents overwriting.
     */
    do
    {
      row = rand() % SUITS;    // Random number between 0-3
      column = rand() % FACES; // Random number between 0-12
    } while (deck[row][column] != 0);

    // Place the current card number (e.g., 1, 2, ... 52) into that slot
    deck[row][column] = card;
  }
}
void deal(int deck[][FACES], const char *face[], const char *suit[])
{
  // Loop through each card number in shuffled order
  for (size_t card = 1; card <= CARDS; ++card)
  {
    // Scan for rows
    for (size_t row = 0; row < SUITS; ++row)
    {
      // Scan for columns
      for (size_t column = 0; column < FACES; ++column)
      {
        // If we found the current card number we are looking for:
        if (deck[row][column] == card)
        {
          // Print the Face (based on column) and Suit (based on row).
          // %5s and %-8s are formatting specifiers to align the text neatly.
          // %c prints a newline '\n' every 4 cards, or a tab '\t' otherwise.
          printf("%5s of %-8s %c",
                 face[column],               // e.g., "Queen"
                 suit[row],                  // e.g., "Spades"
                 card % 4 == 0 ? '\n' : '\t' // New line after every 4 cards
          );
        }
      }
    }
  }
}
