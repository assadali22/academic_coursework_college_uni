#ifndef CARDTYPE_H
#define CARDTYPE_H

#include <iostream>
#include <string>
using namespace std;

class cardType
{
public:
    void setSuit(string s);
    void setRank(int r);

    string getSuit() const;
    int getRank() const;

    void printCard() const;

private:
    string suit; //clubs, hearts, diamonds, spades
    int cardRank; //A = 1, 2-10, K = 11, Q = 12, J = 13
};
#endif // CARDTYPE_H
