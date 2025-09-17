/*
Chapter 8 Programming Exercises Problem 7

Write a program that allows the user to enter the last names of five
candidates in a local election and the number of votes received by each
candidate. The program should then output each candidate's name,
the number of votes received, and the percentage of the total votes
received by the candidate. Your program should also output the winner
of the election.

*/

#include <iostream>
#include <iomanip>
using namespace std;
const int NAME_SIZE = 25;
const int SIZE = 5;

int findTotalVotes(const int votes[], int S);
void electionResults(char lastNames[], const int votes[], int S, int winner, int totalVotes);

int main()
{
    char lastNames[SIZE][NAME_SIZE];
    int votes[SIZE];
    int totalVotes = 0;
    int highestVote = 0;
    int winnerIndex = 0;
    int i = 0;
    double votePercent = 0;

    for (i = 0; i < SIZE; i++)
    {
        cout << "Enter name and number of votes for candidate #" << i + 1 << ": ";
        cin >> lastNames[i] >> votes[i];
    }
    cout << endl;
    totalVotes = findTotalVotes(votes, SIZE);

    highestVote = votes[0];
    for (i = 1; i < SIZE; i++)
    {
        if (votes[i] > highestVote)
        {
            winnerIndex = i;
            highestVote = votes[i];
        }
    }

    cout << left;
    cout << fixed << showpoint << setprecision(2);
    cout << setw(20) << "Candidate" << setw(20) << "Votes Received" << setw(20) << "% of Total Votes" << endl;
    cout << endl;

    for (i = 0; i < SIZE; i++)
    {
        votePercent = 100 * (static_cast<double>(votes[i]) / static_cast<double>(totalVotes));
        cout << setw(20) << lastNames[i] << setw(20) << votes[i] << setw(20) << votePercent << endl;
    }
    cout << setw(20) << "Total" << setw(20) << totalVotes << endl;

    cout << endl;
    cout << "The Winner of the Election is " << lastNames[winnerIndex] << endl;


    return 0;


}


int findTotalVotes(const int votes[], int S)
{
    int sum = 0;
    int i = 0;

    for (i = 0; i < S; i++)
    {
        sum = sum + votes[i];
    }

    return sum;
}



/*
Sample Run 1
Enter name and number of votes for candidate #1: Johnson 5000
Enter name and number of votes for candidate #2: Miller 4000
Enter name and number of votes for candidate #3: Duffy 6000
Enter name and number of votes for candidate #4: Robinson 2500
Enter name and number of votes for candidate #5: Ashtony 1800

Candidate           Votes Received      % of Total Votes

Johnson             5000                25.91
Miller              4000                20.73
Duffy               6000                31.09
Robinson            2500                12.95
Ashtony             1800                9.33
Total               19300

The Winner of the Election is Duffy


Sample Run 2
Enter name and number of votes for candidate #1: Sam 600
Enter name and number of votes for candidate #2: Tom 450
Enter name and number of votes for candidate #3: Tim 160
Enter name and number of votes for candidate #4: Kim 950
Enter name and number of votes for candidate #5: Cam 200

Candidate           Votes Received      % of Total Votes

Sam                 600                 25.42
Tom                 450                 19.07
Tim                 160                 6.78
Kim                 950                 40.25
Cam                 200                 8.47
Total               2360

The Winner of the Election is Kim

Sample Run 3
Enter name and number of votes for candidate #1: Lucas 50
Enter name and number of votes for candidate #2: Jesse 75
Enter name and number of votes for candidate #3: Angel 45
Enter name and number of votes for candidate #4: Luis 40
Enter name and number of votes for candidate #5: John 35

Candidate           Votes Received      % of Total Votes

Lucas               50                  20.41
Jesse               75                  30.61
Angel               45                  18.37
Luis                40                  16.33
John                35                  14.29
Total               245

The Winner of the Election is Jesse
*/
