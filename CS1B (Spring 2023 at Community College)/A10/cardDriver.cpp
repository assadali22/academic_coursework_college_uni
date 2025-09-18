//-----------------------------------------------------------------------
//Purpose: This program creates 3 credit cards with card number, card   -
//name, and expiration date being private data members. The getter      -
//and setter functions are in a header file and the code to get or edit -
//the data is in creditcard.cpp. The balance on each card is also       -
//kept track when a purchase is made and an appropriate message is      -
//printed if a purchase will exceed the credit limit of $10000.         -
//-----------------------------------------------------------------------


#include "creditcard.h"

int main()
{
	string number;
	string expDate;
	string name;

	creditCardType card1;
	cout << "Number of cards: " << card1.getCount() << endl; //1 card

	creditCardType card2("7395 1929 1248 1954", "Sam Smith", "11/2027");
	cout << "Number of cards: " << card2.getCount() << endl; //output 2

	creditCardType card3("6527 8636 7521 1114", "John Apple", "04/2026");
	cout << "Number of cards: " << card3.getCount() << endl; //output 3


	//Set Data for Card 1
	cout << "Enter card number for Card #1: ";
	getline(cin, number);
	card1.setCardNumber(number);

	cin.ignore(100, '\n');
	cout << "Enter expiration date for Card #1: ";
	cin >> expDate;
	card1.setExpiration(expDate);

	cin.ignore(100, '\n');
	cout << "Enter the name on Card #1: ";
	getline(cin, name);
	card1.setName(name);

    cout << endl;
    cout << "Test Card #1:" << endl;
	cout << "$500 purchase on Card #1" << endl;
	card1.purchase(500);
	cout << endl;
	cout << "Data for credit card #1: " << endl;
	card1.print(); //print data and balance
    cout << "-------------------------------------------------------" << endl;


    cout << "Test Card #2:" << endl;
	cout << "$5000 purchase on Card #2" << endl;
	card2.purchase(5000);
	cout << endl;
	cout << "Data for credit card #2: " << endl;
	card2.print();


    cout << "-------------------------------------------------------" << endl;
    cout << "Test Card #3:" << endl;
	cout << "$12000 purchase on Card #3" << endl;
	card3.purchase(12000);
	cout << endl;
	cout << "Data for credit card #3: " << endl;
	card3.print();

	return 0;

}


/*
Create 3 credit cards that are tied to the same account.
Every time you create a card, increment the count by one
(in the constructor(s)). After each card creation, print out count.

Set credit limit to $10000.00 (inside creditCardType.cpp)

In your driver:

call static fn  getCount(). Then....

Make 3 purchases (i.e. $500, i.e. $5000, i.e $20000) using the 3 different cards.

After each purchase, call the credit cards' print method and call the static fn getBalance().

Private static variables:
count (i.e. 5 would mean 5 credit cards were created)
credit limit
balance
public static functions

int getCount(), returns count
float getCreditLimit(), returns credit limit
float getBalance(), return current balance.
*/
