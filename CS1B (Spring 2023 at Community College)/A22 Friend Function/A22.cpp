//-----------------------------------------------------------------------
//Purpose: This program implements Bucky's C++ Programming Tutorials,   -
//specifically on how friend functions work, using a simple program.    -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Create an object that is of stankFistType.                    -
//Step 2: Pass the object into the friend function stinkysFriend, which -
//will set the value of stinkyVar to 99 and display it on the screen.   -
//Step 3: Quit                                                          -
//-----------------------------------------------------------------------

#include "stankFistType.h"

int main()
{
	stankFistType bob;
	stinkysFriend(bob); //pass in the object bob, should print 99

	return 0;
}
