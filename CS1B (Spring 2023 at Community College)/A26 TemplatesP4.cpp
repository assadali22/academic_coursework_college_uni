//Template specialization a way to make a class that has a different
//implementation when a specific type is passed into it

#include <iostream>
using namespace std;

//Basic template
template <class T>
class Spunky
{
public:
	Spunky(T x)
	{
		cout << x << " is not a character!" << endl;
	}
};

//Do something differently when a character is passed into the template.
//Template specialization
template <>
class Spunky<char> //special class to handle char
{
public:
	Spunky(char x)
	{
		cout << x << " is indeed a character!" << endl;
	}
};
//When a character is encountered, it will be handled by specialized template.

int main()
{
	Spunky<int> obj1(7);
	Spunky<double> obj2(3.154);
	Spunky<char> obj3('q');


	return 0;
}
