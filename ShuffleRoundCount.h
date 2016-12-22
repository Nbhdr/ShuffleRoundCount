//
//  ShuffleRoundCount.h
//  
//
//  Created by Neel Bhadra on 12/21/16.
//
//

#ifndef ShuffleRoundCount_h
#define ShuffleRoundCount_h

#include <stdio.h>

#define TOP 1
#define BOT 0

// card structure where face value, representing both its face value and original position
struct card{
    unsigned long int face;
    struct card *next;           // represent card order as a linked list
    
};

// deck structure, only required to insert to the beginning and end of deck
struct deckOfCards {
    struct card *pTopCard;
    struct card *pBottomCard;
};


static void AddCardToDeck(struct deckOfCards *pDeck, struct card* pCard, int top);
static struct card* GetTopCard(struct deckOfCards *pDeck);
static int CheckDeckOrder(const struct deckOfCards *pDeck, unsigned long int cardCount);
static struct card *InitializeCard(unsigned long int face);
static struct deckOfCards *InitializeDeck(unsigned long int cardCount);
static void FreeDeckMemory(struct deckOfCards **ppDeckHand, struct deckOfCards **ppDeckTable);
void PrintDeck(const struct deckOfCards *pDeck);
static void ShuffleRound(struct deckOfCards *hand, struct deckOfCards *table);


#endif /* ShuffleRoundCount_h */
