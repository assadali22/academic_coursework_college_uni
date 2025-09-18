#include "deckType.h"
#include "cardType.h"

void deckType::initializeDeck()
{
    int index = 0;
    int i = 0;

    //Initialize clubs
    for (i = 1; i <= 13; i++)
    {
        cards[index].setSuit("Clubs");
        cards[index].setRank(i);
        index++;
    }

    //Initialize hearts
    for (i = 1; i <= 13; i++)
    {
        cards[index].setSuit("Hearts");
        cards[index].setRank(i);
        index++;
    }

    //Initialize diamonds
    for (i = 1; i <= 13; i++)
    {
        cards[index].setSuit("Diamonds");
        cards[index].setRank(i);
        index++;
    }

    //Initialize spades
    for (i = 1; i <= 13; i++)
    {
        cards[index].setSuit("Spades");
        cards[index].setRank(i);
        index++;
    }
}


void deckType::perfectShuffle()
{
    //New card order (position of each card by number, subtract 1 for index interpretation)
    //1, 27, 2, 28, 3, 29, 4, 30, 5, 31, 6, 32, 7, 33, 8, 34, 9, 35, 10, 36, 11, 37, 12, 38, 13, 39, 14, 40, 15, 41, 16, 42, 17, 43, 18, 44, 19, 45, 20, 46, 21, 48, 22, 49, 23, 50, 24, 51, 25, 52, 26
    cardType tempCards[NUM_CARDS];
    int i = 0;
    for (i = 0; i < NUM_CARDS / 2; i++)
    {
        tempCards[i] = cards[i];
    }


    //Shuffle 1st half
    int tempIndex = 0;
    for (i = 0; i < NUM_CARDS / 2; i++)
    {
        tempCards[tempIndex] = cards[i];
        tempIndex += 2;
    }

    tempIndex = 1;
    //Shuffle 2nd half
    for (i = NUM_CARDS / 2; i < NUM_CARDS; i++)
    {
        tempCards[tempIndex] = cards[i];
        tempIndex += 2;
    }

    //Assign cards to be the new temp deck that was just shuffled
    for (i = 0; i < NUM_CARDS; i++)
    {
        cards[i] = tempCards[i];
    }

}


void deckType::printDeck() const
{
    int k;
    for (k = 0; k < NUM_CARDS; k++)
    {
        cards[k].printCard();
    }
    cout << "--------------------------------------------------------" << endl;
}


bool deckType::compareDeck(const deckType& other) const
{

    bool exact = true;
    int i;
    for (i = 0; i < NUM_CARDS; i++)
    {
        if ((cards[i].getRank() != other.cards[i].getRank()) || ((cards[i].getSuit()).compare(other.cards[i].getSuit()) != 0))
        {
            exact = false;
            return exact;
        }
    }

    return exact;
}
