#include "CuckooHashTable.h"

/**
 * Since cuckoo hashing requires two tables, you should create two tables
 * of size numBuckets / 2. Because our testing harness attempts to exercise
 * a number of different load factors, you should not change the number of
 * buckets once the hash table has initially be created.
 */
CuckooHashTable::CuckooHashTable(size_t numBuckets, std::shared_ptr<HashFamily> family) {
  // TODO: Implement this
	h1 = family->get(); //hash function for table #1
	h2 = family->get(); //hash function for table number 2
	numElements = numBuckets;

	table1Size = numBuckets / 2;
	table2Size = numBuckets / 2;

	table1.resize(table1Size);
	table2.resize(table2Size);

	for (size_t i = 0; i < table1.size(); i++)
	{
			table1[i] = -1;
	}

	for (size_t i = 0; i < table2.size(); i++)
	{
			table2[i] = -1;
	}
}

CuckooHashTable::~CuckooHashTable() {
  // TODO: Implement this
}

//credit for Kiwon and Illyas for some help
void CuckooHashTable::insert(int data) {
  // TODO: Implement this
	int temp;
	int hashIndexT1 = h1(data) % table1Size;
	int hashIndexT2 = h2(data) % table2Size;

	if (contains(data))
	{
		return;
	}

	for (int i = 0; i < numElements; i++)
	{
		if (table1[hashIndexT1] == -1)
		{
			table1[hashIndexT1] = data;
			return;
		}

		if (table2[hashIndexT2] == -1)
		{
			table2[hashIndexT2] = data;
			return;
		}

		temp = table1[hashIndexT1];
		table1[hashIndexT1] = data;
		data = temp;

		hashIndexT2 = h2(data) % table2Size;

		temp = table2[hashIndexT2];
		table2[hashIndexT2] = data;
		data = temp;

		hashIndexT1 = h1(data) % table1Size;
	}

	return;

}


bool CuckooHashTable::contains(int data) const {
  // TODO: Implement this
	int i1 = h1(data) % table1Size;
	int i2 = h2(data) % table2Size;

	if (table1[i1] == data || table2[i2] == data)
	{
		return true;
	}

	return false;
}


void CuckooHashTable::remove(int data) {
  // TODO: Implement this
	int i1 = h1(data) % table1Size;
	int i2 = h2(data) % table2Size;

	if (table1[i1] == data)
	{
		table1[i1] = -1;
		return;
	}

	if (table2[i2] == data)
	{
		table2[i2] = -1;
		return;
	}

	return;
}

/*
//handle case for odd number of numBuckets
	if (numBuckets % 2 == 0)
	{
		//numBuckets is even
		table1Size = numElements / 2;
		table2Size = numElements / 2;
	}
	else
	{
		//numBuckets is odd
		table1Size = numElements / 2;
		table2Size = (numElements / 2) + 1; //split numBuckets in half and add one
	}


void CuckooHashTable::insert(int data) {
	int attempts = 0;
	int temp;
	int hashIndexT1;
	int hashIndexT2;
	int maxTries = (int) (6 * log(numElements));
	if (contains(data))
	{
		return; //prevent duplicates
	}

	while (attempts < maxTries) //changed from do while to normal while loop
	{
		//try to insert into table 1
		hashIndexT1 = h1(data) % table1Size;
		if (table1[hashIndexT1] == -1)
		{
			table1[hashIndexT1] = data;
			return;
		}
		else
		{
			//evict data occupied in table 1, swap
			temp = table1[hashIndexT1];
			table1[hashIndexT1] = data;
			data = temp;
			attempts++;

			//try to insert into table 2
			hashIndexT2 = h2(data) % table2Size;
			if (table2[hashIndexT2] == -1)
			{
				table2[hashIndexT2] = data;
				return;
			}
			else
			{
				temp = table2[hashIndexT2];
				table2[hashIndexT2] = data;
				data = temp;
				attempts++;
			}

		}//end long else
	}

	//do rehash if insertion fails
	rehash();
	return;

}

void CuckooHashTable::rehash()
{
	//take all elements out of table
	//put them into one list, then insert again
	//update hash functions for both tables
	h1 = familyFunctions->get();
	h2 = familyFunctions->get();
	vector<int> list;

	for (size_t j = 0; j < table1.size(); j++)
	{
		if (table1[j] != -1)
		{
			list.push_back(table1[j]); //store element in the list
			table1[j] = -1; //remove element from the table
		}
	}

	for (size_t j = 0; j < table2.size(); j++)
	{
		if (table2[j] != -1)
		{
			list.push_back(table2[j]);
			table2[j] = -1;
		}
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		insert(list[i]);
	}
	return;
}


*/
