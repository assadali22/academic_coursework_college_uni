#ifndef DECKTYPE_H
#define DECKTYPE_H
#include <iostream>
#include <string>
#include "cardType.h"
using namespace std;
const int NUM_CARDS = 52;
class deckType
{
public:
    void initializeDeck();
    void printDeck() const;

    void perfectShuffle();
    bool compareDeck(const deckType& other) const;

private:
    cardType cards[NUM_CARDS];

};

#endif // DECKTYPE_H
