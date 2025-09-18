#include <iostream>
using namespace std;
//Similar function bodies, but we want to work with different data types
//Template: generic type of data
template <class bucky>

bucky addCrap(bucky a, bucky b)
{
	return (a + b);
}

int main()
{
	cout << "This program implements function templates." << endl;
	//Variables to test data
	int x = 7, y = 43;
	double d1 = 5.6;
	double d2 = 7.2;
	char ch1 = '#';
	char ch2 = '$';
	string str1 = "Door";
	string str2 = "bell";

	//Variables for outputting data
	int z;
	double sum;
	char chSum;
	string str3;

	//Add integers
	cout << "Adding x = " << x << " and y = " << y << endl;
	z = addCrap(x, y);
	cout << "z = " << z << endl;

	//Add doubles
	cout << "Adding d1 = " << d1 << " and d2 = " << d2 << endl;
	sum = addCrap(d1, d2);
	cout << "Sum = " << sum << endl;

	//Add chars
	cout << "Adding ch1 = " << ch1 << " and ch2 = " << ch2 << endl;
	chSum = addCrap(ch1, ch2);
	cout << "chSum = " << chSum << endl;

	//Add strings
	cout << "Adding str1 = " << str1 << " and str2 = " << str2 << endl;
	str3 = addCrap(str1, str2);
	cout << "str3 = " << str3 << endl;

	return 0;
}

