#include <iostream>
using namespace std;
template <class FIRST, class SECOND> //working with 2 data types, which are unknown. Generic names are given, in this case, FIRST and SECOND

FIRST smaller(FIRST a, SECOND b)
{
	return (a < b ? a:b); //if a < b, return a, else return b
}

int main()
{
	int x = 89;
	double y = 56.78;

	//first thing passed in (x) was an integer, replace first with int, since x was passed in first. Replaces FIRST with int in the template.
	cout << "smaller(x,y) = " << smaller(x, y) << endl; //outputs 56, return type was int

	//Double data type passed in first
	cout << "smaller(y,x) = " << smaller(y, x) << endl; //outputs 56.78, double passed in first. Replaces FIRST with double in the template.

	return 0;
}
