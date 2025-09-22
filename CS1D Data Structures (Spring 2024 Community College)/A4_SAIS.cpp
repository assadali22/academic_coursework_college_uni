#include "SAIS.h"
#include <iostream>
using namespace std;

void findSuffixTypes(const vector<size_t>& text, char* &typeSuffixes);
void setBucketPointers(const vector<size_t>& text, int** &headTailArr, const size_t asciiTable[]);

SuffixArray sais(const vector<size_t>& text) {


	//text is passed in rank order
	//given abracadabra$, sequence is [1, 2, 5, 1, 3, 1, 4, 1, 2, 5, 1, 0]
	//$ = 0, a = 1, b = 2, c = 3, d = 4, r = 5
/*
index 0	1	2	3	4	5	6	7	8	9	10	11
		a  b  r  a  c  a  d  a  b  r  a   $
rank  1  2  5  1  3  1  4  1  2  5  1   0
type                    L  S  S  L  L   S

So, rank order follows the same rules as if we looked at only the string when finding the types.

Even though the string itself is not passed in, the rank order behaves
 the same way when looking for L or S types.

*/
	//count distinct elements in text (128 possible characters to represent ascii)
	//dynamic 2D array needed, 2 columns (one for head, one for tail)
	//number of rows is the number of distinct letters
	//make the buckets and the appropriate sizes for how much of each element there is
	//(ex. 3 'a' in banana buckets mean 3 slots for 'a' bucket)


	//print rank order
	int numBuckets = 0;
	for (size_t k = 0; k < text.size(); k++)
	{
		cout << text[k] << " ";
	}
	cout << endl;

	//distinct elements array for ascii
	size_t asciiTable[128] = {0};
	for (size_t j = 0; j < text.size(); j++)
	{
		asciiTable[text[j]]++;
	}

	//print ascii table
	for (size_t i = 0; i < 128; i++)
	{
		if (asciiTable[i] > 0)
		{
			numBuckets++;
			cout << "asciiTable[" << i << "] = " << asciiTable[i] << endl;
		}
	}


	//parallel array to the string, mark the L and S types
	char *typeSuffixes = new char[text.size()];
	typeSuffixes[text.size() - 1] = 'S';

	cout << "start filling suffix types" << endl;
	findSuffixTypes(text, typeSuffixes);
	cout << "suffix types done, printing L and S type array" << endl;

	//print text and type suffix array (test if it works)
	cout << endl;
	for (size_t k = 0; k < text.size(); k++)
	{
		cout << text[k] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < text.size(); i++)
	{
		cout << typeSuffixes[i] << " ";
	}
	cout << endl;

	//parallel array for marking LMS types and initalize all to '0'
	char *lmsTypeArr = new char[text.size()];
	for (size_t i = 0; i < text.size(); i++)
	{
		lmsTypeArr[i] = '0';
	}


	lmsTypeArr[text.size() - 1] = '*'; //mark lms type with a star
	for (int i = text.size() - 2; i >= 1; i--)
	{
		if (typeSuffixes[i] == 'S' && typeSuffixes[i - 1] == 'L')
		{
			lmsTypeArr[i] = '*';
		}
	}

	//print lms arr
	cout << endl;
	for (size_t k = 0; k < text.size(); k++)
	{
		cout << lmsTypeArr[k] << " ";
	}
	cout << endl;


	//Create head and tail 2D array
	int **headTail = NULL;
	headTail = new int*[numBuckets]; //make the rows
	for (int row = 0; row < numBuckets; row++)
	{
		headTail[row] = new int[2]; //create 2 columns for each row
	}

	headTail[0][0] = 0; //head for $ bucket
	headTail[0][1] = 0; //tail for $ bucket (same as head, single slot)
	setBucketPointers(text, headTail, asciiTable); //helper to set bucket pointers

	/*
	//test for string ACGTGCCTAGCCTACCGTGCC$
	cout << "headtail[1][0] (head of rank 1 letter) = " << headTail[1][0] << endl;
	cout << "headtail[1][1] (tail of rank 1 letter) = " << headTail[1][1] << endl;
	cout << "headtail[2][0] (head of rank 2 letter) = " << headTail[2][0] << endl;
	cout << "headtail[2][1] (tail of rank 2 letter) = " << headTail[2][1] << endl;
	cout << "headtail[3][0] (head of rank 3 letter) = " << headTail[3][0] << endl;
	cout << "headtail[3][1] (tail of rank 3 letter) = " << headTail[3][1] << endl;
	cout << "headtail[4][0] (head of rank 4 letter) = " << headTail[4][0] << endl;
	cout << "headtail[4][1] (tail of rank 4 letter) = " << headTail[4][1] << endl;
	*/

	vector<size_t> suffixArr(text.size(), 0);
	suffixArr[0] = text.size() - 1; //$ bucket, last index with sentinel
	cout << "suffixArr[0] = " << suffixArr[0] << endl;

	//Scan right to left of string and fill in lms types at the end buckets of suffix array
	//first character in string can never be LMS type
	for (int k = text.size() - 2; k >= 1; k--)
	{
		if (lmsTypeArr[k] == '*')
		{
			size_t letter = text[k];
			suffixArr[headTail[letter][1]] = k; //get the tail for the appropriate bucket
			headTail[letter][1] = headTail[letter][1] - 1; //update tail
		}
	}

	//check suffix arr output
	cout << endl;
	cout << "FIRST PASS: " << endl;
	for (size_t k = 0; k < suffixArr.size(); k++)
	{
		cout << suffixArr[k] << " ";
	}
	cout << endl;

	//pass one complete
	//reinitialize head and tail for each bucket
	setBucketPointers(text, headTail, asciiTable);

	size_t letterRank;
	//Scan left to right of suffix array and find L-types, append to front of bucket
	for (size_t n = 0; n < suffixArr.size(); n++)
	{
		if (suffixArr[n] != 0)
		{
			if (typeSuffixes[suffixArr[n] - 1] == 'L')
			{
				letterRank = text[suffixArr[n] - 1];
				suffixArr[headTail[letterRank][0]] = suffixArr[n] - 1;
				headTail[letterRank][0]++; //move head up, update it
			}
		}
	}

	cout << "SECOND PASS FOR SUFFIX ARRAY: " << endl;
	for (size_t k = 0; k < suffixArr.size(); k++)
	{
		cout << suffixArr[k] << " ";
	}
	cout << endl;

	//after second pass, reinitialize head and tail pointers for the buckets
	setBucketPointers(text, headTail, asciiTable);

	//Scan right to left of suffix array, find s-types, append to back of bucket
	for (int n = suffixArr.size() - 1; n >= 0; n--)
	{
		if (suffixArr[n] != 0)
		{
			if (typeSuffixes[suffixArr[n] - 1] == 'S')
			{
				letterRank = text[suffixArr[n] - 1];
				suffixArr[headTail[letterRank][1]] = suffixArr[n] - 1;
				headTail[letterRank][1]--; //update tail, decrement
			}
		}
	}

	cout << "third and final pass for suffix array is: " << endl;
	for (size_t k = 0; k < suffixArr.size(); k++)
	{
		cout << suffixArr[k] << " ";
	}
	cout << endl;

	//Deallocate the dynamic arrays
	delete [] typeSuffixes;
	delete [] lmsTypeArr;
	for (int rows = 0; rows < numBuckets; rows++)
	{
		delete [] headTail[rows];
	}

	delete [] headTail;

	return suffixArr;
}


//fill L and S types for string (helper function)
void findSuffixTypes(const vector<size_t>& text, char* &typeSuffixes)
{
	//Fill the suffix type array
	for (int i = text.size() - 2; i >= 0; i--)
	{
		//determining L and S types (use multiple ifs)
		if (text[i] > text[i + 1])
		{
			typeSuffixes[i] = 'L';
		}

		if (text[i] < text[i+1])
		{
			typeSuffixes[i] = 'S';
		}

		if (text[i] == text[i+1])
		{
			typeSuffixes[i] = typeSuffixes[i + 1];
		}
	}//end for loop
}


//helper to set the pointers (WORKS)
//asciiTable static array automatically passed by reference, argument is asciiTable[]
void setBucketPointers(const vector<size_t>& text, int** &headTailArr, const size_t asciiTable[])
{
	//head for first bucket should be index 1 no matter what
	//initialize head and tail pointers for buckets
	size_t slotCounter = 0;
	size_t countLetters;
	size_t trackLetterBucket = 1; //track the corresponding letter bucket for 2D array and ascii table (for reference to correct letter/rank and its count)
	for (size_t b = 1; b < text.size(); b++)
	{
		if (asciiTable[trackLetterBucket] != 0)
		{
			countLetters = 0;
			slotCounter = 0;
			headTailArr[trackLetterBucket][0] = b;
			//while condition to count appropriate number of slots and set the tail at the end
			countLetters = asciiTable[trackLetterBucket] - 1; //asciiTable[trackLetterBucket] - 1 should be in a variable so that it is not affected by while loop
			while (slotCounter < countLetters)
			{
				b++;
				slotCounter++;
			}

			headTailArr[trackLetterBucket][1] = b;
		}
		trackLetterBucket++;
	}
}


/*
BAD CODE (b ruins everything, it does not track the proper value/proper count of a letter from the asciiTable array
	//head for first bucket should be index 1 no matter what
	//initialize head and tail pointers for buckets
	size_t slotCounter = 0;
	size_t trackBucket = 0;
	size_t countLetters;
	for (size_t b = 1; b < text.size(); b++)
	{
		if (asciiTable[b] != 0)
		{
			countLetters = 0;
			slotCounter = 0;
			headTailArr[b][0] = b; //property of trying to reference the count of a specific letter bucket DOES NOT HOLD after 1st iteration. b needed to be 2 when it comes back around
			trackBucket = b; //preserve b before going to while loop, keep reference to letter bucket for 2D array

			//line below doesn't work after first iteration, does not reference the letter count for the correct letter from ascii table
			//(and caused infinite while loop when I tried to change my approach. it jumped to a different index in ascii table that may have had value of 0)
			countLetters = asciiTable[b] - 1; //asciiTable[b] - 1 should be in a variable so that b is not affected by while loop
			while (slotCounter < countLetters)
			{
				b++;
				slotCounter++;
			}

			headTailArr[trackBucket][1] = b;
		}
	}

*/

/*
Debugging for ACGTGCCTAGCCTACCGTGCC$
(below is the correct inital setup for the pointers)

headtail[1][0] (head of rank 1 letter) = 1
headtail[1][1] (tail of rank 1 letter) = 3
headtail[2][0] (head of rank 2 letter) = 4
headtail[2][1] (tail of rank 2 letter) = 12
headtail[3][0] (head of rank 3 letter) = 13
headtail[3][1] (tail of rank 3 letter) = 17
headtail[4][0] (head of rank 4 letter) = 18
headtail[4][1] (tail of rank 4 letter) = 21


	cout << "Before resetting pointers: " << endl;
	cout << "headtail[1][0] (head of rank 1 letter) = " << headTail[1][0] << endl;
	cout << "headtail[1][1] (tail of rank 1 letter) = " << headTail[1][1] << endl;
	cout << "headtail[2][0] (head of rank 2 letter) = " << headTail[2][0] << endl;
	cout << "headtail[2][1] (tail of rank 2 letter) = " << headTail[2][1] << endl;
	cout << "headtail[3][0] (head of rank 3 letter) = " << headTail[3][0] << endl;
	cout << "headtail[3][1] (tail of rank 3 letter) = " << headTail[3][1] << endl;
	cout << "headtail[4][0] (head of rank 4 letter) = " << headTail[4][0] << endl;
	cout << "headtail[4][1] (tail of rank 4 letter) = " << headTail[4][1] << endl;

	//reinitialize head and tail for each bucket
	setBucketPointers(text, headTail, asciiTable);

	cout << "AFTER RESETTING HEAD AND TAIL FOR BUCKETS: " << endl;
	cout << "headtail[1][0] (head of rank 1 letter) = " << headTail[1][0] << endl;
	cout << "headtail[1][1] (tail of rank 1 letter) = " << headTail[1][1] << endl;
	cout << "headtail[2][0] (head of rank 2 letter) = " << headTail[2][0] << endl;
	cout << "headtail[2][1] (tail of rank 2 letter) = " << headTail[2][1] << endl;
	cout << "headtail[3][0] (head of rank 3 letter) = " << headTail[3][0] << endl;
	cout << "headtail[3][1] (tail of rank 3 letter) = " << headTail[3][1] << endl;
	cout << "headtail[4][0] (head of rank 4 letter) = " << headTail[4][0] << endl;
	cout << "headtail[4][1] (tail of rank 4 letter) = " << headTail[4][1] << endl;

*/
