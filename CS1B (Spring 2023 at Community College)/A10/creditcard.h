#ifndef CREDITCARD_H_
#define CREDITCARD_H_

#include <iostream>
#include <string>

using namespace std;

class creditCardType
{
private:
	static int count;
	static float creditLimit;
	static float balance;
	string cardNumber;
	string cardName;
	string expiration;

public:
	creditCardType();
	creditCardType(string, string, string);

	//Setters
	void setCardNumber(string cardNum);
	void setName(string name);
	void setExpiration(string exp);

    /*
    //don't need these
	static void setCount(int c);
	static void setBalance(float bal);
	static void setCreditLimit(float cardLim);
    */

	//Getters
	string getCardNumber() const;
	string getName() const;
	string getExpiration() const;

	static int getCount();
	static float getCreditLimit();
	static float getBalance();

	void print() const;
	void purchase(float purch);
	bool equals(creditCardType &other) const;
};

#endif
