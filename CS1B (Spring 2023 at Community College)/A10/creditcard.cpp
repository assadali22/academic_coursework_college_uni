#include "creditcard.h"
int creditCardType::count = 0;
float creditCardType::balance = 0;
float creditCardType::creditLimit = 15000.00;

//When a new card is created, count goes up by one in constructor.
//Constructors
creditCardType::creditCardType()
{
	cout << "Default constructor called." << endl;
	setCardNumber("0000 0000 0000 0000");
	setName("First Last");
	setExpiration("MM/YYYY");
	count++;
}

creditCardType::creditCardType(string cardNum, string name, string exp)
{
	cout << "Constructor to take in all private members called." << endl;
	setCardNumber(cardNum);
	setName(name);
	setExpiration(exp);
    count++;
}

//In a destructor, count would go down one. count--; in the function

//Setters
void creditCardType::setCardNumber(string cardNum)
{
	cardNumber = cardNum;
}


void creditCardType::setName(string name)
{
	cardName = name;
}


void creditCardType::setExpiration(string exp)
{
	expiration = exp;
}



//Getters
string creditCardType::getCardNumber() const
{
	return cardNumber;
}


string creditCardType::getName() const
{
	return cardName;
}


string creditCardType::getExpiration() const
{
	return expiration;
}


//Static getters
int creditCardType::getCount()
{
	return count;
}


float creditCardType::getCreditLimit()
{
	return creditLimit;
}


float creditCardType::getBalance()
{
	return balance;
}


//Print, Purchase, Equals methods
void creditCardType::print() const
{
	cout << "Card Number: " << getCardNumber() << endl;
	cout << "Expiration Date: " << getExpiration() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Balance: " << getBalance() << endl;
	cout << "Credit Limit: " << getCreditLimit() << endl;
}

//Getters for static variables not necessary, you are in the function. No static setters needed either, you dont make them in the first place.
void creditCardType::purchase(float purch)
{
	float newBal = 0;
	if (purch + getBalance() > getCreditLimit())
	{
		cout << "Purchase of $" << purch << " will exceed credit limit, card declined." << endl;
		return;
	}
	else
	{
		cout << "Purchase of $" << purch << " successful." << endl;
		newBal = purch + getBalance();
		balance = newBal;
	}
}

bool creditCardType::equals(creditCardType &other) const
{
	bool same = false;

	if (getName().compare(other.getName()) == 0)
		same = true;
	else
		return false;

	if (getCardNumber().compare(other.getCardNumber()) == 0)
		same = true;
	else
		return false;

	if (getExpiration().compare(other.getExpiration()) == 0)
		same = true;
	else
		return false;


	return same;
}


/*
//Static setters
void creditCardType::setCount(int c)
{
	count = c;
}


void creditCardType::setBalance(float bal)
{
	balance = bal;
}


void creditCardType::setCreditLimit(float cardLim)
{
	creditLimit = cardLim;
}
*/
