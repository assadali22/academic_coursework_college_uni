#ifndef STANKFISTTYPE_H
#define STANKFISTTYPE_H

#include <iostream>
using namespace std;

class stankFistType
{
	friend void stinkysFriend(stankFistType &sfo); //friend included only in prototype heading
public:
	stankFistType(); //Default Constructor, initialize to 0

private:
	int stinkyVar;

};

#endif
