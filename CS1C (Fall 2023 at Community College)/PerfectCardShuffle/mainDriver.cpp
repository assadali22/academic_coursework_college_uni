#include <iostream>
#include "cardType.h"
#include "deckType.h"
using namespace std;

int main()
{
    int perfectShuffles = 0;
    deckType originalDeck; //standard initialized deck
    deckType deck2; //deck used for perfect shuffling

    //Deck Initialization
    originalDeck.initializeDeck();
    deck2.initializeDeck();
    cout << "AFTER INITIALIZING ORIGINAL DECK: " << endl;
    cout << "--------------------------------------------------------" << endl;
    originalDeck.printDeck();
    cout << endl << endl;


    cout << "After initializing a 2nd deck for shuffling: " << endl;
    cout << "--------------------------------------------------------" << endl;
    deck2.printDeck();
    cout << endl << endl;
    cout << boolalpha;
    cout << "After initializing both decks, originalDeck = deck2?: 0 = false, 1 = true: " << deck2.compareDeck(originalDeck) << endl;


    //One perfect shuffle
    deck2.perfectShuffle();
    perfectShuffles++;
    cout << "Printing deck2 after a perfect shuffle: " << endl;
    cout << "--------------------------------------------------------" << endl;
    deck2.printDeck();
    cout << "After one perfect shuffle of deck2, originalDeck = deck2?: 0 = false, 1 = true: " << deck2.compareDeck(originalDeck) << endl << endl;


    //Do multiple perfect shuffles
    cout << "Now doing multiple perfect shuffles to get to the original deck." << endl;
    while (deck2.compareDeck(originalDeck) != 1)
    {
        deck2.perfectShuffle();
        perfectShuffles++;
    }

    cout << "Number of perfect shuffles to go back to original deck: " << perfectShuffles << endl;
    cout << "After perfect shuffles, originalDeck = deck2?: 0 = false, 1 = true: " << deck2.compareDeck(originalDeck) << endl;
    cout << "Printing deck after doing perfect shuffles (final deck):" << endl;
    cout << "--------------------------------------------------------" << endl;
    deck2.printDeck();


    return 0;
}


/*
//testing a single card
    int rankInput;
    cout << "Set a rank for club card, Ace = 1, King = 11, Queen = 12, Jack = 13: ";
    cin >> rankInput;
    cardType card1;
    card1.setSuit("Clubs");
    card1.setRank(rankInput);
    cout << "Printing card: " << endl;
    card1.printCard();
*/
