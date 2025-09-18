#include <iostream>
using namespace std;

template <class T>
class Bucky
{
	T first;
	T second;

public:
	Bucky(T a, T b) //passing in 2 numbers of unknown data type
	{
		first = a;
		second = b;
	}
	T bigger();
};

//Important: After class name, add <T> to tell C++ that the function's template
//parameter is the same one we are going to use for the class
template <class T>
T Bucky<T>::bigger() //T is the generic return type
{
	return (first > second ? first:second); //if first > second, return first, else return second.
}


int main()
{
	Bucky <int> newObj(69, 195);
	//Important: Specify what type of data we want to substitute for T. Between class name and object,
	//pass in the data type to substitute T.

	cout << newObj.bigger() << endl;
	return 0;
}
