#include "LinearProbingHashTable.h"

LinearProbingHashTable::LinearProbingHashTable(size_t numBuckets, std::shared_ptr<HashFamily> family) {
  // TODO: Implement this
	table.resize(numBuckets);
	tableSize = numBuckets;
  h = family->get();
	//initialize table to -1 for all inidicies
	for (size_t i = 0; i < table.size(); i++)
	{
		table[i] = -1;
	}
}

LinearProbingHashTable::~LinearProbingHashTable() {
  // TODO: Implement this
}

void LinearProbingHashTable::insert(int data) {
  // TODO: Implement this
	//prevent duplicate values
	if (contains(data))
	{
		return;
	}

	int location = h(data) % tableSize;

	//loop from location to end of vector
	for (size_t i = location; i < table.size(); i++)
	{
		if (table[i] == -1 || table[i] == -5)
		{
			table[i] = data;
			return;
		}
	}

	//loop from beginning of vector to the location to check for empty spots
	//or tombstone for insertion
	for (int i = 0; i < location; i++)
	{
		if (table[i] == -1 || table[i] == -5)
		{
			table[i] = data;
			return;
		}
	}

	return;
}

bool LinearProbingHashTable::contains(int data) const {
  // TODO: Implement this
	//stop searching if we find an empty spot (aka spot is -1)
	//dont stop at tombstones, continue search
	int location = h(data) % tableSize;

	//loop from location to end of vector
	for (size_t i = location; i < table.size(); i++)
	{
		if (table[i] == -1)
		{
			return false;
		}

		if (data == table[i])
		{
			return true;
		}
	}

	//loop from beginning of vector to the location to check for empty spots
	for (int i = 0; i < location; i++)
	{
		if (table[i] == -1)
		{
			return false;
		}

		if (data == table[i])
		{
			return true;
		}
	}

	return false;
}

void LinearProbingHashTable::remove(int data) {
  // TODO: Implement this
	//let a tombstone represent -5

	int location = h(data) % tableSize;

	//loop from location to end of vector
	for (size_t i = location; i < table.size(); i++)
	{
		if (table[i] == -1)
		{
			return;
		}

		if (data == table[i])
		{
			table[i] = -5;
			return;
		}
	}

	//loop from beginning of vector to the location to check for empty spots
	for (int i = 0; i < location; i++)
	{
		if (table[i] == -1)
		{
			return;
		}

		if (data == table[i])
		{
			table[i] = -5;
			return;
		}
	}
}

