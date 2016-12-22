# ShuffleRoundCount
Coding challenge


I decided to implement this solution using two different data structures, one to represent a deck (struct deckOfCards)
and one to represent a card (struct card). The deck's order is represented as a singly linked list of card structures.
Having a deckOfCards structure with pointer to top and bottom cards allows constant time insertion 
into a deck, since we only ever insert a card to the top or bottom. This also allows the saving
of O(n) memory for the extra pointer otherwise required in a doubly linked list implementation. 

Overall, the code take in a positive number argument representing the number of cards in the deck.
The input is checked to make sure we have the correct number of arguments and input type.

I then initialize two decks, one in hand with n cards, and an empty deck on the table.
After shuffling the frist round, I jump into a while loop, where I repeatedly shuffle and check the deck order,
keeping track of the shuffle count. 

I chose unsigned long integers to represent the data, since card count will always be > 0 and allows for large shuffle and card counts

The deck in the left hand represents a geometric series where the factor is 1/2, requring 2n-1 passes to shuffle 
the deck completely. Check the deck order also requires n passes.
This straightforward algorithm requires O(R * n) time where R is the round count and n is the card count.

Sample output:

$Coding Challenge Neel$ gcc -o out  ShuffleRoundCount.c 

$Coding Challenge Neel$ ./out 

Expecting only one parameter 

$Coding Challenge Neel$ ./out 0 

Empty Deck 

$Coding Challenge Neel$ ./out -99 

Card count must be a postive integer 

$Coding Challenge Neel$ ./out 1.0 

Card count must be a postive integer 

$Coding Challenge Neel$ ./out 1 

Card Count: 1  Round Count: 1   

$Coding Challenge Neel$ ./out 13 

Card Count: 13  Round Count: 12   

$Coding Challenge Neel$ ./out 31 

Card Count: 31  Round Count: 210   

$Coding Challenge Neel$ ./out 82 

Card Count: 82  Round Count: 55440   

$Coding Challenge Neel$ ./out 200 

Card Count: 200  Round Count: 8460   


Sample Test output where n is 0-99:

Empty Deck

Card Count: 1  Round Count: 1  

Card Count: 2  Round Count: 2  

Card Count: 3  Round Count: 3  

Card Count: 4  Round Count: 2  

Card Count: 5  Round Count: 5  

Card Count: 6  Round Count: 6  

Card Count: 7  Round Count: 5  

Card Count: 8  Round Count: 4  

Card Count: 9  Round Count: 6  

Card Count: 10  Round Count: 6  

Card Count: 11  Round Count: 15  

Card Count: 12  Round Count: 12  

Card Count: 13  Round Count: 12  

Card Count: 14  Round Count: 30  

Card Count: 15  Round Count: 15  

Card Count: 16  Round Count: 4  

Card Count: 17  Round Count: 17  

Card Count: 18  Round Count: 18  

Card Count: 19  Round Count: 10  

Card Count: 20  Round Count: 20  

Card Count: 21  Round Count: 21  

Card Count: 22  Round Count: 14  

Card Count: 23  Round Count: 24  

Card Count: 24  Round Count: 90  

Card Count: 25  Round Count: 63  

Card Count: 26  Round Count: 26  

Card Count: 27  Round Count: 27  

Card Count: 28  Round Count: 18  

Card Count: 29  Round Count: 66  

Card Count: 30  Round Count: 12  

Card Count: 31  Round Count: 210  

Card Count: 32  Round Count: 12  

Card Count: 33  Round Count: 33  

Card Count: 34  Round Count: 90  

Card Count: 35  Round Count: 35  

Card Count: 36  Round Count: 30  

Card Count: 37  Round Count: 110  

Card Count: 38  Round Count: 120  

Card Count: 39  Round Count: 120  

Card Count: 40  Round Count: 26  

Card Count: 41  Round Count: 41  

Card Count: 42  Round Count: 42  

Card Count: 43  Round Count: 105  

Card Count: 44  Round Count: 30  

Card Count: 45  Round Count: 45  

Card Count: 46  Round Count: 30  

Card Count: 47  Round Count: 60  

Card Count: 48  Round Count: 48  

Card Count: 49  Round Count: 120  

Card Count: 50  Round Count: 50  

Card Count: 51  Round Count: 42  

Card Count: 52  Round Count: 510  

Card Count: 53  Round Count: 53  

Card Count: 54  Round Count: 1680  

Card Count: 55  Round Count: 120  

Card Count: 56  Round Count: 1584  

Card Count: 57  Round Count: 57  

Card Count: 58  Round Count: 336  

Card Count: 59  Round Count: 276  

Card Count: 60  Round Count: 60  

Card Count: 61  Round Count: 2665  

Card Count: 62  Round Count: 720  

Card Count: 63  Round Count: 8415  

Card Count: 64  Round Count: 12  

Card Count: 65  Round Count: 720  

Card Count: 66  Round Count: 66  

Card Count: 67  Round Count: 120  

Card Count: 68  Round Count: 68  

Card Count: 69  Round Count: 840  

Card Count: 70  Round Count: 336  

Card Count: 71  Round Count: 4347  

Card Count: 72  Round Count: 210  

Card Count: 73  Round Count: 286  

Card Count: 74  Round Count: 870  

Card Count: 75  Round Count: 66  

Card Count: 76  Round Count: 50  

Card Count: 77  Round Count: 621  

Card Count: 78  Round Count: 78  

Card Count: 79  Round Count: 24  

Card Count: 80  Round Count: 210  

Card Count: 81  Round Count: 9690  

Card Count: 82  Round Count: 55440  

Card Count: 83  Round Count: 3465  

Card Count: 84  Round Count: 1122  

Card Count: 85  Round Count: 5040  

Card Count: 86  Round Count: 370  

Card Count: 87  Round Count: 87  

Card Count: 88  Round Count: 720  

Card Count: 89  Round Count: 630  

Card Count: 90  Round Count: 90  

Card Count: 91  Round Count: 783  

Card Count: 92  Round Count: 92  

Card Count: 93  Round Count: 78  

Card Count: 94  Round Count: 50  

Card Count: 95  Round Count: 95  

Card Count: 96  Round Count: 96  

Card Count: 97  Round Count: 6435  

Card Count: 98  Round Count: 132  

Card Count: 99  Round Count: 780  

