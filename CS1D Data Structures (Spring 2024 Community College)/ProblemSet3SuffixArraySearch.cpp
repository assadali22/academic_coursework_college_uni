#include "Search.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//void recursiveBinarySearch(const string& pattern, const string& text, const SuffixArray& suffixArr, size_t low, size_t high, vector<size_t> &m);

//Reference for function: https://github.com/imhelendang/Suffix-Array/blob/main/Search.cpp
int findNewLow(const string& pattern, const string& text, const SuffixArray& suffixArr, int m)
{
	int newLeft = m;
	while (newLeft > 1 && pattern[0] == text[suffixArr[newLeft - 1]])
	{
		newLeft--;
	}

	return newLeft;
}

//Reference for function: https://github.com/imhelendang/Suffix-Array/blob/main/Search.cpp
int findNewHigh(const string& pattern, const string& text, const SuffixArray& suffixArr, int m)
{
	int newRight = m;
	while (newRight < (int) text.length() && pattern[0] == text[suffixArr[newRight + 1]])
	{
		newRight++;
	}

	return newRight;
}

//Reference for searchFor function: https://github.com/imhelendang/Suffix-Array/blob/main/Search.cpp
//by Jade Tran and Nika Douri
vector<size_t> searchFor(const string& pattern,
                         const string& text,
                         const SuffixArray& suffixArr) {

	//suffixArr is a vector of indicies corresponding to each suffix
	/*
	for (size_t j = 0; j < suffixArr.size(); j++)
	{
		cout << text.substr(suffixArr.at(j)) << endl;
	}
	*/

	size_t low = 0;
	size_t high = suffixArr.size() - 1;
	size_t middle;
	vector<size_t> matches;

	if (pattern.length() == 0) //empty pattern
	{
		for (size_t z = 0; z <= text.length(); z++)
		{
			matches.push_back(z);
		}
	}
	else
	{
		if (pattern.length() == text.length())
		{
			//check if pattern and text are the same
			if (pattern == text)
			{
				matches.push_back(0);
			}
		}
		else
		{
			while (low <= high)
			{
				middle = (low + high) / 2;
				if (pattern[0] < text[suffixArr[middle]])
				{
					high = middle - 1;
				}
				else if (pattern[0] > text[suffixArr[middle]])
				{
					low = middle + 1;
				}
				else
				{
					//i assume these functions find the start and end points for the specific letter bucket
					//in sorted suffix array, skipping through the irrelevant elements where first character doesnt match
					low = findNewLow(pattern, text, suffixArr, middle);
					high = findNewHigh(pattern, text, suffixArr, middle);

					while (low <= high)
					{
						//start position suffixArr[low], number of characters to compare is pattern.length()
						//compare to substring of text
						if (strncmp(pattern.c_str(), text.c_str()+suffixArr[low], pattern.length()) == 0)
							matches.push_back(suffixArr[low]);

						low++;
					}
				}


			}//end while
		}


	}//end of main else



	//cout << "Entering recursive binary search for all possible (and partial) matches" << endl;
	//recursiveBinarySearch(pattern, text, suffixArr, low, high, matches);
	//cout << "returning matches now, initial call to recursive search is done" << endl;
	//when a match is found, continue search down the branch
	//cout << "my matches: ";
	//for (size_t p = 0; p < matches.size(); p++)
	//{ cout << matches.at(p) << endl;}

	return matches;
}



/*
//more failed code/attempts
//REFERENCE: https://stackoverflow.com/a/75107627
//By Saikat Acharjee Joy
void recursiveBinarySearch(const string& pattern, const string& text, const SuffixArray& suffixArr,
size_t low, size_t high, vector<size_t> &m)
{
	if (low > high)
	{
		return;
	}

	while (low <= high)
	{
		size_t middle;
		middle = (low + high) / 2;

		//check if pattern is anywhere in the suffixes
		//if (text.substr(suffixArr.at(middle)).find(pattern) != string::npos)
		if (pattern.compare(0, pattern.length(), text.substr(suffixArr[middle])) == 0)
		{
			//m.push_back(suffixArr.at(middle));
			//m.push_back(middle);
			m.push_back(suffixArr[middle]);
			recursiveBinarySearch(pattern, text, suffixArr, low, middle - 1, m); //search lower half
			recursiveBinarySearch(pattern, text, suffixArr, middle + 1, high, m); //search upper half
			return;
		}
		else if (pattern[0] < text[suffixArr[middle]])
		{
			high = middle - 1;
			recursiveBinarySearch(pattern, text, suffixArr, low, high, m); //this wasnt in the citation for some reason
		}
		else
		{
			low = middle + 1;
			recursiveBinarySearch(pattern, text, suffixArr, low, high, m); //also not in original citation
		}


	}//end while
	//cout << "end of while loop" << endl;

}
*/

/*
failed while loop
	//check if the suffix starts with the pattern
	//text.substr(suffixArr[middle]) gets the actual string to compare against

	while (low <= high)
	{
		middle = (low + high) / 2;

		//check if pattern is anywhere in the suffixes
		//if (pattern.compare(0, pattern.length(), text.substr(suffixArr[middle])) == 0)
		if (text.substr(suffixArr[middle]).find(pattern) != string::npos)
		{
			//matches.push_back(suffixArr.at(middle));
			//matches.push_back(middle);
			matches.push_back(suffixArr[middle]);
		}
		else if (pattern[0] < text[suffixArr[middle]])
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}

	}
*/

/*
	for (i = 0; i < suffixArr.size(); i++)
	{
		if (text.substr(suffixArr.at(i)).find(pattern) != string::npos)
		{
			matches.push_back(suffixArr.at(i));
		}
	}
*/

/*
for (i = 0; i < suffixArr.size(); i++)
	{
		if (pattern.compare(text.substr(suffixArr.at(i))) == 0)
		{
			matches.push_back(suffixArr.at(i)); //get the index for the matching suffix, store it in matches
		}
	}
*/
