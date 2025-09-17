//-------------------------------------------------------------------
//Algorithm:														-
//Step 1: Get the name and number of votes for each candidate		-
//and store them in an array. One array for number of votes, and    -
//one array for the name.											-
//Step 2: Find the total number of votes.							-
//Step 3: Use the selection sort algorithim to sort the array of	-
//the number of votes from greatest to least with respect to each	-
//candidate.														-
//Step 4: Display the sorted data in a table-like format, with the	-
//vote percentage calculated by taking the number of votes for a	-
//candidate and dividing it by the total number of votes.			-
//Step 5: Display the winner of the election, with the name being	-
//capitalized.														-
//Step 6: Quit														-
//-------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;

const int NAME_SIZE = 20;
const int ARR_SIZE = 5;

//Function Prototypes
void getNameAndVotes(char lastName[][NAME_SIZE], int votes[], int size, int nameSize);
int getTotalVotes(const int votes[], int S);
void sortArrays(char lastName[][NAME_SIZE], int votes[], int size, int nameSize);

int main()
{
	char lastName[ARR_SIZE][NAME_SIZE];
	int votes[ARR_SIZE];
	int totalVotes = 0;
	int i = 0;
	int length = 0;
	double votePercent = 0;

	getNameAndVotes(lastName, votes, ARR_SIZE, NAME_SIZE);
	totalVotes = getTotalVotes(votes, ARR_SIZE);
	sortArrays(lastName, votes, ARR_SIZE, NAME_SIZE);


	cout << left;
	cout << fixed << showpoint << setprecision(2);
	cout << setw(20) << "Candidate" << setw(20) << "Votes Received" << setw(20) << "% of Total Votes" << endl;
	cout << setw(20) << "---------" << setw(20) << "--------------" << setw(20) << "----------------" << endl;


	for (i = 0; i < ARR_SIZE; i++)
	{
		cout << left;
		votePercent = 100 * (static_cast<double>(votes[i]) / static_cast<double>(totalVotes));
		cout << setw(20) << lastName[i];
		cout << right << setw(14) << votes[i] << setw(22) << votePercent << endl;
	}


	cout << left;
	cout << "--------------------------------------------------------" << endl;
	cout << setw(20) << "Total";
	cout << right << setw(14) << totalVotes << endl;


	cout << left;
	length = strlen(lastName[0]);
	for (i = 0; i < length; i++)
	{
		lastName[0][i] = toupper(lastName[0][i]);
	}
	cout << "The Winner of the Election is " << lastName[0] << endl;
	return 0;
}



//Pass in the array of votes and names, along with the size of each array.
//The user inputs the data for each candidate.
void getNameAndVotes(char lastName[][NAME_SIZE], int votes[], int size, int nameSize)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		cout << "Enter last name and number of votes for candidate #" << i + 1 << ": ";
		cin >> lastName[i] >> votes[i];
	}
	cout << endl;
}


//Pass in the array of votes and the size of the array
//and find the total number of the votes.
int getTotalVotes(const int votes[], int S)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < S; i++)
	{
		sum = sum + votes[i];
	}


	return sum;
}


//The function takes the array of names and votes, along with
//the size of each array. Sort the array of votes from greatest to least
//with respect to each candidate.
void sortArrays(char lastName[][NAME_SIZE], int votes[], int size, int nameSize)
{
	int index = 0;
	int smallestIndex = 0;
	int location = 0;
	int temp1 = 0;
	char temp2[nameSize];

	for (index = 0; index < size - 1; index++)
	{
		smallestIndex = index;

		for (location = index + 1; location < size; location++)
		{
			if (votes[location] > votes[smallestIndex])
			{
				smallestIndex = location;
			}
		}

		temp1 = votes[smallestIndex];
		votes[smallestIndex] = votes[index];
		votes[index] = temp1;

		strcpy(temp2, lastName[smallestIndex]);
		strcpy(lastName[smallestIndex], lastName[index]);
		strcpy(lastName[index], temp2);
	}
}
