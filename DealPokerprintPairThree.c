/*
******************************* C SOURCE FILE ********************************
** project   : rik_c_play
** filename  : MAIN.C
** version   : 1
** date      : August 02, 2003
*********************
VERSION HISTORY:
----------------
Version     : 1
Date        : Feb 2017
Revised by  : relauder@lakeheadu.ca
*/

#define _MAIN_C_SRC 
/****************************************************************************/
/**                     MODULES USED                                       **/
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****************************************************************************/
/**                     DEFINITIONS AND MACROS                             **/
/****************************************************************************/
#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5

/****************************************************************************/
/**                     TYPEDEFS AND STRUCTURES                            **/
/****************************************************************************/
/*typedef struct
{
    int custom;
    char mystring[];
} structname;
/*

/****************************************************************************/
/**                     PROTOTYPES OF LOCAL FUNCTIONS                      **/
/****************************************************************************/
void shuffle(const int wDeck[][FACES]); // shuffling modifies wDeck
void deal(const int wDeck[][FACES], const char *wFace[],
    const char *wSuit[]); // dealing doesn't modify the arrays
void pair(const int[][FACES], const int[][2], const char *[] );
void threeOfKind(const int[][FACES], const int[][2], const char *[]);


/****************************************************************************/
/**                     EXPORTED VARIABLES                                 **/
/****************************************************************************/

/****************************************************************************/
/**                     GLOBAL VARIABLES                                   **/
/****************************************************************************/

/****************************************************************************/
/**                     EXPORTED FUNCTIONS                                 **/
/****************************************************************************/

/****************************************************************************/
/**                     LOCAL FUNCTIONS                                    **/
/****************************************************************************/ 

int main(void)
{
    // initialize deck array
    const char *suit[SUITS] =
    { "Hearts", "Diamonds", "Clubs", "Spades" };

    // initialize face array                   
    const char *face[FACES] =
    { "Ace", "Deuce", "Three", "Four",
	   "Five", "Six", "Seven", "Eight",
	   "Nine", "Ten", "Jack", "Queen", "King" };

    int deck[SUITS][FACES] = { 0 }, hand[CARDS][2] = { 0 };

    srand(time(NULL)); // seed random-number generator

    shuffle(deck); // shuffle the deck

    deal(deck, face, suit, hand); // deal the deck

    pair(deck, hand, face);

    threeOfKind(deck, hand, face);
}

// shuffle cards in deck
void shuffle( int wDeck[][FACES])
{
    // for each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) {
	   size_t row; // row number
	   size_t column; // column number

				   // choose new random location until unoccupied slot found
	   do {
		  row = rand() % SUITS;
		  column = rand() % FACES;
	   } while (wDeck[row][column] != 0); // end do...while

								   // place card number in chosen slot of deck
	   wDeck[row][column] = card;
    }
}

// deal cards in deck
void deal(const int wDeck[][FACES], const char *wFace[],
    const char *wSuit[], int wHand[][2])
{
    //deal a 5 card hand
    int r = 0;
    printf("The hand is: \n");

    for (int card = 1; card < HAND+1; ++card)
	   for (int row = 0; row <= 3; ++row)
		  for (int column = 0; column <= 12; ++column)
			 if (wDeck[row][column] == card) {
				wHand[r][0] = row;
				wHand[r][1] = column;
				printf("%5s of %-8s%c", wFace[column], wSuit[row],
				    card % 2 == 0 ? '\n' : '\t'); // 2-column format
				++r;
			 }
    printf("\n");
}

    /* deal ell of the cards
    for (size_t card = 1; card <= CARDS; ++card) {
	   // loop through rows of wDeck
	   for (size_t row = 0; row < SUITS; ++row) {
		  // loop through columns of wDeck for current row
		  for (size_t column = 0; column < FACES; ++column) {
			 // if slot contains current card, display card
			 if (wDeck[row][column] == card) {
				printf("%5s of %-8s%c", wFace[column], wSuit[row],
				    card % 2 == 0 ? '\n' : '\t'); // 2-column format
			 }
		  }
	   }
    }
}*/

//determine if hand contains one or two pair
void pair(const int wDeck[][FACES], const int wHand[][2], const char *wFace[])
{
    int counter[FACES] = { 0 };

    for (int r = 0; r < HAND; r++)
	   ++counter[wHand[r][1]];
    
    printf("\n");

    for (int p = 0; p < FACES; ++p) 
	   if (counter[p] == 2)
		  printf("The hand contains a pair of %s \n", wFace[p]);
}

//determine if hand has 3 of kind
void threeOfKind(const int wDeck[][FACES], const int wHand[][2], const char *wFace[])
{
    int counter[FACES] = { 0 };

    for (int r = 0; r < HAND; r++)
	   ++counter[wHand[r][1]];

    printf("\n");

    for (int p = 0; p < FACES; ++p)
	   if (counter[p] == 3)
		  printf("The hand contains a three of %s \n", wFace[p]);
}

/****************************************************************************/
/**                     EOF                                                **/
/****************************************************************************/