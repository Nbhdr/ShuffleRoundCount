//
//  ShuffleRoundCount.c
//
//
//  Created by Neel Bhadra on 12/21/16.
//
//

#include "ShuffleRoundCount.h"


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>



/********************************************************************************
 Function to add a card to the top or bottom of a deck of cards.
 @params:
 -  *pDeck is a pointer to the deck to add the card to
 -  *pCard is a pointer to the card to be added
 -  top - use macro TOP or BOT, determines which end of deck to add card
 output:
 -  None
 *********************************************************************************/

static void AddCardToDeck(struct deckOfCards *pDeck, struct card* pCard, int top)
{
    if(top){  // add card to top of deck
        if(pDeck->pTopCard == NULL){                // if deck is empty
            pDeck->pTopCard = pCard;                // now only card in deck, both top & bot
            pDeck->pBottomCard = pCard;
            pCard->next = NULL;
        }
        else{                                       //deck is not empty
            pCard->next = pDeck->pTopCard;          //make old top the new top's next
            pDeck->pTopCard = pCard;
        }
    }
    
    else{    // add card to bottom of deck
        pCard->next = NULL;
        if(pDeck->pTopCard == NULL){                //if deck is empty
            pDeck->pTopCard = pCard;                // now only card in deck is top
        }
        else{
            pDeck->pBottomCard->next = pCard;       //deck is not empty, update old bot
        }
        
        pDeck->pBottomCard = pCard;                //add new bot
    }
}


/********************************************************************************
 Function to get the top card of a deck.
 @params:
 -  *pDeck is a pointer to the deck to get top card from
 output:
 -  pointer to top card
 *********************************************************************************/

//get the top card of the deck
static struct card* GetTopCard(struct deckOfCards *pDeck)
{
    
    struct card *pCard = pDeck->pTopCard;
    if(pCard == NULL){    // if empty deck return null
        return pCard;
    }
    else{    // top card exists
        if(pCard->next == NULL){     // if only one card left
            pDeck->pTopCard = NULL;          // deck will now be empty
            pDeck->pBottomCard = NULL;
            return pCard;
            
        }
        else{    // more than one card exists
            pDeck->pTopCard = pCard->next;
            return pCard;
        }
    }
    
}


/********************************************************************************
 Function to check if the original deck order has been reached or not
 @params:
 -  *pDeck is a pointer to the deck to get top card from
 -  unsigned long int cardCount is the number of cards in the deck
 output:
 -  int true/false
 *********************************************************************************/

static int CheckDeckOrder(const struct deckOfCards *pDeck, unsigned long int cardCount)
{
    // loop through cards and compare values to int i
    struct card *temp = pDeck->pTopCard;
    unsigned long int i = 1;
    while(temp != NULL){
        if(temp->face != i){    // found an out of place card
            return 0;
        }
        i++;
        temp = temp->next;
    }
    return (cardCount == (i-1)) && 1;     // make sure we have correct# of cards in addition to order
                                          // (i-1) promoted to unsigned long

}


/********************************************************************************
 Function to allocate memory and initialize for a new card
 @params:
 -  unsigned long int face value to initialize card to
 output:
 -  pointer to newly allocated card
 *********************************************************************************/

static struct card *InitializeCard(unsigned long int face)
{
    struct card* pCard = (struct card*)malloc(sizeof(struct card));   // allocate memory for new card node
    if(pCard == NULL){ // malloc unable to allocate new memory
        return NULL;
    }
    pCard->face = face;
    pCard->next = NULL;
    return pCard;
}



/********************************************************************************
 Function to allocate memory and initialize for a new deck
 @params:
 -  unsigned long int cardCount represents how many cards in the deck
 output:
 -  pointer to newly allocated card
 *********************************************************************************/

static struct deckOfCards *InitializeDeck(unsigned long int cardCount)
{
    unsigned long int i = 1;
    struct deckOfCards *pDeck = (struct deckOfCards*)malloc(sizeof(struct deckOfCards)); // allocate memory for new deck
    if(pDeck == NULL){
        printf("Unable to allocate memory for Deck\r\n");
        return NULL;
    }
    struct card* currentCard;
    if(cardCount == 0){            // initialize empty deck
        pDeck->pTopCard = NULL;
        pDeck->pBottomCard = NULL;
    }
    else{                                   //initialize and link top card to deck
        currentCard = InitializeCard(i);
        if(currentCard == NULL){
            printf("Unable to allocate memory for card #%lu\r\n",i);
            return NULL;
        }
        pDeck->pTopCard = currentCard;
        
    }
    
    for(i = 2; i<= cardCount; i++){            //initialize rest of cards
        currentCard->next = InitializeCard(i);
        if(currentCard == NULL){
            printf("Unable to allocate memory for card #%lu\r\n",i);
            return NULL;
        }
        currentCard = currentCard->next;
        if(i == cardCount){                     //initialize and link bottom card to deck
            pDeck->pBottomCard = currentCard;
        }
    }
    
    return pDeck;
    
}


/********************************************************************************
 Function to free previously allocated memory used by both deck and cards
 @params:
 -  pointer to the decks, in hand and table
 output:
 -  none
 *********************************************************************************/

static void FreeDeckMemory(struct deckOfCards **ppDeckHand, struct deckOfCards **ppDeckTable)
{
    
    
    struct card *temp;
    struct card *next;
    temp = (*ppDeckHand)->pTopCard;  //free cards in hand
    while(temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
    temp = (*ppDeckTable)->pTopCard; //free cards in table
    while(temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(*ppDeckHand);   //free deck hand
    free(*ppDeckTable);  //free deck table
}


/********************************************************************************
 Utility Function to display a deck
 @params:
 -  pointer to the deck
 output:
 -  none
 *********************************************************************************/

void PrintDeck(const struct deckOfCards *pDeck)
{
    struct card* temp;
    temp = pDeck->pTopCard;
    if(temp == NULL){
        printf("empty\r\n");
    }
    while(temp != NULL){
        printf("card face: %lu\r\n", temp->face);
        temp = temp->next;
    }
    
    
}


/********************************************************************************
 Function to simulate one round of shuffling a deck
 @params:
 -  *hand is a pointer to deck of cards in hand
 -  *table is a pointer to deck of cards on the table
 output:
 -  none
 *********************************************************************************/

static void ShuffleRound(struct deckOfCards *hand, struct deckOfCards *table)
{
    struct card* top;
    struct card* bot;
    while(hand->pTopCard != NULL){       // while cards left to shuffle
        top = GetTopCard(hand);                 // add first card to table
        AddCardToDeck(table, top, TOP);
        if(hand->pTopCard!= NULL){
            bot = GetTopCard(hand);
            AddCardToDeck(hand, bot, BOT);        // add second card to bottom of hand
        }
    }
}







int main(int argc, char *argv[])
{
    unsigned long int numCards = 0;
    int i = 0;
    char *ptr;
    if(argc != 2){
        printf("Expecting only one parameter\r\n");
        return 0;
    }
    
    while(argv[1][i] != '\0') {
        if(!isdigit(argv[1][i])){
            printf("Card count must be a postive integer\r\n");
            return 0;
        }
        i++;
    }

    
    // assign card count
    numCards = strtoul(argv[1], &ptr, 10);
    
  
    
    
    if(numCards <= 0){
        printf("Empty Deck\r\n");
        return 0;
    }
    
    
    unsigned long roundCount = 1;
    
    
    struct deckOfCards *deckHand =  InitializeDeck(numCards);  // initialize an empty deck in hand
    struct deckOfCards *deckTable = InitializeDeck(0); // initialize an empty deck on the table
    
    // run first shuffle
    ShuffleRound(deckHand, deckTable);
    
    // shuffle and count rounds while the order does not match
    while(!CheckDeckOrder(deckTable, numCards)){
        deckHand = deckTable;
        deckTable = InitializeDeck(0);
        ShuffleRound(deckHand, deckTable);
        roundCount++;                       //track number of rounds
        if(roundCount == ULONG_MAX){  //too many rounds overflow
            printf("Round count reached max UL value\r\n");
            return 0;
        }
    }
    
    // free deck and card memory
    FreeDeckMemory(&deckHand,&deckTable);
    printf("Card Count: %lu  Round Count: %lu  \r\n", numCards, roundCount);
    
    return 0;
}




