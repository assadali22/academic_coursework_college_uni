#include "cardType.h"

void cardType::setSuit(string s)
{
    suit = s;
}


void cardType::setRank(int r)
{
    cardRank = r;
}


string cardType::getSuit() const
{
    return suit;
}


int cardType::getRank() const
{
    return cardRank;
}


void cardType::printCard() const
{
    if (cardRank == 1) //ace
    {
        cout << "Ace of " << suit << endl;
    }
    else if (cardRank == 11) //king
    {
        cout << "King of " << suit << endl;
    }
    else if (cardRank == 12) //queen
    {
        cout << "Queen of " << suit << endl;
    }
    else if (cardRank == 13) //jack
    {
        cout << "Jack of " << suit << endl;
    }
    else
    {
        cout << cardRank << " of " << suit << endl;
    }
}

