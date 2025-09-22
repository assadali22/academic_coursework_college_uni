#include "PrecomputedRMQ.h"

PrecomputedRMQ::PrecomputedRMQ(const RMQEntry* elems, std::size_t numElems) {

	//array of objects for the numbers

	arrSize = numElems;
	size_t i, j;
	size_t m;
	//Make dynamic 2D array
	lookupTable = new size_t*[numElems];
	//cout << "Row pointers declared" << endl;

	//Make the staircase of rows
	for (i = 0; i < numElems; i++)
	{
		lookupTable[i] = new size_t[i + 1];
	}
	//cout << "Column staircase created" << endl;

	//Fill the diagonals with the array index
	//diagonals represent indicies of original array 0-...
	for (i = 0, j = 0; i < numElems && j < numElems; i++, j++)
	{
		lookupTable[i][j] = i;
		//cout << lookupTable[i][j] << " ";
	}
	//cout << endl;
	//cout << "end of diagonal filling" << endl;


	//Dynamic programming concept, compare values at specified indicies and fill table
	//fill in index for the table. we want to obtain the value when making the comparasion
	//want to traverse diagonally from top right to bottom left like a staircase for each row.
	size_t var = 0;
	for (m = 1; m < numElems; m++)
	{
		var = m;
		for (j = 0; j < numElems - m; j++)
		{
			if (elems[lookupTable[var - 1][j]].value() < elems[lookupTable[var][j + 1]].value())
			{
				lookupTable[var][j] = lookupTable[var - 1][j];
			}
			else
			{
				lookupTable[var][j] = lookupTable[var][j + 1];
			}
			var++;
		}
	}

	/*
  //more failed code and attempts in these comments
  //originally
	for (m = 0; m < numElems - 1; m++)
	{
		for (i = m + 1, j = 0; i < numElems - j && j < numElems - i; i++, j++)
		{
			if (elems[lookupTable[i - 1][j]].value() < elems[lookupTable[i][j + 1]].value())
			{
				lookupTable[i][j] = lookupTable[i - 1][j];
			}
			else
			{
				lookupTable[i][j] = lookupTable[i][j + 1];
			}
		}
	}

	*/

	/*
	for (m = 0; m < numElems - 1; m++)
	{
		for (i = m + 1, j = m; i < numElems - j; i++, j++)
		{
			if (elems[lookupTable[i - 1][j]].value() < elems[lookupTable[i][j + 1]].value())
			{
				lookupTable[i][j] = lookupTable[i - 1][j];
			}
			else
			{
				lookupTable[i][j] = lookupTable[i][j + 1];
			}
		}
	}
	*/


	/*
	for (i = 1; i < numElems; i++)
	{
		for (j = i - 1; j < numElems - i; j++)
		{
			//elems is a pointer to an array of objects containing the value
			if (elems[lookupTable[i - 1][j]].value() < elems[lookupTable[i][j + 1]].value())
			{
				lookupTable[i][j] = lookupTable[i - 1][j];
			}
			else
			{
				lookupTable[i][j] = lookupTable[i][j + 1];
			}

		}
	}


	//this one also works (no it somehow doesnt?)
	for (i = 1; i < numElems; i++)
	{
		for (j = i - 1; j < i + 1; j++)
		{
			//elems is a pointer to an array of objects containing the value
			if (elems[lookupTable[i - 1][j]].value() < elems[lookupTable[i][j + 1]].value())
			{
				lookupTable[i][j] = lookupTable[i - 1][j];
			}
			else
			{
				lookupTable[i][j] = lookupTable[i][j + 1];
			}

		}
	}


	//failed modification
	for (i = 1; i < numElems; i++)
	{
		for (j = i + 1; j < numElems; j++)
		{
			//elems is a pointer to an array of objects containing the value
			if (elems[lookupTable[i][j - 1]].value() < elems[j].value())
			{
				lookupTable[i][j] = lookupTable[i][j - 1];
			}
			else
			{
				lookupTable[i][j] = j;
			}

		}
	}


	more failed code
	for (m = 1; m < numElems; m++)
	{
		for (i = m, j = 0; i < numElems - j && j < numElems - i; i++, j++)
		{
			if (elems[lookupTable[i - 1][j]].value() < elems[lookupTable[i][j + 1]].value())
			{
				lookupTable[i][j] = lookupTable[i - 1][j];
			}
			else
			{
				lookupTable[i][j] = lookupTable[i][j + 1];
			}
		}
	}
	*/

	//cout << "dynamic programming complete.." << endl;

}

PrecomputedRMQ::~PrecomputedRMQ() {

	size_t k;
	for (k = 0; k < arrSize; k++)
	{
		delete [] lookupTable[k];
	}

	delete [] lookupTable;
	//cout << "Lookup table deallocated." << endl;
}

std::size_t PrecomputedRMQ::rmq(std::size_t low, std::size_t high) const {

	if (arrSize == 1)
	{
		return 0;
	}
	//has to be high - 1, rmq(0, 4) for example returns smallest between index 0-3
	//return lookupTable[low][high - 1]; (was wrong)
	return lookupTable[high - 1][low];

}
