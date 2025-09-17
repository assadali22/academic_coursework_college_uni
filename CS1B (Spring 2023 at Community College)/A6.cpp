//-------------------------------------------------------------------
//Purpose: This program stores the data of 10 football players with -
//structs, with input data from a text file. The program allows the -
//user to search the array of players and update the data of a		  -
//specific player. The user can also store the data in an output    -
//fil if they wish to do so.											                  -
//-------------------------------------------------------------------
//Algorithm:                                                        -
//Step 1: Read the data from the input file and store it in an		  -
//array of structs.												                        	-
//Step 2: Display the menu choices and ask the user for a choice.	  -
//Step 3: If the user chooses to look up the player, the user       -
//inputs the name to be searched.									                  -
//Step 4: If the user chooses to edit a player, the user inputs		  -
//the name to be searched and if found, a new menu appears,         -
//which lets the user choose which data member to edit.				      -
//Step 5: If the user chooses to print the team roster, the team	  -
//roster will be printed in a table-like format, showing the data.	-
//Step 6: If the user chooses to quit, they can choose to save the  -
//data into a text file.												                    -
//Step 7: Quit														                          -
//-------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;
const int ELEMENTS = 10;

struct playerType
{
	string name;
	string position;
	int touchdowns = 0;
	int catches = 0;
	int passingYards = 0;
	int receivingYards = 0;
	int rushingYards = 0;
};

//Function Prototypes
void readFile(playerType players[], int s, ifstream& fin);
void writeFile(playerType players[], int s, ofstream& fout);
int lookUpPlayer(playerType players[], int s);
void editPlayer(playerType players[], int s);
void printTeam(playerType players[], int s);
void printPlayer(playerType players[], int i);

//Helper Function Prototypes
void showMenu();
void lowerName(string& name);
void showEditMenu(playerType players[], int s, int i);


int main()
{
	playerType players[ELEMENTS];
	char choice;
	char saveData; //user choice for saving data to text file
	int playerFound = 0;
	ifstream fin;
	ofstream fout;

	fin.open("footballData.txt");
	fout.open("footballOutput.txt");
	readFile(players, ELEMENTS, fin);

	showMenu();
	cout << "* Choice (1-4): ";
	cin >> choice;

	while (choice < '1' || choice > '4')
	{
		cout << "Invalid choice. Enter a choice between 1-4: ";
		cin >> choice;
	}

	//Depending on the user's choice, the user can look up a player,
	//edit a player, or print the team roster. User can enter 4 to quit.
	while (choice != '4')
	{
		switch (choice)
		{
			case '1':
			{
				playerFound = lookUpPlayer(players, ELEMENTS);

				if (playerFound == -1)
				{
					cout << "Player not found." << endl;
				}
				break;
			}

			case '2':
			{
				editPlayer(players, ELEMENTS);
				break;
			}

			case '3':
			{
				printTeam(players, ELEMENTS);
				break;
			}
		}

		cout << endl << endl << endl;
		showMenu();
		cout << "* Choice (1-4): ";
		cin >> choice;

		while (choice < '1' || choice > '4')
		{
			cout << "Invalid choice. Enter a choice between 1-4: ";
			cin >> choice;
		}


	}

	cout << "Save team data into a text file? (1 = Yes, 0 = No): ";
	cin >> saveData;

	while (saveData > '1' || saveData < '0')
	{
		cout << "Invalid choice. Enter 1 for Yes, or 0 for No: ";
		cin >> saveData;
	}

	if (saveData == '1')
	{
		writeFile(players, ELEMENTS, fout);
		cout << "Data appended to footballOutput.txt." << endl;
	}

	fin.close();
	fout.close();
	return 0;
}


void showMenu()
{
	cout << "********************************************" << endl;
	cout << "* Assignment: A6 Structs                   *" << endl;
	cout << "*                                          *" << endl;
	cout << "* <1> Look Up a Player                     *" << endl;
	cout << "* <2> Edit a Player                        *" << endl;
	cout << "* <3> Print Team Roster                    *" << endl;
	cout << "* <4> To Quit                              *" << endl;
	cout << "********************************************" << endl;
}


//Pass in the data of the football players and print the team roster
//with the use of a for loop.
void printTeam(playerType players[], int s)
{
	int i = 0;
	//Table Header
	cout << "\nTeam consist of the following players:" << endl;
	cout << left;
	cout << setw(25) << "Name" << setw(10) << "Pos" << setw(10) << "TDs" << setw(10) << "Catches";
	cout << setw(10) << "Pass" << setw(10) << "Recv" << setw(10) << "Rush" << endl;
	cout << right << setw(58) << "Yds";
	cout << setw(10) << "Yds" << setw(10) << "Yds" << endl;

	cout << left;
	//Data
	for (i = 0; i < s; i++)
	{
		printPlayer(players, i);
	}
	cout << endl << endl;
}



//Pass in player struct and use string methods to search for a player.
//A temporary variable is used to not mess with the original data member.
//Return the index of the target player.
int lookUpPlayer(playerType players[], int s)
{
	int i = 0;
	bool found = false;

	string searchPlayer;
	string tempName; //Temporary variable to store name
	cin.ignore(100, '\n'); //get rid of '\n' causing problems with input data
	cout << "Search: ";
	getline(cin, searchPlayer);

	lowerName(searchPlayer);
	while (i < s && !found)
	{
		tempName.append(players[i].name); //copy original name into tempName
		lowerName(tempName);
		if (tempName.find(searchPlayer) != string::npos) //use .find and != string::npos comparasion
		{
			found = true;
			cout << "Match found: " << players[i].name << endl;
		}
		else
		{
			i++;
			tempName.erase(); //clear the string so it can be used again for a new name
		}
	}

	if (found)
	{
		return i;
	}
	else
	{
		return -1;
	}
}


//This function calls lookUpPlayer and if the target player is found
//the user can edit player data with a menu system.
void editPlayer(playerType players[], int s)
{
	int i; //i represents index of target player
	char editChoice;
	i = lookUpPlayer(players, s);
	if (i == -1)
	{
		cout << "Not found." << endl;
		return;
	}
	else
	{
		do
		{
			cout << endl << endl;
			showEditMenu(players, s, i);
			cout << "Choice (1-8): ";
			cin >> editChoice;

			while (editChoice < '1' || editChoice > '8')
			{
				cout << "Invalid choice, please enter a choice between 1 and 8: ";
				cin >> editChoice;
			}

			switch (editChoice)
			{
				case '1':
				{
					cin.ignore(100, '\n'); //helps solve the issue causing "invalid choice" to pop up
					cout << "Enter the new name: ";
					getline(cin, players[i].name);
					break;
				}
				case '2':
				{
					cout << "Enter new position: ";
					cin >> players[i].position;
					break;
				}
				case '3':
				{
					cout << "Enter new number of touchdowns: ";
					cin >> players[i].touchdowns;
					break;
				}
				case '4':
				{
					cout << "Enter new number of catches: ";
					cin >> players[i].catches;
					break;
				}
				case '5':
				{
					cout << "Enter new number of passing yards: ";
					cin >> players[i].passingYards;
					break;
				}
				case '6':
				{
					cout << "Enter new number of receiving yards: ";
					cin >> players[i].receivingYards;
					break;
				}
				case '7':
				{
					cout << "Enter new number of rushing yards: ";
					cin >> players[i].rushingYards;
					break;
				}
				case '8':
				{
					cout << "Returning to Main Menu...";
					cout << endl << endl;
					break;
				}
			}

		}
		while (editChoice != '8');
	}
	return;
}


//Number of records in the file should match the number of elements
//in the array of struct. Otherwise, the result of the function may be undetermined.
//Read the data from the text file for the 10 players.
void readFile(playerType players[], int s, ifstream& fin)
{
	int i = 0;
	for (i = 0; i < s; i++)
	{
		getline(fin, players[i].name);
		getline(fin, players[i].position);
		fin >> players[i].touchdowns >> players[i].catches >> players[i].passingYards;
		fin >> players[i].receivingYards >> players[i].rushingYards;
		fin.ignore(25, '\n');
	}
}


//Pass in the array of struct and write the data to a text file
//with the use of a for loop, cycling through each player.
void writeFile(playerType players[], int s, ofstream& fout)
{
	int i = 0;
	for (i = 0; i < s; i++)
	{
		fout << "Name: " << players[i].name << endl;
		fout << "Position: " << players[i].position << endl;
		fout << "Touchdowns: " << players[i].touchdowns << endl;
		fout << "Catches: "<< players[i].catches << endl;
		fout << "Passing Yards: " << players[i].passingYards << endl;
		fout << "Receiving Yards: " << players[i].receivingYards << endl;
		fout << "Rushing Yards: " << players[i].rushingYards << endl;
		fout << endl << endl;
	}
}


//This function takes in a string by reference and makes it lowercase.
void lowerName(string& name)
{
	int length;
	int i;
	length = name.length();
	for (i = 0; i < length; i++)
	{
		name[i] = tolower(name[i]);
	}

}



void showEditMenu(playerType players[], int s, int i)
{
	cout << "**********************************************************" << endl;
	cout << "* Edit Player                                            *" << endl;
	cout << "*                                                        * CURRENT VALUES" << endl;
	cout << "* <1> Edit Name                                          : " << players[i].name << endl;
	cout << "* <2> Edit Position                                      : " << players[i].position << endl;
	cout << "* <3> Edit Number of Touch Downs                         : " << players[i].touchdowns << endl;
	cout << "* <4> Edit Number of Catches                             : " << players[i].catches << endl;
	cout << "* <5> Edit Number of Passing Yards                       : " << players[i].passingYards << endl;
	cout << "* <6> Edit Number of Receiving Yards                     : " << players[i].receivingYards << endl;
	cout << "* <7> Edit Number of Rushing Yards                       : " << players[i].rushingYards << endl;
	cout << "* <8> Return to Main Menu                                *" << endl;
	cout << "**********************************************************" << endl;
}


//Take in the array of struct and print an individual player.
//The for loop in printTeam prints each record, cycling through each index.
void printPlayer(playerType players[], int i)
{
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << setw(25) << players[i].name << setw(10) << players[i].position;
	cout << setw(10) << players[i].touchdowns << setw(10) << players[i].catches;
	cout << setw(10) << players[i].passingYards << setw(10) << players[i].receivingYards;
	cout << setw(10) << players[i].rushingYards << endl;

}
