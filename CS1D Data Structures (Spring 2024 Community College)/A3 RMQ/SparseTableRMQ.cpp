#include "SparseTableRMQ.h"


SparseTableRMQ::SparseTableRMQ(const RMQEntry* elems, std::size_t numElems) {

	nums = elems;
	rowSize = numElems;
	sparseTableColSize = 0;
	sparseTableArr = new int*[numElems];

	//BEGIN CITATION
	//floor of log base 2 required
	for (size_t row = 0; row < numElems; row++)
	{
		sparseTableArr[row] = new int[(int) (floor(log2(numElems))) + 1];
	}
	//cout << "columns initialized!" << endl;

	//store column size
	sparseTableColSize = (size_t) (floor(log2(numElems))) + 1;

	size_t i, j;
	for (i = 0; i < numElems; i++)
	{
		sparseTableArr[i][0] = i;
	}
	//cout << "lengths of 1 initialized" << endl;

	//preprocess
	for (j = 1; (size_t) (pow(2, j)) <= numElems; j++)
	{
		for (i = 0; i + (size_t) (pow(2, j)) - 1 < numElems; i++)
		{
			if (elems[sparseTableArr[i][j - 1]].value() < elems[sparseTableArr[i + (size_t) (pow(2, j - 1))][j - 1]].value())
			{
				sparseTableArr[i][j] = sparseTableArr[i][j - 1];
			}
			else
			{
				sparseTableArr[i][j] = sparseTableArr[i + (size_t) (pow(2, j - 1))][j - 1];
			}

		}

	}
	//https://www.youtube.com/watch?v=c5O7E_PDO4U
	//Sparse Table Algorithm Range Minimum Query
	//END CITATION

	//cout << "preprocess complete" << endl;

	/*
	//failed code
  //Preprocess and find maximum length, find number of columns for table
	int power;
	int m = 0;
	do
	{
		power = (int) pow(2, m);
		sparseTableColSize++;
	}
	while (power < numElems);

	
	need a nested loop for 2^1 and beyond? size 11, num entries = 9
	if (elems[sparseTable[0][i]].value < elems[sparseTable[0][i + 1].value)
	*/
}

SparseTableRMQ::~SparseTableRMQ() {

	size_t b;
	for (b = 0; b < rowSize; b++)
	{
		delete [] sparseTableArr[b];
	}

	delete [] sparseTableArr;
	nums = NULL;
}

std::size_t SparseTableRMQ::rmq(std::size_t low, std::size_t high) const {

	//cout << "entered sparse rmq func.." << endl;
	//BEGIN CITATION
	size_t l, k;

	l = high - low; //originally was high - low + 1
	k = (size_t)(floor(log2(l)));

	if (nums[sparseTableArr[low][k]].value() < nums[sparseTableArr[low + l - (size_t)(pow(2, k))][k]].value())
	{
		return sparseTableArr[low][k];
	}

	return sparseTableArr[low + l - (size_t)(pow(2, k))][k];


	//https://www.youtube.com/watch?v=c5O7E_PDO4U
	//Sparse Table Algorithm Range Minimum Query
	//END CITATION

	//return min(sparseTableArr[low][k], sparseTableArr[low + l - (size_t)(pow(2, k))][k]);

}
