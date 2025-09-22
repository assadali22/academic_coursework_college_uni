#include "RobinHoodHashTable.h"

RobinHoodHashTable::RobinHoodHashTable(size_t numBuckets, std::shared_ptr<HashFamily> family) {
  // TODO: Implement this
	robinHoodTable.resize(numBuckets);
	h = family->get();
	vectorSize = numBuckets;
	for (size_t i = 0; i < robinHoodTable.size(); i++)
	{
		robinHoodTable[i].num = -1;
		robinHoodTable[i].distanceFromHome = -1;
	}
}

//can always convert back to pointers, i forgot to put using namespace std
RobinHoodHashTable::~RobinHoodHashTable() {
  // TODO: Implement this
}

void RobinHoodHashTable::insert(int data) {
  // TODO: Implement this
	if (contains(data))
	{
		return; //prevent duplicates
	}

	int index = h(data) % vectorSize;
	dataBlock blockToInsert;
	blockToInsert.num = data;
	blockToInsert.distanceFromHome = 0;

	//loop from index to end of vector
	for (int j = index; j < vectorSize; j++)
	{
		if (robinHoodTable[j].num == -1)
		{
			robinHoodTable[j] = blockToInsert; //insert the number/data block
			return;
		}
		else
		{
			if (blockToInsert.distanceFromHome > robinHoodTable[j].distanceFromHome)
			{
				dataBlock temp;
				temp = robinHoodTable[j];
				robinHoodTable[j] = blockToInsert;
				blockToInsert = temp;
			}

			blockToInsert.distanceFromHome = blockToInsert.distanceFromHome + 1;
		}

	}
	return;

}

bool RobinHoodHashTable::contains(int data) const {
  // TODO: Implement this

	int index = h(data) % vectorSize;
	dataBlock blockSearch;
	blockSearch.num = data;
	blockSearch.distanceFromHome = 0;

	//loop from index to the end of the vector
	for (int k = index; k < vectorSize; k++)
	{
		if (robinHoodTable[k].num == data)
		{
			return true;
		}

		if (blockSearch.distanceFromHome > robinHoodTable[k].distanceFromHome)
		{
			return false;
		}
		blockSearch.distanceFromHome++;
	}

	return false;
}

/**
 * You should implement this operation using backward-shift deletion: once
 * you've found the element to remove, continue scanning forward until you
 * find an element that is at its home location or an empty cell, then shift
 * each element up to that point backwards by one step.
 */
void RobinHoodHashTable::remove(int data) {
  // TODO: Implement this

	int position = h(data) % vectorSize;

	//loop from position to end of vector
	for (int j = position; j < vectorSize; j++)
	{
		if (data == robinHoodTable[j].num)
		{
			//make the values negative sentinel values
			robinHoodTable[j].num = -1;
			robinHoodTable[j].distanceFromHome = -1;
			//go through the rest of the vector and any data that is far
			//from home can be shifted to the left, move it closer to home
			for (int shift = j; shift < vectorSize - 1; shift++)
			{
				//check if distance from home for next element is not 0, bring it closer
				if (robinHoodTable[shift + 1].distanceFromHome != 0)
				{
					dataBlock temp;
					temp = robinHoodTable[shift];
					robinHoodTable[shift] = robinHoodTable[shift + 1];
					robinHoodTable[shift + 1] = temp;
				}
				else
				{
					return;
				}
			}

			//go from beginning of vector to index of hash code minus 1
			for (int shift = 0; shift < position - 1; shift++)
			{
				//check if distance from home for next element is not 0, bring it closer
				if (robinHoodTable[shift + 1].distanceFromHome != 0)
				{
					dataBlock temp;
					temp = robinHoodTable[shift];
					robinHoodTable[shift] = robinHoodTable[shift + 1];
					robinHoodTable[shift + 1] = temp;
				}
				else
				{
					return;
				}
			}

		}//end main if statement

	}//end of main for loop

	return;
}
