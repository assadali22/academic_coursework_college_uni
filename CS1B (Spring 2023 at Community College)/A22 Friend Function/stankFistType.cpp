#include "stankFistType.h"


//Default Constructor
stankFistType::stankFistType()
{
	stinkyVar = 0;
}

//Friend function, can access the class, private and public members
void stinkysFriend(stankFistType &sfo)
{
	sfo.stinkyVar = 99;
	cout << "Sticky var = " << sfo.stinkyVar << endl;
}
